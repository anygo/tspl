/*****************************************************************************
 *                             vectormath_test.cpp
 *
 * Math functions of matrix testing.
 *
 * Zhang Ming, 2010-08, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <utilities.h>
#include <matrixmath.h>


using namespace std;
using namespace itlab;


int main()
{
    int N = 9;
	double  a = 0, b = 2*PI;
	Vector<double> array = linspace( a, b, N );

	Matrix<double> x( 3, 3, array );
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

    Vector< complex<double> > carray(N);
    for( int i=0; i<N; ++i )
        carray[i] = complex<float>( sin(array[i]), cos(array[i]) );

    Matrix< complex<double> > cm( 3, 3, carray );
    cout << "Complex vector cm : " << cm << endl;
    cout << "Absolute of cm : " << abs(cm) << endl;
    cout << "Angle of cm : " << arg(cm) << endl;
    cout << "Real part of cm : " << real(cm) << endl;
    cout << "Imaginary part of cm : " << imag(cm) << endl;

	return 0;
}
