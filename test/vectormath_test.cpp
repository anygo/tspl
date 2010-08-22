/*****************************************************************************
 *                             vectormath_test.cpp
 *
 * Math functions of vector testing.
 *
 * Zhang Ming, 2010-08, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <utilities.h>
#include <vectormath.h>


using namespace std;
using namespace itlab;


int main()
{

	int     N = 5;
	double  a = 0,
            b = 2*PI;
	Vector<double> x = linspace( a, b, N );
	cout << x << endl;

	cout << "sin of x : " << sin(x) << endl;
	cout << "cos of x : "<< cos(x) << endl;
	cout << "tan of x : " << tan(x) << endl;
	cout << "asin of x : "<< asin(x) << endl;
	cout << "acos of x : " << acos(x) << endl;
	cout << "atan of x : " << atan(x) << endl;

	cout << "exp of x : "<< exp(x) << endl;
	cout << "log of x : " << log(x) << endl;
	cout << "log10 of x : " << log10(x) << endl;

    a = 2.0;
	cout << "sqrt of x : "<< sqrt(x) << endl;
	cout << "pow of x : " << pow(x,x) << endl;
	cout << "pow of x : " << pow(x,a) << endl;
	cout << "pow of x : " << pow(a,x) << endl;

	cout << "The standard normal distribution : " << gauss( x, a, b ) << endl;

    Vector< complex<float> > cv(N);
    for( int i=0; i<N; ++i )
        cv[i] = complex<float>( sin(x[i]), cos(x[i]) );
    cout << "Complex vector vc : " << cv << endl;
    cout << "Absolute of vc : " << abs(cv) << endl;
    cout << "Angle of vc : " << arg(cv) << endl;
    cout << "Real part of vc : " << real(cv) << endl;
    cout << "Imaginary part of vc : " << imag(cv) << endl;

	return 0;
}
