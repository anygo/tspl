/*****************************************************************************
 *                                    coefficients.h
 *
 * Some generally used filter coeffcients in wavelet transform.
 *
 *
 * Zhang Ming, 2010-03
 *****************************************************************************/


#ifndef COEFFICIENTS_H
#define COEFFICIENTS_H


#include <vector.h>


namespace itlab
{

	/**
	 * Daubichies filters for wavelets with 4 vanishing moments.
	 */
	template <typename Type>
	void db4Coefs( Vector<Type> &ld, Vector<Type> &hd,
	               Vector<Type> &lr, Vector<Type> &hr )
	{
		ld.resize(8);
		ld[0] = -0.010597401784997;		ld[1] = 0.032883011666983;
		ld[2] = 0.030841381835987; 		ld[3] = -0.187034811718881;
		ld[4] = -0.027983769416984;		ld[5] = 0.630880767929590;
		ld[6] = 0.714846570552542;		ld[7] = 0.230377813308855;

		hd.resize(8);
		hd[0] = -0.230377813308855;		hd[1] = 0.714846570552542;
		hd[2] = -0.630880767929590;		hd[3] = -0.027983769416984;
		hd[4] = 0.187034811718881;		hd[5] = 0.030841381835987;
		hd[6] = -0.032883011666983;		hd[7] = -0.010597401784997;

		lr = flip(ld);
		hr = flip(hd);
	}

}
// namespace itlab


#endif
// COEFFICIENTS_H
