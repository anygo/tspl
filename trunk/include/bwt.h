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
 * Zhang Ming, 2010-03
 *****************************************************************************/


#ifndef BWT_H
#define BWT_H


#include <constants.h>
#include <vector.h>
#include <utilities.h>


namespace itlab
{

    /**
     * Forward Transform.
     * The decomposition levels is specified by integer "J". The decomposed
     * coefficients are stroed in a "Vector< vector<Type> >" structure.
     * Detial coefficients are stored from 1st to Jth row, and approximation
     * coefficients are stored at the last row, i.e. the (J+1)th row.
     */
    template <typename Type>
    Vector< Vector<Type> > bwt( const Vector<Type> &xn, int J )
    {
        // lowpass decomposition filter
        Vector<Type> ld(4);
        ld[0] = 0.125;		ld[1] = 0.375;
        ld[2] = 0.375;		ld[3] = 0.125;
        ld = Type(RT2) * ld;
        int ldZeroStart = 1;

        // highpass decomposition filter
        Vector<Type> hd(2);
        hd[0] = -0.5;		hd[1] = 0.5;
        hd = Type(RT2) * hd;
        int hdZeroStart = 0;

        // initializing the coefficients
        int N = xn.size();
        Vector< Vector<Type> > coefs(J+1);
        for( int i=0; i<J; ++i )
            coefs[i].resize(N);

        Vector<Type> approx(N);
        Vector<Type> a(xn);

        // get the inversion of filters
        Vector<Type> ll = flip(ld);
        Vector<Type> hh = flip(hd);

        int llZeroStart = 0,
            hhZeroStart = 0,
            p = 1;

        for( int j=0; j<J; ++j )
        {
            // compute the 0 position of the new filters
            llZeroStart = ll.size()-1 - p*ldZeroStart;
            hhZeroStart = hh.size()-1 - p*hdZeroStart;

            for( int i=0; i<N; ++i )
            {
                Type sum = 0;

                // compute the approximation coefficients
                for( int k=0; k<ll.size(); k+=p )
                {
                    int index = mod( i+llZeroStart-k, N );
                    sum += ll[k]*a[index];
                }
                approx[i] = sum;

                // compute the detial coefficients
                sum = 0;
                for( int k=0; k<hh.size(); k+=p )
                {
                    int index = mod( i+hhZeroStart-k, N );
                    sum += hh[k]*a[index];
                }
                coefs[j][i] = sum;
            }

            a = approx;

            // dyadic upsampling
            ll = dyadUp( ll, 1 );
            hh = dyadUp( hh, 1 );
            p *= 2;
        }

        coefs[J] = approx;
        return coefs;
    }


    /**
     * Backword Transform.
     * The reconstruction livel is specified by integer "level", and
     * "levle" should between "0"(the approximation component) and "J"
     * (the original signal).
     */
    template <typename Type>
    Vector<Type> ibwt( const Vector< Vector<Type> > &coefs, int level )
    {
        Vector<Type> lr(4);
		lr[0] = 0.125;		lr[1] = 0.375;
		lr[2] = 0.375;		lr[3] = 0.125;
		lr = Type(RT2) * lr;
		int lrZeroStart = 1;

		Vector<Type> hr(6);
		hr[0] =	-0.03125;	hr[1] = -0.21875;	hr[2] = -0.6875;
		hr[3] = 0.6875;		hr[4] = 0.21875;	hr[5] = 0.03125;
		hr = Type(RT2) * hr;
		int hrZeroStart = 2;

        int J = coefs.dim() - 1;
        if( (level < 0) || (level > J) )
        {
            cout << "invalid reconstruction level!" << endl;
            return Vector<Type>(0);
        }

        int N = coefs[0].dim();
        Vector<Type> a = coefs[J];
        Vector<Type> xn(N);

        Vector<Type> ll = lr;
        Vector<Type> hh = hr;
        int llZeroStart = 0;
        int hhZeroStart = 0;
        int p = 1;

        // get the Jth level filters
        for( int j=0; j<level-1; ++j )
        {
            p *= 2;
            ll = dyadUp( ll, 1 );
            hh = dyadUp( hh, 1 );
        }

        for( int j=level-1; j>=0; --j )
        {
            // compute the 0 position of the new filters
            llZeroStart = p*lrZeroStart;
            hhZeroStart = p*hrZeroStart;

            // compute the jth approximation coefficients
            for( int i=0; i<N; ++i )
            {
                Type sum = 0;
                for( int k=0; k<ll.size(); k+=p )
                {
                    int index = mod( i+llZeroStart-k, N );
                    sum += ll[k]*a[index];
                }

                for( int k=0; k<hh.size(); k+=p )
                {
                    int index = mod( i+hhZeroStart-k, N );
                    sum += hh[k]*coefs[j][index];
                }

                xn[i] = sum/2;
            }

            a = xn;

            // dyadic downsampling
            ll = dyadDown( ll, 0 );
            hh = dyadDown( hh, 0 );
            p /= 2;
        }

        return xn;
    }

}
// namespace itlab


#endif
// BWT_H
