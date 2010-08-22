/*****************************************************************************
 *                                    bwt.h
 *
 * Dyadic Wavelet Transform.
 *
 * These routines are designed for computing the dyadic wavelet transform
 * and it's inverse transform using quadratic spline wavelet.
 *
 * To distinguish with the "dwt" (discrete wavelet transform), we call this
 * file as "bwt", but in fact, it should be dyadic wavelet transform.                                                                                 *
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef BWT_H
#define BWT_H


#include <constants.h>
#include <vector.h>
#include <utilities.h>


namespace itlab
{

    template<typename Type> Vector< Vector<Type> > bwt( const Vector<Type>&, int );
    template<typename Type> Vector<Type> ibwt( const Vector< Vector<Type> >&, int );


    #include <bwt-impl.h>

}
// namespace itlab


#endif
// BWT_H
