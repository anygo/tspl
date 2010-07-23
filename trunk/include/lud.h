/*****************************************************************************
 *                                    lud.h
 *
 * Class template of triangular decomposition.
 *
 * For an m-by-n matrix A with m >= n, the LU decomposition is an m-by-n
 * unit lower triangular matrix L, an n-by-n upper triangular matrix U, and
 * a permutation vector piv of length m so that A(piv,:) = L*U. If m < n,
 * then L is m-by-m and U is m-by-n.
 *
 * The LU decompostion with pivoting always exists, even if the matrix is
 * singular, so the constructor will never fail. The primary use of the LU
 * decomposition is in the solution of square systems of simultaneouslinear
 * equations. This will fail if isNonsingular() returns false.
 *
 * Adapted form Template Numerical Toolkit.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef LUD_H
#define LUD_H


#include <matrix.h>


namespace itlab
{

	template <typename Real>
	class LUD
	{

	public :

        LUD();
		~LUD();

		void dec( const Matrix<Real> &A );
		void getL( Matrix<Real> &L );
		void getU( Matrix<Real> &U );

		Real det();
		bool isNonsingular();

		Vector<Real> solve( const Vector<Real> &b );
		Matrix<Real> solve( const Matrix<Real> &B );

    private:

        // Array for internal storage of decomposition.
		Matrix<Real> LU;
		int m;
		int n;

		int pivsign;
		Vector<int> piv;
		Vector<int> getPivot() const;

		Vector<Real> permuteCopy( const Vector<Real> &A,
                                  const Vector<int> &piv );
		Matrix<Real> permuteCopy( const Matrix<Real> &A,
		                          const Vector<int> &piv, int j0, int j1 );

	};
	// class LUD


	#include <lud-impl.h>

}
// namespace itlab


#endif
// LUD_H
