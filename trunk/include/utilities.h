/*****************************************************************************
 *                                  utilities.h
 *
 * Some usable routines converted from "Matlab", which are used in wavelet
 * transform and time-frequency analysis, such as "filp"(same to reverse),
 * "shift", "circshift", "fftshift", "dyadup", "wkeep", "wextend" and so on.
 *
 * Warning: the convolution routine "conv" is implemented by it's definition
 * in time domain, so if the sequence to be convoluted are long, you should
 * use the fast convolution algorithm "fastConv", which is implemented in
 * frequency domain by usin FFT.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef UTILITIES_H
#define UTILITIES_H


#include <string>
#include <vector.h>


namespace itlab
{


    int mod( int, int );
    int ceil( int, int );

    bool isPower2( int );
    int fastLog2( int n );

	template<typename Type> Vector<Type> linspace( Type, Type, int );

	template<typename Type> Vector<Type> reverse( const Vector<Type>& );
    template<typename Type> Vector<Type> flip( const Vector<Type>& );
    template<typename Type> Vector<Type> shift( const Vector<Type>& );
    template<typename Type> Vector<Type> cirshift( const Vector<Type>& );
    template<typename Type> Vector<Type> fftshift( const Vector<Type>& );

    template<typename Type> Vector<Type> dyadUp( const Vector<Type>&, int );
    template<typename Type> Vector<Type> dyadDown( const Vector<Type>&, int );

    template<typename Type> Vector<Type> wkeep( const Vector<Type>&, int, int );
    template<typename Type> Vector<Type> wkeep( const Vector<Type>&, int, const string& );
    template<typename Type> Vector<Type> wextend( const Vector<Type>&, int, const string&, const string& );

    template<typename Type> Vector<Type> conv( const Vector<Type>&, const Vector<Type>& );
    template<typename Type> Vector<Type> convolution( const Vector<Type>&, const Vector<Type>& );


    #include <utilities-impl.h>

}
// namespace itlab


#endif
// UTILITIES_H
