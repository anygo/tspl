/*****************************************************************************
 *                            matrixinverse_test.cpp
 *
 * Matrix inverse testing.
 *
 * Zhang Ming, 2010-08, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <matrixinverse.h>


using namespace std;
using namespace itlab;


int main()
{
	Matrix<double> A, invA;
	A.resize(3,3);
	A[0][0] = 1;	A[0][1] = 2;	A[0][2] = 1;
	A[1][0] = 2;	A[1][1] = 5;	A[1][2] = 4;
	A[2][0] = 1;	A[2][1] = 1;	A[2][2] = 0;
	cout << "The original matrix A is : " << A << endl;
	invA = inv(A);
	cout << "The invse matrix of A (LUD based) : " << invA << endl;
    invA = colPivInv(A);
    cout << "The invse matrix of A (column pivot Based) : " << invA << endl;
    invA = cmpPivInv(A);
    cout << "The invse matrix of A (complete pivot Based) : " << invA << endl;
    cout << "The product of A and its inverse: " << prod(A,invA) << endl << endl;

	A.resize( 5, 5 );
    for( int i=1; i<6; ++i )
	{
		for( int j=1; j<6; ++j )
			if( i == j )
				A(i,i) = i;
			else if( i < j )
                A(i,j) = i;
            else
                A(i,j) = j;
	}
	cout << "The original matrix A is : " << A << endl;
	invA = inv(A,"sys");
    cout << "The invse matrix of A (LUD based) : " << invA << endl;
    invA = colPivInv(A);
    cout << "The invse matrix of A (column pivot Based) : " << invA << endl;
    invA = cmpPivInv(A);
    cout << "The invse matrix of A (complete pivot Based) : " << invA << endl;
    cout << "The product of A and its inverse: " << prod(A,invA) << endl << endl;

    A.resize( 8, 6 );
    A[0][0]=64; A[0][1]=2;  A[0][2]=3;  A[0][3]=61; A[0][4]=60; A[0][5]=6;
    A[1][0]=9;  A[1][1]=55; A[1][2]=54; A[1][3]=12; A[1][4]=13; A[1][5]=51;
    A[2][0]=17; A[2][1]=47; A[2][2]=46; A[2][3]=20; A[2][4]=21; A[2][5]=43;
    A[3][0]=40; A[3][1]=26; A[3][2]=27; A[3][3]=37; A[3][4]=36; A[3][5]=30;
    A[4][0]=32; A[4][1]=34; A[4][2]=35; A[4][3]=29; A[4][4]=28; A[4][5]=38;
    A[5][0]=41; A[5][1]=23; A[5][2]=22; A[5][3]=44; A[5][4]=45; A[5][5]=19;
    A[6][0]=49; A[6][1]=15; A[6][2]=14; A[6][3]=52; A[6][4]=53; A[6][5]=11;
    A[7][0]=8;  A[7][1]=58; A[7][2]=59; A[7][3]=5;  A[7][4]=4;  A[7][5]=62;
	invA = pinv(A);
	cout << "The original matrix A is : " << A << endl;
    cout << "The pseudoinvse matrix of A : " << invA << endl;
    cout << "The product of A and its inverse: " << prod(A,invA) << endl;

	return 0;
}
