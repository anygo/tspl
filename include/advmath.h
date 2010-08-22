/*****************************************************************************
 *                                  advmath.h
 *
 * Some advance math functions used in IIR filter design.
 *
 * Adapted form "Analog and Digital Filter Design", Les Thede, 2004.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef ADVMATH_H
#define ADVMATH_H


#include <cmath>
#include <complex>


namespace itlab
{

    inline double acosh( double );
    inline double asinh( double );

    double arcsc( double, double );
    void ellipticFun( double, double, double*, double*, double* );
    double ellipticIntegral( double );

    void quadradicRoot( complex<double>, complex<double>, complex<double>,
                        complex<double>&, complex<double>& );


    #include <advmath-impl.h>

}
// namespace itlab


#endif
// ADVMATH_H
