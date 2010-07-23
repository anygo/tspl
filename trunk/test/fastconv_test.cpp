/*****************************************************************************
 *                               fastconv_test.cpp
 *
 * Fast convolution testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <fastconv.h>


using namespace std;
using namespace itlab;


const   int M = 3;
const   int N = 5;
typedef double  Type;


int main()
{
    Vector<Type> xn( M ),
                   yn( N );
    Vector<Type> zn;

    for( int i=0; i<M; ++i )
        xn[i] = i;
    for( int i=0; i<N; ++i )
        yn[i] = i-N/2;

    // covolution
    zn = fastConv( xn, yn );
    cout << "xn:  " << xn << endl << endl
         << "yn:  " << yn << endl << endl;
    cout << "convolution:   " << zn << endl << endl;

    // autor and cross correlation functions
    zn = fastAcor( xn );
    cout << "auto-correlation:   " << zn << endl << endl;
    zn = fastCcor( xn, yn );
    cout << "cross-correlation:   " << zn << endl;

    return 0;
}
