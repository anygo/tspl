/*****************************************************************************
 *                                 statistics.h
 *
 * Some generally used routines about probability and statistics, such as
 * median, mean, variance, standard variance, skew, kurtosis and the
 * PDF(probability density function).
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef STATISTICS_H
#define STATISTICS_H


#include <vector.h>


namespace itlab
{

    template<typename Type> Type mid( const Vector<Type>& );
    template<typename Type> Type mean( const Vector<Type>& );

    template<typename Type> Type var( const Vector<Type>& );
    template<typename Type> Type stdVar( const Vector<Type>& );
    template<typename Type> Vector<Type> standard( const Vector<Type>& );

    template<typename Type> Type skew( const Vector<Type>& );
    template<typename Type> Type kurt( const Vector<Type>& );

    template<typename Type> Vector<Type> pdf( Vector<Type>&, const Type lambda=1 );


    #include <statistics-impl.h>

}
// namespace itlab


#endif
// STATISTICS_H
