/*****************************************************************************
 *                               svd_test.cpp
 *
 * SVD class testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <svd.h>


using namespace std;
using namespace itlab;


int main()
{
//    Matrix<double> A(4,4);
//	A(1,1) = 16;    A(1,2) = 2;     A(1,3) = 3;     A(1,4) = 13;
//	A(2,1) = 5;     A(2,2) = 11;    A(2,3) = 10;    A(2,4) = 8;
//	A(3,1) = 9;     A(3,2) = 7;     A(3,3) = 6;     A(3,4) = 12;
//	A(4,1) = 4;     A(4,2) = 14;    A(4,3) = 15;    A(4,4) = 1;

//    Matrix<double> A(4,2);
//	A(1,1) = 1;     A(1,2) = 2;
//	A(2,1) = 3;     A(2,2) = 4;
//	A(3,1) = 5;     A(3,2) = 6;
//	A(4,1) = 7;     A(4,2) = 8;

    Matrix<double> A(2,4);
	A(1,1) = 1;     A(1,2) = 3;     A(1,3) = 5;     A(1,4) = 7;
	A(2,1) = 2;     A(2,2) = 4;     A(2,3) = 6;     A(2,4) = 8;

	SVD<double> svd;
	svd.dec(A);

	Matrix<double> U = svd.getU();
	Matrix<double> V = svd.getV();
	Matrix<double> S = svd.getSM();

	cout << "The original matrix A : " << A << endl;
	cout << "The left singular vectors U : " << U << endl;
	cout << "The singular values S : " << S << endl;
	cout << "The right singular vectors V : " << V << endl;
	Matrix<double> A1 = prod( U, prod(S,transpose(V)) );
	cout << "The norm of error matrix between A and U * S * V' : "
	     << norm( A - A1 ) << endl << endl;

	cout << "The rank of A : " << svd.rank() << endl << endl;
	cout << "The condition number of A : " << svd.cond() << endl << endl;

	return 0;
}
