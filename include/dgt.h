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
#include <utilities.h>


namespace itlab
{

    /**
     * Return the daul function of input window "g".
     */
    template <typename Type>
    Vector<Type> daul( const Vector<Type> &gn, int N, int dM )
    {
        int L = gn.size(),
            NL = 2*L-N;

        Vector<Type> hn(L);
        Vector<Type> gg = wextend( gn, NL, "right", "zpd" );

        // coefficient matrix and constant vector
        Matrix<Type> H(NL/N,L/dM);
        Vector<Type> u(NL/N);
        u[0] = Type(1.0/N);

        // evaluate matrix H
        for( int k=0; k<dM; ++k )
        {
            for( int q=0; q<NL/N; ++q )
                for( int p=0; p<L/dM; ++p )
                {
                    int index = mod( k+p*dM+q*N, NL );
                    H[q][p] = gg[index];
                }

            // calculate the kth part value of h
            Vector<Type> tmp = prod( tranProd( H, inverse(prod(H,transpose(H))) ), u );
            for( int i=0; i<tmp.dim(); ++i )
                hn[k+i*dM] = tmp[i];
        }
        return hn;
    }


    /**
     * Compute the discrete Gabor transform of "signal". The coeffitions are
     * stored in "coefs", a Ls+Lw by Lw (Ls: lengthof "signsl", Lw:
     * length of "window") matrix. The row represents frequency ordinate
     * and column represents the time ordinate.
     */
    template <typename Type>
    Matrix< complex<Type> > dgt( const Vector<Type> &signal, const Vector<Type> &anaWin,
                                 int N, int dM, const string &mode = "zpd" )
    {
        int Ls = signal.dim();
        int Lw = anaWin.dim();
        int M = (Ls+Lw)/dM;

        Vector<Type> sn = wextend( signal, Lw, "both", mode );

        Matrix< complex<Type> > coefs(N/2+1,M);
        Vector<Type> segment(Lw);
        Vector< complex<Type> > segDFT(Lw/2+1);
        Vector< complex<Type> > tmp(N/2+1);
        complex<Type> W = polar( Type(1), Type(-2*PI/N) );

        for( int m=0; m<M; ++m )
        {
            // intercept signal by window function
            for( int i=0; i<Lw; ++i )
                segment[i] = sn[i+m*dM]*anaWin[i];

            // Fourier transform
            fft( segment, segDFT );

            // calculate the mth culumn coefficients
            for( int n=0; n<N/2+1; ++n )
                tmp[n] = pow(W,n*m*dM) * segDFT[n*Lw/N];

            coefs.setColumn(tmp, m+1);
        }

        return coefs;
    }


    /**
     * Compute the inverse discrete Gabor transform from "coefs".
     */
    template <typename Type>
    Vector<Type> idgt( const Matrix< complex<Type> > &coefs, const Vector<Type> &synWin,
                       int N, int dM )
    {
        int M = coefs.cols();
        int Lw = synWin.size();
        int Ls = dM*M-Lw;

        // reallocate for signal and initialize it by "0"
        Vector<Type> signal(Ls);

        Matrix<Type> idftCoefs(N,M);
        Vector<Type> sn(N);
        Vector< complex<Type> > Sk(N/2+1);

        for( int i=0; i<M; ++i )
        {
            Sk = coefs.getColumn(i+1);
            ifft( Sk, sn );
            sn *= Type(N);

            idftCoefs.setColumn( sn, i+1 );
        }

        // compulate the ith element of signal
        for( int i=0; i<Ls; ++i )
        {
            int p = ceil(i+1, dM);
            for( int m=p; m<p+Lw/dM; ++m )
            {
                int n = mod(i,N);
                signal[i] += idftCoefs[n][m]*synWin[Lw-m*dM+i];
            }
        }

/*======================replace line 132 to 154================================

		complex<Type> W = polar( Type(1), Type(2*PI/N) );

		// compulate the ith element of sig
		for( int i=0; i<Ls; ++i )
		{
			int p = ceil( i+1, dM );

			for( int m=p; m<p+Lw/dM; ++m )
			{
			    for( int n=0; n<N/2+1; ++n )
				    signal[i] += real( coefs[n][m]*
                                 synWin[Lw-m*dM+i]*pow(W,i*n) );
                for( int n=N/2+1; n<N; ++n )
				    signal[i] += real( conj(coefs[N-n][m])*
                                 synWin[Lw-m*dM+i]*pow(W,i*n) );
			}
		}
=============================================================================*/

		return signal;
    }


//    template <typename Type>
//    Matrix< complex<Type> > dgt( const Vector<Type> &signal, const Vector<Type> &anaWin,
//                                 int N, int dM, const string &mode = "zpd" )
//    {
//        int Ls = signal.dim();
//        int Lw = anaWin.dim();
//        int M = (Ls+Lw)/dM;
//
//        Vector<Type> sn = wextend( signal, Lw, "both", mode );
//
//        Matrix< complex<Type> > coefs(N/2+1,M);
//        Vector<Type> segment(Lw);
//        Vector< complex<Type> > segDFT(Lw/2+1);
//        Vector< complex<Type> > tmp(N/2+1);
//        complex<Type> W = polar( Type(1), Type(-2*PI/N) );
//
//        fftw_plan r2cP;
//        for( int m=0; m<M; ++m )
//        {
//            // intercept signal by window function
//            for( int i=0; i<Lw; ++i )
//                segment[i] = sn[i+m*dM]*anaWin[i];
//
//            // Fourier transform
//            r2cP = fftw_plan_dft_r2c_1d( segment.size(), segment.begin(),
//                   reinterpret_cast<fftw_complex*>(segDFT.begin()),
//                   FFTW_ESTIMATE );
//            fftw_execute( r2cP );
//
//            // calculate the mth culumn coefficients
//            for( int n=0; n<N/2+1; ++n )
//                tmp[n] = pow(W,n*m*dM) * segDFT[n*Lw/N];
//
//            coefs.setColumn(tmp, m+1);
//        }
//        fftw_destroy_plan( r2cP );
//
//        return coefs;
//    }
//
//
//    template <typename Type>
//    Vector<Type> idgt( const Matrix< complex<Type> > &coefs, const Vector<Type> &synWin,
//                       int N, int dM )
//    {
//        int M = coefs.cols();
//        int Lw = synWin.size();
//        int Ls = dM*M-Lw;
//
//        // reallocate for signal and initialize it by "0"
//        Vector<Type> signal(Ls);
//        Matrix<Type> idftCoefs(N,M);
//        Vector<Type> sn(N);
//        Vector< complex<double> > Sk(N/2+1);
//
//        fftw_plan c2rP;
//        for( int i=0; i<M; ++i )
//        {
//            Sk = coefs.getColumn(i+1);
//            c2rP = fftw_plan_dft_c2r_1d( N,
//                   reinterpret_cast<fftw_complex*>(Sk.begin()),
//                   sn.begin(), FFTW_ESTIMATE );
//            fftw_execute( c2rP );
//
//            idftCoefs.setColumn( sn, i+1 );
//        }
//        fftw_destroy_plan( c2rP );
//
//        // compulate the ith element of signal
//        for( int i=0; i<Ls; ++i )
//        {
//            int p = ceil(i+1, dM);
//            for( int m=p; m<p+Lw/dM; ++m )
//            {
//                int n = mod(i,N);
//                signal[i] += idftCoefs[n][m]*synWin[Lw-m*dM+i];
//            }
//        }
//        return signal;
//    }

}
// namespace itlab


#endif
// DGT_H
