/*****************************************************************************
 *                               qrd_test.cpp
 *
 * QRD class testing.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <qrd.h>


using namespace std;
using namespace itlab;


const int M = 4;
const int N = 3;


int main()
{
	Matrix<double> A(M,N);
	A[0][0] = 1;	A[0][1] = 0;	A[0][2] = 0;
	A[1][0] = 1;	A[1][1] = 2;	A[1][2] = 4;
	A[2][0] = 1;	A[2][1] = 3;	A[2][2] = 9;
	A[3][0] = 1;	A[3][1] = 3;	A[3][2] = 9;

	Matrix<double> B(M,M);
	B[0][0] = 1;	B[0][1] = 0;	B[0][2] = 0;    B[0][3] = 0;
	B[1][0] = 0;	B[1][1] = 1;	B[1][2] = 0;    B[1][3] = 0;
	B[2][0] = 0;	B[2][1] = 0;	B[2][2] = 1;    B[2][3] = 0;
	B[3][0] = 0;	B[3][1] = 0;	B[3][2] = 0;    B[3][3] = 1;

	Vector<double> b(M);
	b[0]= 1;	b[1] = 0;	b[2] = 1, b[3] = 2;

    Matrix<double> Q, R;
	QRD<double> qr;
	qr.dec(A);
	qr.getQ(Q);
	qr.getR(R);

	cout << "The original matrix A : " << A << endl;
	cout << "The orthogonal matrix Q  : " << Q << endl;
	cout << "The upper triangular matrix R : " << R << endl;

	Vector<double> x = qr.solve(b);
	cout << "The constant vector b : " << b << endl;
	cout << "The least squares solution of A * x = b : " << x << endl;

	Matrix<double> X = qr.solve(B);
	cout << "The constant matrix B : " << B << endl;
	cout << "The least squares solution of A * X = B : " << X << endl;

	return 0;
}
