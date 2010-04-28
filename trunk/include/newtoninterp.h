/*****************************************************************************
 *                                newtoninterp.h
 *
 * Newton interpolation method.
 *
 * For a given points set "Pn" {xn,yn}, this class can find a polynomial which
 * cross all points of "Pn".
 *
 * Zhang Ming, 2010-04
 *****************************************************************************/


#ifndef NEWTONINTERP_H
#define NEWTONINTERP_H


#include <interpolation.h>


namespace itlab
{

    template <typename Type>
    class NewtonInterp : public Interpolation<Type>
    {

     public:

        using Interpolation<Type>::xi;
        using Interpolation<Type>::yi;

        NewtonInterp( const Vector<Type> &xn, const Vector<Type> &yn );
        ~NewtonInterp();

        void calcCoefs();
        Type evaluate( Type x );
        Vector<Type> getCoefs() const;

    private:

        Vector<Type> coefs;

    };
    // class NewtonInterp


    #include <newtoninterp-impl.h>

}
// namespace itlab


#endif
// NEWTONINTERP_H
