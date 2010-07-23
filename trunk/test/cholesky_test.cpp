/*****************************************************************************
 *                               cholesky_test.cpp
 *
 * Cholesky class testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <cholesky.h>


using namespace std;
using namespace itlab;


const int N = 5;


int main()
{
	Matrix<double> A(N,N), L(N,N), B(N,N);
	Vector<double> b(N);

	for( int i=1; i<N+1; ++i )
	{
		for( int j=1; j<N+1; ++j )
			if( i == j )
			{
				A(i,i) = i;
				B(i,i) = 1;
			}
			else
			{
				if( i < j )
					A(i,j) = i;
				else
					A(i,j) = j;

				B(i,j) = 0;
			}

		b(i) = i*(i+1)/2 + i*(N-i);
	}

	Cholesky<double> cho;
    cho.dec(A);
	if( cho.isSpd() )
		L = cho.getL();
	else
		cout << "Factorization was not complete." << endl;

	cout << "The original matrix A : " << A << endl;
	cout << "The lower triangular matrix L is : " << L << endl;

	Vector<double> x = cho.solve(b);
	cout << "The constant vector b : " << b << endl;
	cout << "The solution of Ax = b : " << x << endl;

	Matrix<double> C = cho.solve(B);
	cout << "The invse matrix of A : " << C << endl;

	return 0;
}
