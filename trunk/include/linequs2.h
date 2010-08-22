/*****************************************************************************
 *                                linequs2.h
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
#include <linequs1.h>


namespace itlab
{


	template<typename Real>	Vector<Real> lsSolver( const Matrix<Real>&, const Vector<Real>& );
	template<typename Real>	Vector<Real> qrlsSolver( const Matrix<Real>&, const Vector<Real>& );

	template<typename Real>	Vector<Real> lnSolver( const Matrix<Real>&, const Vector<Real>& );
	template<typename Real>	Vector<Real> qrlnSolver( const Matrix<Real>&, const Vector<Real>& );


	#include <linequs2-impl.h>

}
// namespace itlab


#endif
// UNDETLINEQUS_H
