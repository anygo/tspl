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

	template<typename Real>	Vector<Real> tsvd( const Matrix<Real>&, const Vector<Real>&, Real tol=-1.0 );
	template<typename Real>	Vector<Real> dsvd( const Matrix<Real>&, const Vector<Real>&, Real& );
	template<typename Real>	Vector<Real> tikhonov( const Matrix<Real>&, const Vector<Real>&, Real& );


	#include <linequs3-impl.h>

}
// namespace itlab


#endif
// RANKDEFLINEQUS_H
