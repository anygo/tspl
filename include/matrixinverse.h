/*****************************************************************************
 *                                matrixinverse.h
 *
 * Matrix Inverse
 *
 * Matrix's inverse is a very important algorithm. If 'A' is an n-by-n full
 * rank square matrix, then it's inverse 'invA' is also an n-by-n full rank
 * square matrix. The general method to compute such matrix's inverse is
 * use LU decomposition to solve A*invA=I, if 'A' is symmetric, then Cholesky
 * decomposition will be more efficiency.
 *
 * If 'A' is an m-by-n (where m != n) matrix, or n-by-n but nor full rank,
 * then we can't compute the ordinary inverse. In these cases, we should
 * compute the pseudoinverse. And here we use SVD to compute the pseudoinverse,
 * which is consistent with Matlab's "pinv".
 *
 * Zhang Ming, 2010-08, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef MATRIXINVERSE_H
#define MATRIXINVERSE_H


#include <matrix.h>
#include <cholesky.h>
#include <lud.h>
#include <svd.h>


namespace itlab
{

    /**
     * Cpmpute the inverse of square matrix.
     */
	template <typename Real>
	Matrix<Real> inv( const Matrix<Real> &A, const string &type="nonsym" )
	{
	    int n = A.rows();
	    assert( n == A.cols() );

	    Matrix<Real> E = eye( n, Real(1) );

        if( type == "sym" )
        {
            Cholesky<Real> cho;
            cho.dec(A);
            if( cho.isSpd() )
                return cho.solve(E);
            else
            {
                cerr << "The matrix is not symmetric!" << endl;
                return A;
            }

        }
        else
        {
            LUD<Real> lu;
            lu.dec(A);
            return lu.solve(E);
        }
	}


	/**
     * Compute the pseudoinverse of matrix.
     */
	template <typename Real>
	Matrix<Real> pinv( const Matrix<Real> &A, Real tol=-1 )
	{
	    int m = A.rows(),
            n = A.cols();

        SVD<Real> svd;
        svd.dec( A );
        Matrix<Real> U = svd.getU();
        Matrix<Real> V = svd.getV();
        Vector<Real> s = svd.getSV();

        int r = 0;
        if( tol <= 0 )
            tol = max( m, n ) * s[0] * EPS;
        for( int i=0; i<s.size(); ++i )
            if( s[i] >= tol )
                r++;

        for( int i=0; i<n; ++i )
            for( int k=0; k<r; ++k )
                    V[i][k] /= s[k];

        Matrix<Real> invA( n, m );
        for( int i=0; i<n; ++i )
            for( int j=0; j<m; ++j )
            {
                Real sum = 0;
                for( int k=0; k<r; ++k )
                    sum += V[i][k]*U[j][k];
                invA[i][j] = sum;
            }

        return invA;
	}

}
// namespace itlab


#endif
// MATRIXINVERSE_H
