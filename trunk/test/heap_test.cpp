/*****************************************************************************
 *                               heap_test.cpp
 *
 * Minimum binary heap class testing.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#include <iostream>
#include <random.h>
#include <binaryheap.h>


using namespace std;
using namespace itlab;


int main()
{
    int x, a[100];
    Random r(1);
    BinaryHeap<int> h;

    for( int i=1; i<=25; ++i )
        h.insert( r.random( 1, 100 ) );

    while( !h.isEmpty() )
    {
        h.findMin( x );
        cout << "  " << x << "\t";
        h.deleteMin();
    }
    cout << endl;

    cout << endl << endl;
    for( int i=0; i<40; ++i )
    {
        a[i] = r.random( 1, 100 );
        cout << "  " << a[i] << "\t";
    }
    cout << endl;

    BinaryHeap<int> hh( a, 40 );
    while( !hh.isEmpty() )
    {
        hh.deleteMin( x );
        cout << "  " << x << "\t";
    }
    cout << endl;

    for( int i=1; i<=5; ++i )
        h.insert( r.random( 1, 100 ) );
    h.makeEmpty();
    h.deleteMin();

    cout << endl << endl;
    return 0;
}
