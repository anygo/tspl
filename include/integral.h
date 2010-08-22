/*****************************************************************************
 *                                 integral.h
 *
 * Numerical integral using Romberg method.
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef INTEGRAL_H
#define INTEGRAL_H


#include <iostream>
#include <integrand.h>


namespace itlab
{

    template<typename Type> Type romberg( Func<Type>&, const Type&, const Type&, const Type tol=1.0e-6 );


    #include <integral-impl.h>

}
// namespace itlab


#endif
// INTEGRAL_H
