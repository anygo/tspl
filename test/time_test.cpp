/*****************************************************************************
 *                               time_test.cpp
 *
 * Timing function testing.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


#include <iostream>
#include <cmath>
#include <timing.h>


using namespace std;
using namespace itlab;


int main()
{
    int     var = 1;
    double  runTime = 0;
    Timing  time;

    time.start();
    for( int i=0; i<10000; ++i )
        for( int j=0; j<10000; ++j )
            var = sqrt(i*j);
    time.stop();
    runTime = time.read();

    cout << "The running time is : " << runTime << endl << endl;

    return 0;
}