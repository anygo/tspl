/*****************************************************************************
 *                               cholesky.h
 *
 * Class template of Cholesky decomposition.
 *
 * For a symmetric, positive definite matrix A, this function computes the
 * Cholesky factorization, i.e. it computes a lower triangular matrix L such
 * that A = L*L'. If the matrix is not symmetric or positive definite, the
 * function computes only a partial decomposition. This can be tested with
 * the isSpd() flag.
 *
 * Adapted form Template Numerical Toolkit.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef CHOLESKY_H
#define CHOLESKY_H


#include <matrix.h>


namespace itlab
{

    template <typename Real>
    class Cholesky
    {

    public:

        Cholesky();
        ~Cholesky();

        bool isSpd() const;
        void dec( const Matrix<Real> &A );
        Matrix<Real> getL() const;

        Vector<Real> solve( const Vector<Real> &b );
        Matrix<Real> solve( const Matrix<Real> &B );

    private:

        bool spd;
        Matrix<Real> L;

    };
    //	class Cholesky


    #include <cholesky-impl.h>

}
// namespace itlab


#endif
// CHOLESKY_H
