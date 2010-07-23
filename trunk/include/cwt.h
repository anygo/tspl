/*****************************************************************************
 *                                   cwt.h
 *
 * Continuous Wavelet Transform.
 *
 * Class for continuous wavelet transform, which is designed for
 * computing the continuous wavelet transform and it's inverse transform of
 * 1D signals. For now this class only supports "Mexican hat"(real)
 * and "Morlet"(complex) wavlet.
 *
 * The mother wavelet doubles and scale parameters are specified by users. The
 * inverse transform can not achive perfect reconstruction, but with a
 * sufficient precision in practice. Of course you can improve the accurate
 * by extend the range of scale parameter.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef CWT_H
#define CWT_H


#include <cstdlib>
#include <string>
#include <complex>
#include <fft.h>
#include <matrix.h>


namespace itlab
{

    template <typename Type>
	class CWT
	{

	public:

		CWT( const string &name );
		~CWT();

        void setScales( Type fs, Type fmin, Type fmax, Type dj=0.25 );
        Matrix<Type> cwtR( Vector<Type> &signal );
		Vector<Type> icwtR( const Matrix<Type> &coefs );
		Matrix< complex<Type> > cwtC( Vector<Type> &signal );
		Vector<Type> icwtC( const Matrix< complex<Type> > &coefs );

	private:

        string waveType;
        Type delta;
        Vector<Type> scales;
        Matrix<Type> table;

        void setTable( int N );
		Type constDelta();

	};
	// class CWT

    #include <cwt-impl.h>

}
// namespace itlab


#endif
// CWT_H
