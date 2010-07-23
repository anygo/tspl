/*****************************************************************************
 *                                interpolation.h
 *
 * Base class for interpolation.
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef INTERPOLATION_H
#define INTERPOLATION_H


#include <vector.h>


namespace itlab
{

    template <typename Type>
    class Interpolation
    {

     public:

        Interpolation( const Vector<Type> &xn,  const Vector<Type> &yn )
                     : xi(xn), yi(yn)
        {
        }

        virtual ~Interpolation()
        {
        }

        virtual void calcCoefs() = 0;
        virtual Type evaluate( Type x ) = 0;

    protected:

        Vector<Type> xi;        // abscissas
        Vector<Type> yi;        // ordinates

    };
    // class Interpolation

}
// namespace itlab


#endif
// INTERPOLATION_H
