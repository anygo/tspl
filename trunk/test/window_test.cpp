/*****************************************************************************
 *                               window_test.cpp
 *
 * Windows function testing.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <window.h>


using namespace std;
using namespace itlab;


int main()
{
    int N = 5;

    cout << "Rectangle window : " << rectangle(N) << endl << endl;
    cout << "Bartlett window : " << bartlett(N) << endl << endl;
    cout << "Hanning window : " << hanning(N) << endl << endl;
    cout << "Hamming window : " << hamming(N) << endl << endl;
    cout << "Blackman window : " << blackman(N) << endl << endl;
    cout << "Kaiser window : " << kaiser(N,8/PI) << endl << endl;
    cout << "Gauss window : " << gauss(N) << endl << endl;

    cout << "Rectangle window : " << window("Rectangle",N) << endl << endl;
    cout << "Bartlett window : " << window("Bartlett",N) << endl << endl;
    cout << "Hanning window : " << window("Hanning",N) << endl << endl;
    cout << "Hamming window : " << window("Hamming",N) << endl << endl;
    cout << "Blackman window : " << window("Blackman",N) << endl << endl;
    cout << "Kaiser window : " << window("Kaiser",N, 8/PI) << endl << endl;
    cout << "Gauss window : " << window("Gauss",N,2.5) << endl;

    return 0;
}
