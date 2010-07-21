/*****************************************************************************
 *                                sort_test.cpp
 *
 * Sorting algorithm testing.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#include <iostream>
#include <random.h>
#include <sort.h>


using namespace std;
using namespace itlab;


const int SIZE = 10;


template <typename Type>
void printVector( const vector<Type> &a )
{
    vector<int>::const_iterator itr = a.begin();
    while( itr != a.end() )
        cout << *itr++ << "\t";

    cout << endl;
}


int main()
{
    vector<int> a( SIZE );

    cout << "Unsorted Numbers : " << endl;
    Random r(127);
    for( unsigned i=0; i<a.size(); ++i )
        a[i] = r.random( 1, 10*SIZE );
    printVector( a );
    cout << "Bubble Sorted Numbers : " << endl;
    bubbleSort( a, 0, a.size()-1 );
    printVector( a );
    cout << endl;

    cout << "Unsorted Numbers : " << endl;
    for( unsigned i=0; i<a.size(); ++i )
        a[i] = r.random( 1, 10*SIZE );
    printVector( a );
    cout << "Select Sorted Numbers : " << endl;
    selectSort( a, 0, a.size()-1 );
    printVector( a );
    cout << endl;

    cout << "Unsorted Numbers : " << endl;
    for( unsigned i=0; i<a.size(); ++i )
        a[i] = r.random( 1, 10*SIZE );
    printVector( a );
    cout << "Insert Sorted Numbers : " << endl;
    insertSort( a, 0, a.size()-1 );
    printVector( a );
    cout << endl;

    cout << "Unsorted Numbers : " << endl;
    for( unsigned i=0; i<a.size(); ++i )
        a[i] = r.random( 1, 10*SIZE );
    printVector( a );
    cout << "Quick Sorted Numbers : " << endl;
    quickSort( a, 0, a.size()-1 );
    printVector( a );
    cout << endl;

    cout << "Unsorted Numbers : " << endl;
    for( unsigned i=0; i<a.size(); ++i )
        a[i] = r.random( 1, 10*SIZE );
    printVector( a );
    cout << "Merg Sorted Numbers : " << endl;
    mergSort( a, 0, a.size()-1 );
    printVector( a );
    cout << endl;

    cout << "Unsorted Numbers : " << endl;
    for( unsigned i=0; i<a.size(); ++i )
        a[i] = r.random( 1, 10*SIZE );
    printVector( a );
    cout << "Heap Sorted Numbers : " << endl;
    heapSort( a, 0, a.size()-1 );
    printVector( a );
    cout << endl;

    return 0;
}
