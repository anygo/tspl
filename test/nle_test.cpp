/*****************************************************************************
 *                               nle_test.cpp
 *
 * Rooting of nonlinear equation testing.
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


#include <iostream>
#include <funcroot.h>


using namespace std;
using namespace itlab;


int main()
{
    double x01, x02, x03;
    NLFunc<double> f( 1.0, -3.0, 1.0 );
	FuncRoot<double> fr;

    x01 = fr.bisection( f, 0.0, 2.0, 1.0e-6 );
	cout << x01 << endl <<endl;

	x02 = fr.newton( f, 0.0, 1.0e-6, 100 );
	cout << x02 << endl <<endl;

	x03 = fr.secant( f, 1.0, 3.0, 1.0e-6, 100 );
	cout << x03 << endl <<endl;

	return 0;
}
