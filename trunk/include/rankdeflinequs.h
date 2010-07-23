/*****************************************************************************
 *                                randdeflinequs.h
 *
 * Function template for solving Rank Defect linear equations.
 *
 * For a m-by-n Coefficient Matrix A and m-by-1 Constant Vector b, if A is a
 * Rank Deficient Matrix, then the conventional methods for solving linear
 * this equations can not be used. There methods for solving such problem
 * are provided in this file: Truncated SVD, Dampted SVD and Tikhonov
 * Regularization.
 *
 * Zhang Ming, 2010-07, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef RANKDEFLINEQUS_H
#define RANKDEFLINEQUS_H


#include <vector.h>
#include <matrix.h>
#include <svd.h>


namespace itlab
{

    /**
     * Rank defect linear equationequations solution by Truncated SVD.
     * A  --->  The m-by-n coefficient matrix(Rank Defect);
     * b  --->  The n-by-1 right-hand side vector;
     * x  --->  The n-by-1 solution vector.
     */
	template <typename Real>
	Vector<Real> tsvd( const Matrix<Real> &A, const Vector<Real> &b, Real tol=-1 )
	{
	    int m = A.rows(),
            n = A.cols();

	    assert( m == b.size() );

        SVD<Real> svd;
        svd.dec( A );
        Matrix<Real> U = svd.getU();
        Matrix<Real> V = svd.getV();
        Vector<Real> s = svd.getSV();
        Vector<Real> x(n);

        int r = 0;
        if( tol <= 0 )
            tol = max( m, n ) * s[0] * EPS;
        for( int i=0; i<s.size(); ++i )
            if( s[i] >= tol )
                r++;

        for( int i=0; i<n; ++i )
            for( int j=0; j<r; ++j )
            {
                Real sum = 0;
                for( int k=0; k<m; ++k )
                    sum += U[k][j]*b[k];
                x[i] += sum * V[i][j] / s[j];
            }

        return x;
	}


	/**
     * Rank defect linear equationequations solution by Dampted SVD.
     * A  --->  The m-by-n(m>n) coefficient matrix(Rank Defect);
     * b  --->  The n-by-1 right-hand side vector;
     * sigma :  dampted factor;
     * x  --->  The n-by-1 solution vector.
     */
	template <typename Real>
	Vector<Real> dsvd( const Matrix<Real> &A, const Vector<Real> &b, Real sigma )
	{
	    int m = A.rows(),
            n = A.cols();

	    assert( m == b.size() );

        SVD<Real> svd;
        svd.dec( A );
        Matrix<Real> U = svd.getU();
        Matrix<Real> V = svd.getV();
        Vector<Real> s = svd.getSV();
        Vector<Real> x(n);

        int p = s.size();
        for( int i=0; i<n; ++i )
            for( int j=0; j<p; ++j )
            {
                Real sum = 0;
                for( int k=0; k<m; ++k )
                    sum += U[k][j]*b[k];
                x[i] += sum * V[i][j] / ( s[j] + sigma );
            }

        return x;
	}


	/**
     * Rank defect linear equationequations solution by Tikhonov Regularization.
     * A  --->  The m-by-n(m>n) coefficient matrix(Rank Defect);
     * b  --->  The n-by-1 right-hand side vector;
     * alpha :  regularization factor;
     * x  --->  The n-by-1 solution vector.
     */
	template <typename Real>
	Vector<Real> tikhonov( const Matrix<Real> &A, const Vector<Real> &b, Real alpha )
	{
	    int m = A.rows(),
            n = A.cols();

	    assert( m == b.size() );

        SVD<Real> svd;
        svd.dec( A );
        Matrix<Real> U = svd.getU();
        Matrix<Real> V = svd.getV();
        Vector<Real> s = svd.getSV();
        Vector<Real> x(n);

        int p = s.size();
        for( int i=0; i<n; ++i )
            for( int j=0; j<p; ++j )
            {
                Real sum = 0;
                for( int k=0; k<m; ++k )
                    sum += U[k][j]*b[k];
                x[i] += s[j] * sum * V[i][j] / ( s[j]*s[j] + alpha*alpha ) ;
            }

        return x;
	}

}
// namespace itlab


#endif
// RANKDEFLINEQUS_H
