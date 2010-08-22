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


#include <vector.h>


namespace itlab
{

    Vector<double> window( const string&, int );
	Vector<double> window( const string&, int, double );

    Vector<double> rectangle( int );
    Vector<double> bartlett( int );
    Vector<double> hanning( int );
    Vector<double> hamming( int );
    Vector<double> blackman( int );
    Vector<double> kaiser( int, double );
    Vector<double> gauss( int, double alpha = 2.5 );

	double I0( double alpha );


	#include <window-impl.h>

}
// namespace itlab


#endif
// WINDOW_H
