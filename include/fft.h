/*****************************************************************************
 *                                    fft.h
 *
 * A simple C++ interface for FFTW. This file only provides the one dimension
 * DFT and IDFT for data type as "Vector<Type>" in ITLab, where "Type" can
 * be "double", "complex<double>, "float", "complex<float>, "long double",
 * "complex<long double>.
 *
 * If you need execute FFT many times in your program, it's not a good idear
 * for using this interface because of losing efficiency.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef FFT_H
#define FFT_H


#include <complex>
#include <fftw3.h>
#include <vector.h>


namespace itlab
{


    void fft( Vector<double>&, Vector< complex<double> >& );
    void fft( Vector<float>&, Vector< complex<float> >& );
    void fft( Vector<long double>&, Vector< complex<long double> >& );

    void fft( Vector< complex<double> >&, Vector< complex<double> >& );
    void fft( Vector< complex<float> >&, Vector< complex<float> >& );
    void fft( Vector< complex<long double> >&, Vector< complex<long double> >& );

    void ifft( Vector< complex<double> >&, Vector<double>& );
    void ifft( Vector< complex<float> >&, Vector<float>& );
    void ifft( Vector< complex<long double> >&, Vector<long double>& );

    void ifft( Vector< complex<double> >&, Vector< complex<double> >& );
    void ifft( Vector< complex<float> >&, Vector< complex<float> >& );
    void ifft( Vector< complex<long double> >&, Vector< complex<long double> >& );


    #include <fft-impl.h>

}
// namespace itlab


#endif
// FFT_H
