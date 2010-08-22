/*****************************************************************************
 *                               linequs1.h
 *
 * Function template for solving deterministic linear equations.
 *
 * For a n-by-n Coefficient Matrix A and n-by-1 Constant Vector b, Gauss
 * elimination method can solve the equations Ax=b. But the decomposition
 * methods are more commonly used. if A is nonsymmetric, the LU decomposition
 * can be use to solve the equations; if A is symmetric, the Cholesky
 * decomposition is the better choice; if A is a tridiagonal matrix, then
 * the Forward Elimination and Backward Substitution maybe the best choice.
 *
 * Zhang Ming, 2010-07, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef DETLINEQUS_H
#define DETLINEQUS_H


#include <vector.h>
#include <matrix.h>
#include <cholesky.h>
#include <lud.h>


namespace itlab
{

    template<typename Real>	void gaussSolver( Matrix<Real>&, Matrix<Real>& );
    template<typename Real> Vector<Real> gaussSolver( const Matrix<Real>&, const Vector<Real>& );

    template<typename Real>	Matrix<Real> luSolver( const Matrix<Real>&, const Matrix<Real>& );
	template<typename Real>	Vector<Real> luSolver( const Matrix<Real>&, const Vector<Real>& );

	template<typename Real>	Matrix<Real> choleskySolver( const Matrix<Real>&, const Matrix<Real>& );
	template<typename Real> Vector<Real> choleskySolver( const Matrix<Real>&, const Vector<Real>& );

	template<typename Real>	Vector<Real> febsSolver( const Vector<Real>&, const Vector<Real>&,
                                                     const Vector<Real>&, const Vector<Real>& );


	#include <linequs1-impl.h>

}
// namespace itlab


#endif
// DETLINEQUS_H
