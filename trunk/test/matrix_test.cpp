/*****************************************************************************
 *                               matrix_test.cpp
 *
 * Matrix class testing.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <matrix.h>


using namespace std;
using namespace itlab;


const int M = 3;
const int N = 3;


int main()
{
	double x;

	Matrix<double> m1;
	m1.resize( M, N );
	x = 1.0;
	m1 = x;
	cout << "matrix m1 : " << m1 << endl;

	x = 2.0;
	Matrix<double> m2( M, N, x );
	cout << "matrix m2 : " << m2 << endl;

	Matrix<double> m3 = m1;
	cout << "matrix m3 : " << m3 << endl;
	m3.resize( 3, 4 );
	for( int i=1; i<=3; ++i )
		for( int j=1; j<=4; ++j )
			m3(i,j) = double(i*j);

	int row = m3.dim(1);
	int column = m3.dim(2);
	cout << "the row number of new matrix m3 : " << row << endl;
	cout << "the column number of new matrix m3 : " << column << endl;
	cout << "new matrix m3 : " << m3 << endl;

	cout << "the diagonal matrix of m3 : " << diag( m3 ) << endl;
	cout << "the transpose matrix of m3 : " << transpose( m3 ) << endl;

    cout << endl << endl << "\t\t\t\tmatrix-scalar operand" << endl << endl;
	cout << "scalar x = " << x << endl;
	cout << "m1 + x : " << m1+x << endl;
	cout << "x + m1 : " << x+m1 << endl;
	m1 += x;
	cout << "m1 += x : " << m1 << endl;
	cout << "m1 - x : " << m1-x << endl;
	cout << "x - m1 : " << x-m1 << endl;
	m1 -= x;
	cout << "m1 -= x : " << m1 << endl;
	cout << "m1 * x : " << m1*x << endl;
	cout << "x * m1 : " << x*m1 << endl;
	m1 *= x;
	cout << "m1 *= x : " << m1 << endl;
	cout << "m1 / x : " << m1/x << endl;
	cout << "x / m1 : " << x/m1 << endl;
	m1 /= x;
	cout << "m1 /= x : " << m1 << endl;

    cout << endl << endl << "\t\t\t\telementwise matrix-matrix operand" << endl << endl;
	cout << "m1 + m2 : " << m1 + m2 << endl;
	m1 += m2;
	cout << "m1 += m2 : " << m1 << endl;
	cout << "m1 - m2 : " << m1-m2 << endl;
	m1 -= m2;
	cout << "m1 -= m2 : " << m1 << endl;
	cout << "m1 * m2 : " << m1*m2 << endl;
	m1 *= m2;
	cout << "m1 *= m2 : " << m1 << endl;
	cout << "m1 / m2 : " << m1/m2 << endl;
	m1 /= m2;
	cout << "m1 /= m2 : " << m1 << endl;

	cout << endl << endl << "\t\t\t\tmatrix-matrix operand" << endl << endl;
	cout << "m1 * m2 : " << prod(m1, m2) << endl;
	cout << "m1' * m2 : " << tranProd(m1, m2) << endl;

    cout << endl << endl << "\t\t\t\tmatrix-vector operand" << endl << endl;
    Vector<double> v1( 3, 2 );
	cout << "vector v1 : " << v1 << endl;
	cout << "m1 * v1 : " << prod(m1, v1) << endl;
	cout << "m1' * v1 : " << tranProd(m1, v1) << endl;

	cout << "Please input a sqare matrix mtr." << endl;
	Matrix<double> mtr;
	cin >> mtr;
	cout << "the inverse matrix of mtr : " << inverse( mtr ) << endl;

	Matrix<int> m4( 4, 5 );
	Vector<int> v2(5);
	v2[0] = 1;  v2[1] = 2;  v2[2] = 3;  v2[3] = 4;  v2[4] = 5;
	for( int i=1; i<=4; ++i )
		m4.setRow( i*v2, i );

	cout << "matrix m4 : " << m4 << endl;
	cout << "column vectors of m4 : " << endl;
	for( int j=1; j<=5; ++j )
		cout << "the " << j << "th column" << m4.getColumn(j) << endl;

    v2.resize(4);
	v2[0] = 1;  v2[1] = 2;  v2[2] = 3;  v2[3] = 4;
	for( int j=1; j<=5; ++j )
		m4.setColumn( j*v2, j );

	cout << "row vectors of m4 : " << endl;
	for( int i=1; i<=4; ++i )
		cout << "the " << i << "th row" << m4.getRow(i) << endl;

	return 0;
}
