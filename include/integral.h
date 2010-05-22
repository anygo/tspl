/*****************************************************************************
 *                                 integral.h
 *
 * Numerical integral using Romberg method.
 *
 * Zhang Ming, 2010-04
 *****************************************************************************/


#ifndef INTEGRAL_H
#define INTEGRAL_H


#include <iostream>
#include <integrand.h>


namespace itlab
{

    template <typename Type>
    Type romberg( Func<Type> &f, Type a, Type b, Type tol=1.0e-6 )
    {
        int n = 5,
            m = 2*n;
        Type x = 0,
             tmp = 0,
             result = 0;

        for( int k=0; k<MAXTERM; ++k )
        {
            Type h = (b-a)/m;
            for( int i=0; i<n; ++i )
            {
                x = a + (2*i+1)*h;
                tmp += 4*f(x);
            }
            for( int i=1; i<n; ++i )
            {
                x = a + 2*i*h;
                tmp += 2*f(x);
            }
            tmp += f(a)+f(b);
            tmp *= h/3;

            if( abs(tmp-result) < tol )
            {
                result = tmp;
                return result;
            }
            else
            {
                result = tmp;
                tmp = 0;
                n = m;
                m = 2*n;
            }
        }

        std::cerr << "Didn't get the specified precision value!" << std::endl;
        return result;
    }

}
// namespace itlab


#endif
// INTEGRAL_H
