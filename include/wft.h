/*****************************************************************************
 *                                    wft.h
 *
 * Windowed Fourier Transform.
 *
 * These routines are designed for calculating WFT and IWFT of 1D signals.
 * The windows for forward and backword transform should be the same.
 *
 * In order to eliminate border effect, the input signal is extended by
 * three forms: zeros padded("zpd"), periodized extension("ppd") and
 * symetric extension("sym").
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef WFT_H
#define WFT_H


#include <string>
#include <complex>
#include <fft.h>
#include <matrix.h>
#include <utilities.h>


namespace itlab
{

    template<typename Type> Matrix< complex<Type> > wft( const Vector<Type>&, const Vector<Type>&,
                                                         const string &mode = "zpd" );
    template<typename Type> Vector<Type> iwft( const Matrix< complex<Type> >&, const Vector<Type>& );


    #include <wft-impl.h>

}
// namespace itlab


#endif
// WFT_H
