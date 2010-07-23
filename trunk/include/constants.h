/*****************************************************************************
 *                                 constants.h
 *
 * Some constants often used in numeric computing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef	CONSTANTS_H
#define CONSTANTS_H


namespace itlab
{

    const double	EPS		    = 2.220446049250313e-016;

    const double	PI		    = 3.141592653589793;
    const double	TWOPI	    = 6.283185307179586;
    const double	HALFPI	    = 1.570796326794897;
    const double	D2R 	    = 0.017453292519943;

    const double	EXP		    = 2.718281828459046;

    const double	RT2		    = 1.414213562373095;
    const double	IRT2	    = 0.707106781186547;

    const int		FORWARD	    = 1;
    const int		INVERSE	    = 0;

    const int		MAXTERM	    = 100;
    const int       INITSIZE    = 20;
    const int       EXTFACTOR   = 2;

}


#endif
// CONSTANTS_H
