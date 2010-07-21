/*****************************************************************************
 *                               detequs.h
 *
 * Function template for solving deterministic  linear equations.
 *
 * For a n-by-n Coefficient Matrix A and n-by-1 Constant Vector b, Gauss
 * elimination method can solve the equations Ax=b. But the decomposition
 * methods are more commonly used. if A is nonsymmetric, the LU decomposition
 * can be use to solve the equations; if A is symmetric, the Cholesky
 * decomposition is the better choice; if A is a tridiagonal matrix, then
 * the Forward Elimination and Backward Substitution maybe the best choice.
 *
 * Zhang Ming, 2010-07, Xi'an Jiaotong Univerty.
 *****************************************************************************/


#ifndef DETLINEQUS_H
#define DETLINEQUS_H


#include <vector.h>
#include <matrix.h>
#include <cholesky.h>
#include <lud.h>


namespace itlab
{

    /**
     * Linear equations solution by Gauss-Jordan elimination, AX=B.
     * A  --->  The n-by-n coefficient matrix(Full Rank);
     * B  --->  The n-by-m right-hand side vectors;
     * When solving is completion, A is replaced by its inverse and
     * B is replaced by the corresponding set of solution vectors.
     * Adapted from Numerical Recipes.
     */
    template <typename Real>
	void gaussSolver( Matrix<Real> &A, Matrix<Real> &B )
	{
	    assert( A.rows() == B.rows() );

        int i, j, k, l, ll, icol, irow,
            n=A.rows(),
            m=B.cols();
        Real big, dum, pivinv;

        Vector<int> indxc(n), indxr(n), ipiv(n);
        for( j=0; j<n; j++ )
            ipiv[j]=0;

        for( i=0; i<n; ++i )
        {
            big = 0.0;
            for( j=0; j<n; ++j )
                if( ipiv[j] != 1 )
                    for( k=0; k<n; ++k )
                        if( ipiv[k] == 0 )
                            if( abs(A[j][k]) >= big )
                            {
                                big = abs(A[j][k]);
                                irow = j;
                                icol = k;
                            }

            ++(ipiv[icol]);

            if( irow != icol )
            {
                for( l=0; l<n; ++l )
                    swap( A[irow][l], A[icol][l] );
                for( l=0; l<m; ++l )
                    swap( B[irow][l], B[icol][l] );
            }
            indxr[i] = irow;
            indxc[i] = icol;

            if( A[icol][icol] == 0.0 )
            {
                cerr << "Singular Matrix!" << endl;
                return;
            }

            pivinv = 1.0 / A[icol][icol];
            A[icol][icol] = 1.0;
            for( l=0; l<n; ++l )
                A[icol][l] *= pivinv;
            for( l=0; l<m; ++l )
                B[icol][l] *= pivinv;
            for( ll=0; ll<n; ++ll )
                if( ll != icol )
                {
                    dum = A[ll][icol];
                    A[ll][icol] = 0.0;
                    for( l=0; l<n; ++l )
                        A[ll][l] -= A[icol][l]*dum;
                    for( l=0; l<m; ++l )
                        B[ll][l] -= B[icol][l]*dum;
                }
        }

        for( l=n-1; l>=0; --l )
            if( indxr[l] != indxc[l] )
                for( k=0; k<n; k++ )
                    swap( A[k][indxr[l]], A[k][indxc[l]] );
	}


    /**
     * Linear equations solution by Gauss-Jordan elimination, Ax=B.
     * A  --->  The n-by-n coefficient matrix(Full Rank);
     * b  --->  The n-by-1 right-hand side vector;
     * x  --->  The n-by-1 solution vector.
     */
    template <typename Real>
    Vector<Real> gaussSolver( const Matrix<Real> &A, const Vector<Real> &b )
    {
        assert( A.rows() == b.size() );

        int rows = b.size();
        Vector<Real> x( rows );
        Matrix<Real> C(A);
        Matrix<Real> B( rows, 1 );
        for( int i=0; i<rows; ++i )
            B[i][0] = b[i];

        gaussSolver( C, B );

        for( int i=0; i<rows; ++i )
            x[i] = B[i][0];

        return x;
    }


