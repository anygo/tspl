/*****************************************************************************
 *                               utilities_test.cpp
 *
 * Utilities class testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <string>
#include <utilities.h>


using namespace std;
using namespace itlab;


const int N = 5;


int main()
{

	Vector<int> v1(N);
	for( int i=1; i<=v1.dim(); i++ )
		v1(i) = i;
	cout << "vector v1 : " << v1 << endl;

	Vector<int> v2(N);
	for( int i=1; i<=v2.dim(); ++i )
		v2(i) = i+N;
	cout << "vector v2 : " << v2 << endl;

	int N = 11;
	double a = 0;
	double b = 1.0;
	Vector<double> x = linspace( a, b, N );
	cout << N << " points linearly spaced from 0 to 1.0"
	     << x << endl;

	cout << "Flipping vector v1 from left to right : " << flip(v1) << endl;
	cout << "Dyadic upsampling of vector v1 by zeros at the even position : "
		 << dyadUp( v1,0 ) << endl;
	cout << "Dyadic upsampling of vector v1 by zeros at the odd position : "
		 << dyadUp( v1,1 ) << endl;
	cout << "Dyadic downsampling of vector v1 by zeros at the even position : "
		 << dyadDown( v1,0 ) << endl;
	cout << "Dyadic downsampling of vector v1 by zeros at the odd position : "
		 << dyadDown( v1,1 ) << endl;

	int n = 2;
	string dire = "left";
	string mode = "zpd";
	cout << "Extending vector v1 in left dirction by zeros padding : "
		 << wextend( v1,n,dire,mode ) << endl;
	mode = "ppd";
	cout << "Extending vector v1 in left dirction by periodic mode : "
		 << wextend( v1,n,dire,mode ) << endl;
	mode = "sym";
	cout << "Extending vector v1 in left dirction by symetric mode : "
		 << wextend( v1,n,dire,mode ) << endl;

	dire = "right";
	mode = "zpd";
	cout << "Extending vector v1 in right dirction by zeros padding : "
		 << wextend( v1,n,dire,mode ) << endl;
	mode = "ppd";
	cout << "Extending vector v1 in right dirction by periodic mode : "
		 << wextend( v1,n,dire,mode ) << endl;
	mode = "sym";
	cout << "Extending vector v1 in right dirction by symetric mode : "
		 << wextend( v1,n,dire,mode ) << endl;

	dire = "both";
	mode = "zpd";
	cout << "Extending vector v1 in both dirction by zeros padding : "
		 << wextend( v1,n,dire,mode ) << endl;
	mode = "ppd";
	cout << "Extending vector v1 in both dirction by periodic mode : "
		 << wextend( v1,n,dire,mode ) << endl;
	mode = "sym";
	cout << "Extending vector v1 in both dirction by symetric mode : "
		 << wextend( v1,n,dire,mode ) << endl;

	cout << "Keeping the center part of vector v1 : " << wkeep( v1,3,"center" ) << endl;
	cout << "Keeping the left part of vector v1 : " << wkeep( v1,3,"left" ) << endl;
	cout << "Keeping the right part of vector v1 : " << wkeep( v1,3,"right" ) << endl;
	cout << "Keeping the first(2) to first + L(3) elements of vector v1 : "
		 << wkeep( v1,3,2 ) << endl;

	cout << "The convolution of vector v1 and v2 : " << conv( v1,v2 ) << endl;

	cout << "The modulus of 2 divided by 5 is " << mod(2,5) << "." << endl;
	cout << "The modulus of -1 divided by 5 is " << mod(-1,5) << "." << endl;
	cout << endl;
	cout << "The nearest integer >= 10/2 is " << ceil(10,2) << "." << endl;
	cout << "The nearest integer >= 10/3 is " << ceil(10,3) << "." << endl;

	cout << endl;
	cout << "The numbers can be represented by the integer power of 2 "
		 << "from 0 to 1000 are : " << endl;
	for( int i=0; i<1000; ++i )
		if( isPower2(i) )
			cout << fastLog2(i) << " = log2(" << i << ")" << endl;

	return 0;
}
