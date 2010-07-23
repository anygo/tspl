/*****************************************************************************
 *                                undetlinequs.h
 *
 * Function template for solving linear equations.
 *
 * For a m-by-n (m!=n) Coefficient Matrix A and m-by-1 Constant Vector b, if
 * m>n, the exact solution of Ax=b is not existent, but we can find the least
 * square solution that minimize norm of Ax-b; if m<n, there are infinite
 * many solutions, but we can find the minimum norm sulution that minimize
 * norm of x.
 *
 * Zhang Ming, 2010-07, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef UNDETLINEQUS_H
#define UNDETLINEQUS_H


#include <qrd.h>
#include <detlinequs.h>


namespace itlab
{

    /**
     * Overdetermined linear equationequations solution by Least Squares Generalized Inverse.
     * A  --->  The m-by-n(m>n) coefficient matrix(Full Column Rank);
     * b  --->  The n-by-1 right-hand side vector;
     * x  --->  The n-by-1 least squares solution vector.
     */
	template <typename Real>
	Vector<Real> lsSolver( const Matrix<Real> &A, const Vector<Real> &b )
	{
	    assert( A.rows() == b.size() );

//        Matrix<Real> C = tranProd( A, A );
//        Vector<Real> y = tranProd( A, b );
//        return choleskySolver( C, y );
        return choleskySolver( tranProd( A, A ), tranProd( A, b ) );
	}


	/**
     * Overdetermined linear equationequations solution by QR Decomposition.
     * A  --->  The m-by-n(m>n) coefficient matrix(Full Column Rank);
     * b  --->  The n-by-1 right-hand side vector;
     * x  --->  The n-by-1 least squares solution vector.
     */
	template <typename Real>
	Vector<Real> qrlsSolver( const Matrix<Real> &A, const Vector<Real> &b )
	{
	    assert( A.rows() == b.size() );

	    QRD<Real> qr;
        qr.dec( A );
        if( !qr.isFullRank() )
        {
            cerr << "The matrix A is not Full Rank!" << endl;
            return Vector<Real>();
        }
        else
            return qr.solve( b );
	}


    /**
     * Undetermined linear equationequations solution by Minimum Norm Generalized Inverse.
     * A  --->  The m-by-n(m<n) coefficient matrix(Full Row Rank);
     * b  --->  The n-by-1 right-hand side vector;
     * x  --->  The n-by-1 minimum norm solution vector.
     */
	template <typename Real>
	Vector<Real> lnSolver( const Matrix<Real> &A, const Vector<Real> &b )
	{
	    assert( A.rows() == b.size() );

	    Matrix<Real> At( transpose( A ) );
//        Matrix<Real> C = tranProd( At, At );
//        Vector<Real> y = choleskySolver( C, b );
//        return prod( At, y );
        return prod( At, choleskySolver( tranProd( At, At ), b ) );
	}


	/**
     * Undetermined linear equationequations solution by QR Decomposition.
     * A  --->  The m-by-n(m<n) coefficient matrix(Full Row Rank);
     * b  --->  The n-by-1 right-hand side vector;
     * x  --->  The n-by-1 minimum norm solution vector.
     */
	template <typename Real>
	Vector<Real> qrlnSolver( const Matrix<Real> &A, const Vector<Real> &b )
	{
	    assert( A.rows() == b.size() );

        Matrix<Real> At( transpose( A ) );
	    QRD<Real> qr;
        qr.dec( At );
        if( !qr.isFullRank() )
        {
            cerr << "The matrix A is not Full Rank!" << endl;
            return Vector<Real>();
        }
        else
        {
            Matrix<Real> Q, R;
            qr.getQ( Q );
            qr.getR( R );
            Vector<Real> y( luSolver( transpose( R ), b ) );
            return prod( Q, y );
        }
	}

}
// namespace itlab


#endif
// UNDETLINEQUS_H
