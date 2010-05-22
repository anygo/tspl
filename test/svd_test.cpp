/*****************************************************************************
 *                               svd_test.cpp
 *
 * SVD class testing.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <svd.h>


using namespace std;
using namespace itlab;


const int M = 4;
const int N = 2;


int main()
{
	Matrix<double> A(M,N);
	A(1,1) = 1;     A(1,2) = 2;
	A(2,1) = 3;     A(2,2) = 4;
	A(3,1) = 5;     A(3,2) = 6;
	A(4,1) = 7;     A(4,2) = 8;

	SVD<double> svd;
	svd.dec(A);

	Matrix<double> U = svd.getU();
	Matrix<double> V = svd.getV();
	Vector<double> s = svd.getS();

	Matrix<double> S(N,N);
	S = 0;
	for( int i=0; i<N; ++i )
		S[i][i] = s[i];

	cout << "The original matrix A : " << A << endl;
	cout << "The left singular vectors U : " << U << endl;
	cout << "The right singular vectors V : " << V << endl;
	cout << "The singular values S : " << S << endl;
	Matrix<double> A1 = prod( U, prod(S,transpose(V)) );
	cout << "The norm of error matrix between A and U * S * V' : "
	     << norm( A - A1 ) << endl << endl;

	cout << "The rank of A : " << svd.rank() << endl << endl;
	cout << "The condition number of A : " << svd.cond() << endl << endl;

	return 0;
}
