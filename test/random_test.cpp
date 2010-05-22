/*****************************************************************************
 *                               random_test.cpp
 *
 * Random number generator class testing.
 *
 * Zhang Ming, 2010-04
 *****************************************************************************/


#include <iostream>
#include <random.h>


using namespace std;
using namespace itlab;


int main()
{
    Random rand;

    for( int i=0; i<10; ++i )
        cout << rand.random() << "\t";
    cout << endl << endl;

    rand.seed( 127 );
    for( int i=0; i<10; ++i )
        cout << rand.random( 0, 10 ) << "\t";
    cout << endl << endl;

    rand.seed( 2011 );
    for( int i=0; i<10; ++i )
        cout << rand.random( 0.0, 1.0 ) << "\t";
    cout << endl << endl;

    return 0;
}
