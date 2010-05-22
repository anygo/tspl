/*****************************************************************************
 *                               mathfunc_test.cpp
 *
 * Math functions for vector and matrix testing.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <utilities.h>
#include <mathfun.h>


using namespace std;
using namespace itlab;


int main()
{

	int     N = 11;
	float   a = 0,
            b = 2*PI;
	Vector<float> x = linspace( a, b, N );
	cout << x << endl;

	cout << "Sine function of x : " << vsin(x) << endl;
	cout << "Cosine function of x : "<< vcos(x) << endl;
	cout << "Exponential function of x : " << vexp(x) << endl;
	a = 2.0;
	cout << "Power function of x : " << vpow(x,a) << endl;

    Vector< complex<float> > vc(N);
    for( int i=0; i<N; ++i )
        vc[i] = complex<float>( sin(x[i]), cos(x[i]) );
    cout << "Complex vector vc : " << vc << endl;
    cout << "Real part of vc : " << vreal(vc) << endl;
    cout << "Imaginary part of vc : " << vimag(vc) << endl;
    cout << "Absolute part of vc : " << vabs(vc) << endl;

    N = 21;
	a = -5;
	b = 5;
	x = linspace( a, b, N );
	cout << "Absolute function of x : " << vabs( x ) << endl;
	a = 0.0;
	b = 1.0;
	cout << "The standard normal distribution : "
	     << gauss( x, a, b ) << endl;

	return 0;
}
