/*****************************************************************************
 *                               integral_test.cpp
 *
 * Numerical integral testing.
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


#include <iostream>
#include <integral.h>


using namespace std;
using namespace itlab;


int main()
{
    double  p1 = 1,
            p2 = 2,
            lower = 0,
            upper = PI,
            I = 0;
    Func<double> f( p1, p2 );

    I = romberg( f, lower, upper );
    cout << "The integral of function 'f' from " << lower <<
            " to " << upper << " is:" << endl << I << endl << endl;

    return 0;
}
