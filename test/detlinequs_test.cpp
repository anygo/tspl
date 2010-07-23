/*****************************************************************************
 *                           linearequations_test.cpp
 *
 * Deterministic Linear Equations testing.
 *
 * Zhang Ming, 2010-07, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <detlinequs.h>


using namespace std;
using namespace itlab;


const int M = 3;
const int N = 3;


int main()
{
	Matrix<double> A(M,N), B(M,N);
	Vector<double> b(N);

    // ordinary linear equations
	A[0][0] = 1;	A[0][1] = 2;	A[0][2] = 1;
	A[1][0] = 2;	A[1][1] = 5;	A[1][2] = 4;
	A[2][0] = 1;	A[2][1] = 1;	A[2][2] = 0;
	B = eye( 3, 1.0 );
	b[0] = 1;	b[1] = 0;	b[2] = 1;
    Matrix<double> invA( A );
    Matrix<double> X( B );
    cout << "The original matrix A is : " << A << endl;
	gaussSolver( invA, X );
	cout << "The inverse of A is ( Gauss Solver ) : " << invA << endl;
    cout << "The invse matrix of A is ( LUD Solver ) : " << luSolver( A, B ) << endl;
    cout << "The constant vector b : " << b << endl;
	cout << "The solution of A * x = b is ( Gauss Solver ) : " << gaussSolver( A, b ) << endl;
	cout << "The solution of A * x = b is ( LUD Solver ) : " << luSolver( A, b ) << endl << endl;

    // linear equations with symmetric coefficient matrix
	for( int i=1; i<N+1; ++i )
	{
		for( int j=1; j<N+1; ++j )
			if( i == j )
				A(i,i) = i;
			else
				if( i < j )
					A(i,j) = i;
				else
					A(i,j) = j;
		b(i) = i*(i+1)/2 + i*(N-i);
	}
	cout << "The original matrix A : " << A << endl;
	cout << "The invse matrix of A is ( Cholesky Solver ) : " << choleskySolver( A, B ) << endl;
	cout << "The constant vector b : " << b << endl;
	cout << "The solution of Ax = b is ( Cholesky Solver ) : " << choleskySolver( A, b ) << endl << endl;

	// Tridiagonal linear equations
	Vector<double> aa( 3, -1 ),
                   bb( 4, 4 ),
                   cc( 3, -2 ),
                   dd( 4 );
    dd(1) = 3;   dd(2) = 2;   dd(3) = 2;   dd(4) = 3;
    cout << "The elements below main diagonal is : " << aa << endl;
    cout << "The elements on main diagonal is : " << bb << endl;
    cout << "The elements above main diagonal is : " << cc << endl;
    cout << "The elements constant vector is : " << dd << endl;
    cout << "Teh solution is (Forward Elimination and Backward Substitution) : "
         << febsSolver( aa, bb, cc, dd ) << endl << endl;

	return 0;
}
