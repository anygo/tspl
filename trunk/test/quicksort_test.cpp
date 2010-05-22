/*****************************************************************************
 *                               quicksort_test.cpp
 *
 * Quick sorting testing.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#include <iostream>
#include <random.h>
#include <quicksort.h>


using namespace std;
using namespace itlab;


const int SIZE1 = 10;
const int SIZE2 = 100;


template <typename Type>
void printVector( const vector<Type> &a )
{
    vector<int>::const_iterator itr = a.begin();
    while( itr != a.end() )
        cout << *itr++ << "\t";

    cout << endl << endl;
}


int main()
{
    vector<int> a( SIZE1 );
    Random r(1);

    cout << "\t\t\t\tUnsorted Numbers : " << endl << endl;
    for( unsigned i=0; i<a.size(); ++i )
        a[i] = r.random( 1, 10*SIZE1 );
    printVector( a );

    cout << "\t\t\t\tSorted Numbers : " << endl << endl;
    quickSort( a, 0, a.size()-1 );
    printVector( a );

    a.resize( SIZE2 );
    r.seed( 127 );

    cout << "\t\t\t\tUnsorted Numbers : " << endl << endl;
    for( unsigned i=0; i<a.size(); ++i )
        a[i] = r.random( 1, 10*SIZE2 );
    printVector( a );

    cout << "\t\t\t\tSorted Numbers : " << endl << endl;
    quickSort( a, 0, a.size()-1 );
    printVector( a );

    return 0;
}