    /**
     * Linear equations solution by LU decomposition, AX=B.
     * A  --->  The n-by-n coefficient matrix(Full Rank);
     * B  --->  The n-by-m right-hand side vector;
     * X  --->  The n-by-m solution vectors.
     */
    template <typename Real>
	Matrix<Real> luSolver( const Matrix<Real> &A, const Matrix<Real> &B )
	{
	    assert( A.rows() == B.rows() );

        LUD<Real> lu;
        lu.dec( A );
        return lu.solve( B );
	}


    /**
     * Linear equations solution by LU decomposition, Ax=b.
     * A  --->  The n-by-n coefficient matrix(Full Rank);
     * b  --->  The n-by-1 right-hand side vector;
     * x  --->  The n-by-1 solution vector.
     */
	template <typename Real>
	Vector<Real> luSolver( const Matrix<Real> &A, const Vector<Real> &b )
	{
	    assert( A.rows() == b.size() );

        LUD<Real> lu;
        lu.dec( A );
        return lu.solve( b );
	}


    /**
     * Linear equations solution by Cholesky decomposition, AX=B.
     * A  --->  The n-by-n coefficient matrix(Full Rank);
     * B  --->  The n-by-m right-hand side vector;
     * X  --->  The n-by-m solution vectors.
     */
	template <typename Real>
	Matrix<Real> choleskySolver( const Matrix<Real> &A, const Matrix<Real> &B )
	{
	    assert( A.rows() == B.rows() );

        Cholesky<double> cho;
        cho.dec(A);
        if( cho.isSpd() )
            return cho.solve( B );
        else
        {
            cerr << "Factorization was not complete!" << endl;
            return Matrix<Real>(0,0);
        }
	}


    /**
     * Linear equations solution by Cholesky decomposition, Ax=b.
     * A  --->  The n-by-n coefficient matrix(Full Rank);
     * b  --->  The n-by-1 right-hand side vector;
     * x  --->  The n-by-1 solution vector.
     */
	template <typename Real>
	Vector<Real> choleskySolver( const Matrix<Real> &A, const Vector<Real> &b )
	{
	    assert( A.rows() == b.size() );

        Cholesky<double> cho;
        cho.dec(A);
        if( cho.isSpd() )
            return cho.solve( b );
        else
        {
            cerr << "Factorization was not complete!" << endl;
            return Vector<Real>(0);
        }
	}

    /**
     * Tridiagonal equations solution by Forward Elimination and Backward Substitution.
     * a  --->  The n-1-by-1 main(0th) diagonal vector;
     * b  --->  The n-by-1   -1th(above main) diagonal vector;
     * c  --->  The n-1-by-1 +1th(below main) diagonal vector;
     * d  --->  The right-hand side vector;
     * x  --->  The n-by-1 solution vector.
     */
	template <typename Real>
	Vector<Real> febsSolver( const Vector<Real> &a, const Vector<Real> &b,
                             const Vector<Real> &c, const Vector<Real> &d )
	{
	    int n = b.size();

	    assert( a.size() == n-1 );
	    assert( c.size() == n-1 );
	    assert( d.size() == n );

	    Real mu = 0;
        Vector<Real> x(d),
                     bb(b);

        for( int i=0; i<n-1; ++i )
        {
            mu = a[i] / bb[i];
            bb[i+1] = bb[i+1] - mu*c[i];
            x[i+1] = x[i+1] - mu*x[i];
        }

        x[n-1] = x[n-1] / bb[n-1];
        for( int i=n-2; i>=0; --i )
            x[i] = ( x[i]-c[i]*x[i+1] ) / bb[i];

//        for( int j=1; j<n; ++j )
//        {
//            mu = a(j) / bb(j);
//            bb(j+1) = bb(j+1) - mu*c(j);
//            x(j+1) = x(j+1) - mu*x(j);
//        }
//
//        x(n) = x(n) / bb(n);
//        for( int j=n-1; j>0; --j )
//            x(j) = ( x(j)-c(j)*x(j+1) ) / bb(j);

        return x;
	}

}
// namespace itlab


#endif
// DETLINEQUS_H
