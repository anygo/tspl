/*****************************************************************************
 *                           linearequations_test.cpp
 *
 * Undetermined Linear Equations testing.
 *
 * Zhang Ming, 2010-07, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <undetlinequs.h>


using namespace std;
using namespace itlab;


const int M = 3;
const int N = 3;


int main()
{
	Matrix<double> A(M,N), B(M,N);
	Vector<double> b(N);

    // overdetermined linear equations
    A.resize( 4, 3 );
	A[0][0] = 1;	A[0][1] = -1;	A[0][2] = 1;
	A[1][0] = 1;	A[1][1] = 2;	A[1][2] = 4;
	A[2][0] = 1;	A[2][1] = 3;	A[2][2] = 9;
	A[3][0] = 1;	A[3][1] = -4;	A[3][2] = 16;
	b.resize( 4 );
	b[0]= 1;    b[1] = 2;   b[2] = 3;   b[3] = 4;
    cout << "The original matrix A : " << A << endl;
    cout << "The constant vector b : " << b << endl;
	cout << "The least square solution is( using generalized inverse ) : " << lsSolver( A, b ) << endl;
    cout << "The least square solution is( using QR decomposition ) : " << qrlsSolver( A, b ) << endl;

    // undetermined linear equations
    Matrix<double> At( transpose( A ) );
	b.resize( 3 );
	b[0]= 1;	b[1] = 2;   b[2]= 3;
	cout << "The original matrix A : " << At << endl;
    cout << "The constant vector b : " << b << endl;
	cout << "The least norm solution is( using generalized inverse ) : " << lnSolver( At, b ) << endl;
	cout << "The least norm solution is( using QR decomposition ) : " << qrlnSolver( At, b ) << endl;

	return 0;
}
