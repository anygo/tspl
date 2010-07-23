/*****************************************************************************
 *                                spline3interp.h
 *
 * Cubic splines interpolation method.
 *
 * For a given points set "Pn" {xn,yn}, this class can find a cubic polynomial
 * in each interval [x_i, x_i+1], such that both of the polynomials and their
 * first order derivative are continuous at the bound of each interval.
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef SPLINE3INTERP_H
#define SPLINE3INTERP_H


#include <matrix.h>
#include <interpolation.h>


namespace itlab
{

    template <typename Type>
    class Spline3Interp : public Interpolation<Type>
    {

     public:

        using Interpolation<Type>::xi;
        using Interpolation<Type>::yi;

        Spline3Interp( const Vector<Type> &xn, const Vector<Type> &yn,
                       Type d2l=0, Type d2r=0 );
        ~Spline3Interp();

        void calcCoefs();
        Type evaluate( Type x );
        Matrix<Type> getCoefs() const;

    private:

        void derivative2( Vector<Type> &dx, Vector<Type> &d1,
                          Vector<Type> &d2 );

        Type M0,
             Mn;
        Matrix<Type> coefs;

    };
    // class Spline3Interp


    #include <spline3interp-impl.h>

}
// namespace itlab


#endif
// SPLINE3INTERP_H
