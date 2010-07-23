/*****************************************************************************
 *                               lud_test.cpp
 *
 * LUD class testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <lud.h>


using namespace std;
using namespace itlab;


const int M = 3;
const int N = 3;


int main()
{
	Matrix<double> A(M,N), B(M,N);
	Vector<double> b(N);

	A[0][0] = 1;	A[0][1] = 2;	A[0][2] = 1;
	A[1][0] = 2;	A[1][1] = 5;	A[1][2] = 4;
	A[2][0] = 1;	A[2][1] = 1;	A[2][2] = 0;

	B[0][0] = 1;	B[0][1] = 0;	B[0][2] = 0;
	B[1][0] = 0;	B[1][1] = 1;	B[1][2] = 0;
	B[2][0] = 0;	B[2][1] = 0;	B[2][2] = 1;

	b[0] = 1;	b[1] = 0;	b[2] = 1;

	LUD<double> lu;
	lu.dec(A);

	Matrix<double> L, U;
	lu.getL(L);
	lu.getU(U);

	cout << "The original matrix A is : " << A << endl;
	cout << "The unit lower triangular matrix L is : " << L << endl;
	cout << "The upper triangular matrix U is : " << U << endl;

	Vector<double> x = lu.solve(b);
	cout << "The constant vector b : " << b << endl;
	cout << "The solution of A * x = b : " << x << endl;

	cout << "The invse matrix of A : " << lu.solve(B) << endl;
	cout << "The determinant of A : " << endl;
	cout << lu.det() << endl << endl;

	return 0;
}
