/*****************************************************************************
 *                               fft_test.cpp
 *
 * FFT interface testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <complex>
#include <fft.h>
#include <constants.h>


using namespace std;
using namespace itlab;


const   int     N = 7;
typedef float   Type;


int main()
{
    // complex to complex dft test...
    Vector< complex<Type> > xn( N );
    Vector< complex<Type> > yn( N );
    Vector< complex<Type> > Xk( N );

    for( int i=0; i<N; ++i )
    {
        Type theta = Type( 2*PI * i / N );
        xn[i] = complex<Type>( cos(theta), sin(theta) );
    }
    cout << "xn:   " << xn << endl << endl;

    fft( xn, Xk );
    cout << "Xk=fft(xn):   " << Xk << endl << endl;
    ifft( Xk, yn );
    cout << "yn=ifft(Xk):   " << yn << endl << endl;

    // real to complex and complex to real dft test...
    Vector<Type> sn(N);
    Vector< complex<Type> > Sk( N/2+1 );
    for( int i=0; i<N; ++i )
    {
        Type theta = Type( 2*PI * i / N );
        sn[i] = sin(theta);
    }
    cout << "sn:   " << sn << endl;

    fft( sn, Sk );
    cout << "Sk=fft(sn):   " << Sk << endl << endl;
    ifft( Sk, sn );
    cout << "sn=ifft(Sk):   " << sn << endl;

    return 0;
}
