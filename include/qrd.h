/*****************************************************************************
 *                                    qrd.h
 *
 * Class template of orthogonal decomposition.
 *
 * For an m-by-n matrix A with m >= n, the QR decomposition is an m-by-m
 * orthogonal matrix Q and an m-by-n upper triangular matrix R so that
 * A = Q*R.
 *
 * The QR decompostion always exists, even if the matrix does not have full
 * rank, so the constructor will never fail. The Q and R factors can be
 * retrived via the getQ() and getR() methods.
 *
 * The primary use of the QR decomposition is in the least squares solution
 * of nonsquare systems of simultaneous linear equations. This will fail if
 * isFullRank() returns 0. Furthermore, a solve() method is provided to find
 * the least squares solution of Ax=b using the QR factors.
 *
 * Adapted form Template Numerical Toolkit.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef QRD_H
#define QRD_H


#include <matrix.h>


namespace itlab
{

	template <typename Real>
	class QRD
	{

	public:

		QRD();
		~QRD();

		void dec( const Matrix<Real> &A );
		bool isFullRank() const;
		void getH( Matrix<Real> &H );
		void getQ( Matrix<Real> &Q );
		void getR( Matrix<Real> &R );

		Vector<Real> solve( const Vector<Real> &b );
		Matrix<Real> solve( const Matrix<Real> &B );

    private:

		int m;
		int n;

		// Array for internal storage of QR and diagonal of R.
		Matrix<Real> QR;
		Vector<Real> RDiag;

	};
	// class QRD


    #include <qrd-impl.h>

}
// namespace itlab


#endif
// QRD_H
