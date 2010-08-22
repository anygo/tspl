/*****************************************************************************
 *                                    dwt.h
 *
 * Discrete Wavelet Transform.
 *
 * Class template of discrete wavelet transform, which is designed for
 * computing the discrete wavelet transform and it's inverse transform. The
 * wavelet type is specified by parameter "wname".
 *
 * The decompse and reconstruction levels are specified by integer "J". The
 * approximation and detial coefficents are stroed in an 1D vector as
 * fallowing format:
 *                      ---------------------------------
 *		                | d1 | d2 | * | * | * | dJ | aJ |
 *		                ---------------------------------
 * The signal's length, detial's and approximation's  lengths, are stored
 * in a vectro as fallow:
 *              --------------------------------------------------
 *              | L_sig | L_d1 | L_d2 | * | * | * | L_dJ | L_aJ |
 *              --------------------------------------------------
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef DWT_H
#define DWT_H


#include <string>
#include <cstdlib>
#include <vector.h>
#include <utilities.h>
#include <filtercoefs.h>


namespace itlab
{

	template <typename Type>
	class DWT
	{

	public:

		DWT( const string &wname );
		~DWT();

		Vector<Type> dwt( const Vector<Type> &signal, int J );
		Vector<Type> idwt( const Vector<Type> &coefs, int j );

		Vector<Type> getApprox( const Vector<Type> &coefs );
		Vector<Type> getDetial( const Vector<Type> &coefs, int j );
		void setApprox( const Vector<Type> &approx, Vector<Type> &coefs );
		void setDetial( const Vector<Type> &detial, Vector<Type> &coefs, int j );

    private:

        // wavelet type
        string waveType;

        // decompose and reconstruction filter banks
        Vector<Type> ld, hd,
                     lr, hr;

		// length information of coefficients
		Vector<int> lenInfo;

		void getFilter( const string &wname );
		void lengthInit( int sigLength, int J );

	};
    // class DWT


    #include <dwt-impl.h>

}
// namespace itlab


#endif
// DWT_H
