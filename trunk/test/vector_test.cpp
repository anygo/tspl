/*****************************************************************************
 *                               vector_test.cpp
 *
 * Vector class testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <complex>
#include <iostream>
#include <vector.h>


using namespace std;
using namespace itlab;


const int M = 3;


void display( const int *p, int length )
{
	for( int i=0; i<length; ++i )
		cout << p[i] << "\t" ;
	cout << endl;
}


int main()
{
	int k;
	int arrays[3] = {1,2,3};

	Vector<int> v1( M,arrays );
	k = 1;
	Vector<int> v2( M,k );

	Vector<int> v3( M );
	k = 0;
	v3 = k;

	Vector<int> v4( v1 );

	cout << "vector v1 : " << v1 << endl;
	cout << "vector v2 : " << v2 << endl;
	cout << "vector v3 : " << v3 << endl;
	cout << "vector v4 : " << v4 << endl;

	display( v4, M );
	cout << endl;

	v4.resize( 5 );
	Vector<int>::iterator itr = v4.begin();
	while( itr != v4.end() )
        *itr++ = 1;
	cout << "new vector v4 : " << v4 << endl;
	v4 = v1;
	cout << "new vector v4 : " << v4 << endl;

	k = 2;
	v3 = k+v1;
	cout << "v3 = k + v1 : " << v3 << endl;
	v3 += k;
	cout << "v3 += k : " << v3 << endl;

    v3 = v1-k;
	cout << "v3 = v1 - k : " << v3 << endl;
	v3 = k-v1;
	cout << "v3 = k - v1 : " << v3 << endl;
	v3 -= k;
	cout << "v3 -= k : " << v3 << endl;

	v3 = k*v1;
	cout << "v3 = k * v1 : " << v3 << endl;
	v3 *= k;
	cout << "v3 *= k : " << v3 << endl;

	v3 = v1/k;
	cout << "v3 = v1 / k : " << v3 << endl;
	v3 = k/v1;
	cout << "v3 = k / v1 : " << v3 << endl;
	v3 /= k;
	cout << "v3 /= k : " << v3 << endl;

    v3 = v1+v2;
	cout << "v3 = v1 + v2 : " << v3 << endl;
	v3 += v1;
	cout << "v3 += v1 : " << v3 << endl;

	v3 = v1-v2;
	cout << "v3 = v1 - v2 : " << v3 << endl;
	v3 -= v1;
	cout << "v3 -= v1 : " << v3 << endl;

	v3 = v1*v2;
	cout << "v3 = v1 * v2 : " << v3 << endl;
	v3 *= v1;
	cout << "v3 *= v1 : " << v3 << endl;

	v3 = v1/v2;
	cout << "v3 = v1 / v2 : " << v3 << endl;
	v3 /= v1;
	cout << "v3 /= v1 : " << v3 << endl;

	k = dotProd( v1, v2 );
	cout << "inner product of v1 and v2 : " << endl;
	cout << k << endl << endl;

	cout << "L2 norm of v3 : ";
	cout << norm( v3 ) << endl << endl;

	complex<double> z = -1.0;
	Vector< complex<double> > v( M );
	v[0] = polar( 1.0,PI/4 );
	v[1] = polar( 1.0,PI );
	v[2] = complex<double>( 1.0,-1.0 );
	Vector< complex<double> > u = v*z;

	cout << "complex vector v : " << v << endl;
	cout << "complex vector u = -v : " << u << endl;

	Vector< Vector<double> > v2d1( M );
	for( int i=0; i<M; ++i )
	{
		v2d1[i].resize( M );
		for( int j=0; j<M; ++j )
			v2d1[i][j] = double( i+j );
	}

	cout << "two dimention vector v2d1 : " << endl;
	Vector< Vector<double> >::const_iterator itrD2 = v2d1.begin();
	int rowNum = 0;
	while( itrD2 != v2d1.end() )
	    cout << "the " << rowNum++ << "th row : " << *itrD2++ << endl;

	Vector< Vector<double> > v2d2 = v2d1+v2d1;
	cout << "two dimention vector v2d2 = v2d1 + v2d1 : " << v2d2 << endl;

	return 0;
}
