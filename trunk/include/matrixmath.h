/*****************************************************************************
 *                               matrixmath.h
 *
 * This file provides the basic math functions such as:
 *              cos    sin    tan    acos   asin   atan
 *              abs    exp    log    log10  sqrt   pow
 *
 * When debugging, use #define BOUNDS_CHECK above your "#include matrix.h"
 * line. When done debugging, comment out #define BOUNDS_CHECK for better
 * performance.
 *
 * Zhang Ming, 2010-01 (revised 2010-08), Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef MATRIXMATH_H
#define MATRIXMATH_H


#include <matrix.h>


namespace itlab
{

    template<typename Type> Matrix<Type> abs( const Matrix<Type>& );
    template<typename Type> Matrix<Type> cos( const Matrix<Type>& );
    template<typename Type> Matrix<Type> sin( const Matrix<Type>& );
    template<typename Type> Matrix<Type> tan( const Matrix<Type>& );
    template<typename Type> Matrix<Type> acos( const Matrix<Type>& );
    template<typename Type> Matrix<Type> asin( const Matrix<Type>& );
    template<typename Type> Matrix<Type> atan( const Matrix<Type>& );

    template<typename Type> Matrix<Type> exp( const Matrix<Type>& );
    template<typename Type> Matrix<Type> log( const Matrix<Type>& );
    template<typename Type> Matrix<Type> log10( const Matrix<Type>& );

    template<typename Type> Matrix<Type> sqrt( const Matrix<Type>& );
    template<typename Type> Matrix<Type> pow( const Matrix<Type>&, const Matrix<Type>& );
    template<typename Type> Matrix<Type> pow( const Matrix<Type>&, const Type& );
    template<typename Type> Matrix<Type> pow( const Type&, const Matrix<Type>& );

    template<typename Type> Matrix<Type> abs( const Matrix< complex<Type> >& );
    template<typename Type> Matrix<Type> arg( const Matrix< complex<Type> >& );
    template<typename Type> Matrix<Type> real( const Matrix< complex<Type> >& );
    template<typename Type> Matrix<Type> imag( const Matrix< complex<Type> >& );


    #include <matrixmath-impl.h>

}
// namespace itlab


#endif
// MATRIXMATH_H
