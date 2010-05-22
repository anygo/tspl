/*****************************************************************************
 *                               cwt_test.cpp
 *
 * Continuous wavelet transform testing.
 *
 * Zhang Ming, 2010-03
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <cwt.h>
#include <mathfunc.h>
#include <utilities.h>
#include <statistics.h>
#include <timing.h>


using namespace std;
using namespace itlab;


const int Ls = 1000;
const double fs = 1000.0;


int main()
{

	/******************************* [ signal ] ******************************/
	Vector<double> t = linspace( 0.0, (Ls-1)/fs, Ls );
	Vector<double> st = vsin( 200*PI*vpow(t,2.0) );
	st = st-mean(st);

	/******************************** [ CWT ] ********************************/
	Matrix< complex<double> > coefs;
	CWT<double> wavelet("morlet");
	wavelet.setScales( fs, fs/Ls, fs/2 );
	Timing cnt;
	double runtime = 0.0;
	cout << "Taking contineous wavelet transform(Morlet)." << endl;
	cnt.start();
	coefs = wavelet.cwtC(st);
	cnt.stop();
	runtime = cnt.read();
	cout << "The running time = " << runtime << " (ms)" << endl << endl;

	/******************************** [ ICWT ] *******************************/
	cout << "Taking inverse contineous wavelet transform." << endl;
	cnt.start();
	Vector<double> xt = wavelet.icwtC(coefs);
	cnt.stop();
	runtime = cnt.read();
	cout << "The running time = " << runtime << " (ms)" << endl << endl;

	cout << "The relative error is : " << endl;
	cout << "norm(st-xt) / norm(st) = " << norm(st-xt)/norm(st) << endl;
	cout << endl << endl;


    /******************************* [ signal ] ******************************/
    Vector<float> tf = linspace( float(0.0), (Ls-1)/float(fs), Ls );
	Vector<float> stf = vsin( float(200*PI) * vpow(tf,float(2.0) ) );
	stf = stf-mean(stf);

	/******************************** [ CWT ] ********************************/
	CWT<float> waveletf("mexiHat");
	waveletf.setScales( fs, fs/Ls, fs/2, float(0.25) );
	runtime = 0.0;
	cout << "Taking contineous wavelet transform(Mexican Hat)." << endl;
	cnt.start();
	Matrix<float> coefsf = waveletf.cwtR(stf);
	cnt.stop();
	runtime = cnt.read();
	cout << "The running time = " << runtime << " (ms)" << endl << endl;

	/******************************** [ ICWT ] *******************************/
	cout << "Taking inverse contineous wavelet transform." << endl;
	cnt.start();
	Vector<float> xtf = waveletf.icwtR(coefsf);
	cnt.stop();
	runtime = cnt.read();
	cout << "The running time = " << runtime << " (ms)" << endl << endl;

	cout << "The relative error is : " << endl;
	cout << "norm(st-xt) / norm(st) = " << norm(stf-xtf)/norm(stf) << endl << endl;

	return 0;
}
