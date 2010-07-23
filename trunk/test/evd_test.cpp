/*****************************************************************************
 *                               evd_test.cpp
 *
 * EVD class testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <evd.h>


using namespace std;
using namespace itlab;


const int N = 4;


int main()
{
	Matrix<double> A(N,N);

	A[0][0] = 3.0;	A[0][1] = -2.0;	A[0][2] = -0.9;     A[0][3] = 0.0;
	A[1][0] = -2.0;	A[1][1] = 4.0;	A[1][2] = 1.0;      A[1][3] = 0.0;
	A[2][0] = 0.0;	A[2][1] = 0.0;	A[2][2] = -1.0;     A[2][3] = 0.0;
	A[3][0] = -0.5;	A[3][1] = -0.5;	A[3][2] = 0.1;      A[3][3] = 1.0;

	EVD<double> eig;
	eig.dec(A);

	Matrix<double> D = eig.getD();
	Matrix<double> V = eig.getV();

	cout << "The original matrix A : " << A << endl;
	cout << "The eigenvalue matrix D : " << D << endl;
	cout << "The eigenvectors V : " << V << endl;
	cout << "THe real part of the eigenvalues Dr: "
	     << eig.getRealEigenvalues() << endl;
	cout << "The imaginary part of the eigenvalues Di: "
	     << eig.getImagEigenvalues() << endl;
	cout << "The norm of error matrix between A * V and V * D : "
	     << norm( prod(A,V)-prod(V,D) ) << endl << endl;

	return 0;
}
