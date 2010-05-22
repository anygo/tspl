/*****************************************************************************
 *                               statistics_test.cpp
 *
 * Statistics routines testing.
 *
 * Zhang Ming, 2010-03
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <statistics.h>


using namespace std;
using namespace itlab;


int main()
{
    Vector<double> xn(9);
    xn[0] = 1.2366;     xn[1] = -0.6313;    xn[2] = -2.3252;
    xn[3] = -1.2316;    xn[4] = 1.0556;     xn[5] = -0.1132;
    xn[6] = 0.3792;     xn[7] = 0.9442;     xn[8] = -2.1204;

    cout << "The minmum maximum and median value of the sequence." << endl;
    cout << min(xn) << endl << max(xn) << endl << mid(xn) <<endl << endl;
    cout << "The mean, variance and standard variance of the sequence." << endl;
    cout << mean(xn) << endl << var(xn) << endl << stdVar(xn) << endl << endl;

    Vector<double> yn = xn - mean(xn);
    cout << "The skew and kurtosis of the sequence." << endl;
    cout << skew(yn) << endl << kurt(yn) << endl << endl;

    cout << "The PDF of the sequence." << endl;
    cout << pdf(yn) << endl;

    return 0;
}
