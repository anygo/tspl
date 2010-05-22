/*****************************************************************************
 *                               spline3interp_test.cpp
 *
 * Spline3 interpolation testing.
 *
 * Zhang Ming, 2010-04
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <constants.h>
#include <spline3interp.h>


using namespace std;
using namespace itlab;


int main()
{
    // f(x) = 1 / (1+25*x^2)   -1 <= x <= 1
    float xi[11] = { -1.0,   -0.8,   -0.6, -0.4, -0.2, 0.0, 0.2, 0.4, 0.6, 0.8,   1.0 };
    float yi[11] = { 0.0385, 0.0588, 0.1,  0.2,  0.5,  1.0, 0.5, 0.2, 0.1, 0.0588, 0.0385 };
    float Ml = 0.2105, Mr = 0.2105;
    Vector<float> x( 11, xi ), y( 11, yi );

    Spline3Interp<float> poly( x, y, Ml, Mr );
    poly.calcCoefs();

    cout << "Coefficients of cubic spline interpolated polynomial:" << endl
         << poly.getCoefs() << endl;

    cout << "The true and interpolated values:" << endl;
    cout << "0.0755" << "   " << poly.evaluate(-0.7) << endl
         << "0.3077" << "   " << poly.evaluate(0.3) << endl
         << "0.0471" << "   " << poly.evaluate(0.9) << endl << endl;

    return 0;
}
