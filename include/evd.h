/*****************************************************************************
 *                                    evd.h
 *
 * Class template of eigenvalues and eigenvectors decomposition.
 *
 * If A is symmetric, then A=V*D*V', where the eigenvalue matrix D is
 * diagonal and the eigenvector matrix V is orthogonal. That is, the
 * diagonal values of D are the eigenvalues and the columns of V represent
 * the eigenvectors in the sense that A*V=V*D.
 *
 * If A is not symmetric, then the eigenvalue matrix D is block diagonal
 * with the real eigenvalues in 1-by-1 blocks and any complex eigenvalues,
 * a+i*b, in 2-by-2 blocks [a,b; -b,a]. That is, if the complex eigenvalues
 * look like
 *
 *    u + iv     .        .          .      .    .
 *      .      u - iv     .          .      .    .
 *      .        .      a + ib       .      .    .
 *      .        .        .        a - ib   .    .
 *      .        .        .          .      x    .
 *      .        .        .          .      .    y
 *
 * then D looks like
 *
 *      u        v        .          .      .    .
 *     -v        u        .          .      .    .
 *      .        .        a          b      .    .
 *      .        .       -b          a      .    .
 *      .        .        .          .      x    .
 *      .        .        .          .      .    y
 *
 * This keeps V a real matrix in both symmetric and non-symmetric cases, and
 * A*V = V*D.
 *
 * The matrix V may be badly conditioned, or even singular, so the validity
 * of the equation A=V*D*inverse(V) depends upon the condition number of V.
 *
 * Adapted form Template Numerical Toolkit.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


#ifndef EVD_H
#define EVD_H


#include <matrix.h>


namespace itlab
{

	template <typename Real>
	class EVD
	{

    public:

        EVD();
		~EVD();

		void dec( const Matrix<Real> &A );
		Matrix<Real> getV() const;
		Matrix<Real> getD() const;
		Vector<Real> getRealEigenvalues() const;
		Vector<Real> getImagEigenvalues() const;

    private:

		int     n;
		bool    isSymmetric;
        Real    cdivr,
                cdivi;

		// eigenvalues and its real and image part
		Matrix<Real> V;
		Vector<Real> d;
		Vector<Real> e;

		// temporary storage for internal variables
		Vector<Real> ort;
		Matrix<Real> H;

		void tred2();
		void tql2();
		void cdiv( Real xr, Real xi, Real yr, Real yi );
		void hqr2();
		void others();

	};
	// class EVD


    #include <evd-impl.h>

}
// namespace itlab


#endif
// EVD_H
