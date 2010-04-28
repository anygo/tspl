/*****************************************************************************
 *                               integrand.h
 *
 * Integrand used in numerical integral.
 *
 * Zhang Ming, 2010-04
 *****************************************************************************/


#ifndef INTEGRAND_H
#define INTEGRAND_H


#include <cmath>
#include <constants.h>


namespace itlab
{

    /**
     * Integrand, a function objective.
     */
    template <typename Type>
    class Func
    {

    public:

        /**
         * Initialize the parameters
         */
        Func( Type aa, Type bb ) : a(aa), b(bb)
        { }

        /**
         * Compute the value of objective function at point x.
         */
        Type operator()( Type x )
        {
            return a + b*sin(x);
        }

    private:

        Type a,
             b;

    };
    // class Func

}
// namespace itlab


#endif
// INTEGRAND_H
