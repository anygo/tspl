/*****************************************************************************
 *                                    dgt.h
 *
 * Discrete Gabor Transform.
 *
 * These routines are designed for calculating discrete Gabor transform
 * and its inversion of 1D signals. In order to eliminate the border effect,
 * the input signal("signal") is extended by three forms: zeros padded("zpd"),
 * periodized extension("ppd") and symetric extension("sym").
 *
 * The analysis/synthesis function is given by users, and it's daul
 * (synthesis/analysis) function can be computed by "daul" routine.
 * The over sampling rate is equal to N/dM, where N denotes frequency
 * sampling numbers and dM denotes the time sampling interval.
 *
 * N and dM should can be devided evenly by the window length "Lw". The
 * recovered signal just has the elements from 1 to dM*floor(Ls/dM) of the
 * original signal. So you'd better let dM can be deviede evenly by  the
 * original signal length "Ls".
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef DGT_H
#define DGT_H


#include <string>
#include <complex>
#include <fft.h>
#include <matrix.h>
#include <linequs3.h>
#include <utilities.h>


namespace itlab
{


    template<typename Type> Vector<Type> daul( const Vector<Type>&, int, int );
    template<typename Type> Matrix< complex<Type> > dgt( const Vector<Type>&, const Vector<Type>&,
                                                         int, int, const string &mode = "zpd" );
    template<typename Type> Vector<Type> idgt( const Matrix< complex<Type> >&, const Vector<Type>&,
                                               int, int );


    #include <dgt-impl.h>

}
// namespace itlab


#endif
// DGT_H
