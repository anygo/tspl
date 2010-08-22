/*****************************************************************************
 *                                filtercoefs.h
 *
 * Some generally used filter coeffcients in wavelet transform.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef COEFFICIENTS_H
#define COEFFICIENTS_H


#include <vector.h>


namespace itlab
{


	template<typename Type>	void db4Coefs( Vector<Type>&, Vector<Type>&,
	                                       Vector<Type>&, Vector<Type>& );


    #include <filtercoefs-impl.h>

}
// namespace itlab


#endif
// COEFFICIENTS_H
