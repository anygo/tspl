/*****************************************************************************
 *                                lsfitting.h
 *
 * Least Square Fitting.
 *
 * For a given points set "Pn" {xn,yn} and a fitted function with paramter
 * "pm", this class can find the best parameter "pm" in the meaning of least
 * mean-square error.
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef LSFITTING_H
#define LSFITTING_H


#include <matrix.h>
#include <linequs1.h>
#include <functions.h>
#include <interpolation.h>


namespace itlab
{

    template <typename Type>
    class LSFitting : public Interpolation<Type>
    {

     public:

        using Interpolation<Type>::xi;
        using Interpolation<Type>::yi;

        LSFitting( const Vector<Type> &xn, const Vector<Type> &yn, Funcs<Type> &f );
        ~LSFitting();

        void calcCoefs();
        Type evaluate( Type x );
        Vector<Type> getCoefs() const;

    private:

        Vector<Type> coefs;     // fitted parameters
        Funcs<Type>  phi;       // fitted functions

    };
    // class LSFitting


    #include <lsfitting-impl.h>

}
// namespace itlab


#endif
// LSFITTING_H
