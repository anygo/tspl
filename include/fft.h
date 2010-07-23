/*****************************************************************************
 *                                    fft.h
 *
 * A simple C++ interface for FFTW. This file only provides the one dimension
 * DFT and IDFT for data type as "Vector<Type>" in ITLab, where "Type" can
 * be "double", "complex<double>, "float" or "complex<float>.
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

    /**
     * Real to complex DFT of 1D signal. If "xn" has N points, "Xk"
     * should has N/2+1 points.
     */
    inline void fft( Vector<double> &xn, Vector< complex<double> > &Xk )
    {
        fftw_plan r2cP;
        r2cP = fftw_plan_dft_r2c_1d( xn.dim(), xn.begin(),
               reinterpret_cast<fftw_complex*>(Xk.begin()),
               FFTW_ESTIMATE );
        fftw_execute( r2cP );
        fftw_destroy_plan( r2cP );
    }

    inline void fft( Vector<float> &xn, Vector< complex<float> > &Xk )
    {
        fftwf_plan r2cP;
        r2cP = fftwf_plan_dft_r2c_1d( xn.dim(), xn.begin(),
               reinterpret_cast<fftwf_complex*>(Xk.begin()),
               FFTW_ESTIMATE );
        fftwf_execute( r2cP );
        fftwf_destroy_plan( r2cP );
    }


    /**
     * Complex to complex DFT of 1D signal.
     */
    inline void fft( Vector< complex<double> > &xn, Vector< complex<double> > &Xk )
    {
        fftw_plan c2cP;
        c2cP = fftw_plan_dft_1d( xn.dim(),
               reinterpret_cast<fftw_complex*>(xn.begin()),
               reinterpret_cast<fftw_complex*>(Xk.begin()),
               FFTW_FORWARD, FFTW_ESTIMATE );
        fftw_execute( c2cP );
        fftw_destroy_plan( c2cP );
    }

    inline void fft( Vector< complex<float> > &xn, Vector< complex<float> > &Xk )
    {
        fftwf_plan c2cP;
        c2cP = fftwf_plan_dft_1d( xn.dim(),
               reinterpret_cast<fftwf_complex*>(xn.begin()),
               reinterpret_cast<fftwf_complex*>(Xk.begin()),
               FFTW_FORWARD, FFTW_ESTIMATE );
        fftwf_execute( c2cP );
        fftwf_destroy_plan( c2cP );
    }


    /**
     * Complex to real IDFT of 1D. If "xn" has N points, "Xk" should
     * has N/2+1 points.
     */
    inline void ifft( Vector< complex<double> > &Xk, Vector<double> &xn )
    {
        fftw_plan c2rP;
        c2rP = fftw_plan_dft_c2r_1d( xn.dim(),
               reinterpret_cast<fftw_complex*>(Xk.begin()),
               xn.begin(), FFTW_ESTIMATE );
        fftw_execute( c2rP );
        fftw_destroy_plan( c2rP );

        xn /= double( xn.dim() );
    }

    inline void ifft( Vector< complex<float> > &Xk, Vector<float> &xn )
    {
        fftwf_plan c2rP;
        c2rP = fftwf_plan_dft_c2r_1d( xn.dim(),
               reinterpret_cast<fftwf_complex*>(Xk.begin()),
               xn.begin(), FFTW_ESTIMATE );
        fftwf_execute( c2rP );
        fftwf_destroy_plan( c2rP );

        xn /= float( xn.dim() );
    }


    /**
     * Complex to complex IDFT of 1D.
     */
    inline void ifft( Vector< complex<double> > &Xk, Vector< complex<double> > &xn )
    {
        fftw_plan c2cP;
        c2cP = fftw_plan_dft_1d( xn.dim(),
               reinterpret_cast<fftw_complex*>(Xk.begin()),
               reinterpret_cast<fftw_complex*>(xn.begin()),
               FFTW_BACKWARD, FFTW_ESTIMATE );
        fftw_execute( c2cP );
        fftw_destroy_plan( c2cP );

        xn /= complex<double>( xn.dim(), 0.0 );
    }

    inline void ifft( Vector< complex<float> > &Xk, Vector< complex<float> > &xn )
    {
        fftwf_plan c2cP;
        c2cP = fftwf_plan_dft_1d( xn.dim(),
               reinterpret_cast<fftwf_complex*>(Xk.begin()),
               reinterpret_cast<fftwf_complex*>(xn.begin()),
               FFTW_BACKWARD, FFTW_ESTIMATE );
        fftwf_execute( c2cP );
        fftwf_destroy_plan( c2cP );

        xn /= complex<float>( xn.dim(), 0.0 );
    }

}
// namespace itlab


#endif
// FFT_H
