/*****************************************************************************
 *                                vectormath.h
 *
 * This file provides the basic math functions such as:
 *              cos    sin    tan    acos   asin   atan
 *              abs    exp    log    log10  sqrt   pow
 *
 * Zhang Ming, 2010-08, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef VECTORMATH_H
#define VECTORMATH_H


#include <vector.h>


namespace itlab
{

    template<typename Type> Vector<Type> abs( const Vector<Type>& );
    template<typename Type> Vector<Type> cos( const Vector<Type>& );
    template<typename Type> Vector<Type> sin( const Vector<Type>& );
    template<typename Type> Vector<Type> tan( const Vector<Type>& );
    template<typename Type> Vector<Type> acos( const Vector<Type>& );
    template<typename Type> Vector<Type> asin( const Vector<Type>& );
    template<typename Type> Vector<Type> atan( const Vector<Type>& );

    template<typename Type> Vector<Type> exp( const Vector<Type>& );
    template<typename Type> Vector<Type> log( const Vector<Type>& );
    template<typename Type> Vector<Type> log10( const Vector<Type>& );

    template<typename Type> Vector<Type> sqrt( const Vector<Type>& );
    template<typename Type> Vector<Type> pow( const Vector<Type>&, const Vector<Type>& );
    template<typename Type> Vector<Type> pow( const Vector<Type>&, const Type& );
    template<typename Type> Vector<Type> pow( const Type&, const Vector<Type>& );

    template<typename Type> Vector<Type> abs( const Vector< complex<Type> >& );
    template<typename Type> Vector<Type> arg( const Vector< complex<Type> >& );
    template<typename Type> Vector<Type> real( const Vector< complex<Type> >& );
    template<typename Type> Vector<Type> imag( const Vector< complex<Type> >& );
    template<typename Type> Vector<Type> gauss( const Vector<Type>&, const Type&, const Type& );


    #include <vectormath-impl.h>

}
// namespace itlab


#endif
// VECTORMATH_H
