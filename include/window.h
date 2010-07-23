/*****************************************************************************
 *                                 window.h
 *
 * Often used windows in signal processing, particularly in FIR design.
 *
 * There are seven windows in this file:
 *      Rectangle        Bartlett        Hanning     Hamming
 *      Blackman         Kaiser          Gauss
 * All of them are same to those in "Matlab".
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef WINDOW_H
#define WINDOW_H


#include <constants.h>
#include <vector.h>


namespace itlab
{

    /**
     * The zeroth N modified Bessel function of the first kind.
     */
    double I0( double alpha )
    {
        double  J = 1.0,
                K = alpha / 2.0,
                iOld = 1.0,
                iNew;
        bool    converge = false;

        // Use series expansion definition of Bessel.
        for( int i=1; i<MAXTERM; ++i )
        {
            J *= K/i;
            iNew = iOld + J*J;

            if( (iNew-iOld) < EPS )
            {
                converge = true;
                break;
            }
            iOld = iNew;
        }

        if( !converge )
            return 0.0;

        return iNew;
    }


    /**
     * Calculates rectangle window coefficients.
     */
    Vector<double> rectangle( int N )
    {
        Vector<double> win(N);

        for( int i=0; i<(N+1)/2; ++i )
        {
            win[i] = 1.0;
            win[N-1-i] = win[i];
        }

        return win;
    }


    /**
     * Calculates bartlett window coefficients.
     */
    Vector<double> bartlett( int N )
    {
        Vector<double> win(N);

        for( int i=0; i<(N+1)/2; ++i )
        {
            win[i] = (2.0*i) / (N-1.0);
            win[N-1-i] = win[i];
        }

        return win;
    }


    /**
     * Calculates hanning window coefficients.
     */
    Vector<double> hanning( int N )
    {
       Vector<double> win(N);

        for( int i=0; i<(N+1)/2; ++i )
        {
            win[i] = 0.5 - 0.5*cos( TWOPI*i/(N-1.0) );
            win[N-1-i] = win[i];
        }

        return win;
    }


    /**
     * Calculates hamming window coefficients.
     */
    Vector<double> hamming( int N )
    {
        Vector<double> win(N);

        for( int i=0; i<(N+1)/2; ++i )
        {
            win[i] = 0.54 - 0.46*cos( TWOPI*i/(N-1.0) );
            win[N-1-i] = win[i];
        }

        return win;
    }


    /**
     * Calculates hamming window coefficients.
     */
    Vector<double> blackman( int N )
    {
        Vector<double> win(N);

        for( int i=0; i<(N+1)/2; ++i )
        {
            win[i] = 0.42 - 0.50*cos( TWOPI*i/(N-1.0) )
                          + 0.08*cos( 2*TWOPI*i/(N-1.0) );
            win[N-1-i] = win[i];
        }

        return win;
    }


    /**
     * Calculates hamming window coefficients.
     */
    Vector<double> kaiser( int N, double alpha )
    {
        Vector<double> win(N);

        for( int i=0; i<(N+1)/2; ++i )
        {
            double beta = 2.0*alpha * sqrt(i*(N-i-1.0)) / (N-1.0);
            win[i] = I0(beta) / I0(alpha);
            win[N-1-i] = win[i];
        }

        return win;
    }


    /**
     * Calculates gauss window coefficients. "Alpha: is a optional parameter,
     * the default value is 2.5.
     */
    Vector<double> gauss( int N, double alpha = 2.5 )
    {
        Vector<double> win(N);
        double center = (N-1)/2.0;

        for( int i=0; i<(N+1)/2; ++i )
        {
            double tmp = alpha*(i-center) / center;
            win[i] = exp( -0.5*tmp*tmp );
            win[N-1-i] = win[i];
        }

        return win;
    }


	/**
     * Get the specified window.
     */
	Vector<double> window( const string &type, int N )
	{
	    Vector<double> tmp(N);

	    if( type=="Rectangle" )
            tmp = rectangle( N );
        else if( type=="Bartlett" )
            tmp = bartlett( N );
        else if( type=="Hanning" )
            tmp = hanning( N );
        else if( type=="Hamming" )
            tmp = hamming( N );
        else if( type=="Blackman" )
            tmp = blackman( N );
        else if( type=="Gauss" )
            tmp = gauss( N );
        else
        {
            cerr << "No such type window!" << endl;
            return Vector<double> (0);
        }

        return tmp;
	}

	Vector<double> window( const string &type, int N, double alpha )
	{
	    Vector<double> tmp(N);

	    if( type=="Kaiser" )
            tmp = kaiser( N, alpha );
        else if( type=="Gauss" )
            tmp = gauss( N, alpha );
        else
        {
            cerr << "No such type window!" << endl;
            return Vector<double> (0);
        }

        return tmp;
	}

}
// namespace itlab


#endif
// WINDOW_H
