/*****************************************************************************
 *                               newtoninterp_test.cpp
 *
 * Newton interpolation testing.
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <newtoninterp.h>


using namespace std;
using namespace itlab;


int main()
{
    Vector<double> x(5),
                   y(5);
    x[0] = 0; x[1] = 30;  x[2] = 45;        x[3] = 60;        x[4] = 90;
    y[0] = 0; y[1] = 0.5; y[2] = sqrt(2.0)/2; y[3] = sqrt(3.0)/2; y[4] = 1;

    NewtonInterp<double> poly(x,y);
    poly.calcCoefs();

    cout << "Coefficients of Newton interpolated polynomial:"
         << poly.getCoefs() << endl;

    cout << "The true and interpolated values:" << endl;
    cout << sin(10*D2R) << "   " << poly.evaluate(10) << endl
         << sin(20*D2R) << "   " << poly.evaluate(20) << endl
         << sin(50*D2R) << "   " << poly.evaluate(50) << endl << endl;

    return 0;
}
