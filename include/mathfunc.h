/*****************************************************************************
 *                                 mathfunc.h
 *
 * Usable math functions for vector and matrix. Mainly including "sin", "cos"
 * "exp", "pow" functions for vector, and "abs", "real", "imag" for both
 * vector and matrix.
 *
 * To distinguish general math functions, those for vector, are prefixed
 * with the character "v", and those for matrix, are prefixed with the
 * character "m".
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef MATHFUNC_H
#define MATHFUNC_H


#include <complex>
#include <matrix.h>


namespace itlab
{

    /**
	 * Absolute function of vectors and matrixes.
	 */
	template <typename Type>
	Vector<Type> vabs( const Vector<Type> &x )
	{
		int N = x.dim();
		Vector<Type> y(N);

		for( int i=0; i<N; ++i )
			y[i] = abs( x[i] );

		return y;
	}

	template <typename Type>
	Vector<Type> vabs( const Vector< complex<Type> > &x )
	{
		int N = x.dim();
		Vector<Type> y(N);

		for( int i=0; i<N; ++i )
			y[i] = abs( x[i] );

		return y;
	}

	template <typename Type>
	Matrix<Type> mabs( const Matrix<Type> &x )
	{
		int M = x.rows(),
            N = x.cols();
		Matrix<Type> y( M, N );

		for( int i=0; i<M; ++i )
            for( int j=0; j<N; ++j )
                y[i][j] = abs( x[i][j] );

		return y;
	}

	template <typename Type>
	Matrix<Type> mabs( const Matrix< complex<Type> > &x )
	{
		int M = x.rows(),
            N = x.cols();
		Matrix<Type> y( M, N );

		for( int i=0; i<M; ++i )
            for( int j=0; j<N; ++j )
                y[i][j] = abs( x[i][j] );

		return y;
	}


	/**
	 * Sine function of vectors.
	 */
	template <typename Type>
	Vector<Type> vsin( const Vector<Type> &x )
	{
		int N = x.dim();
		Vector<Type> y(N);

		for( int i=0; i<N; ++i )
			y[i] = sin(x[i]);

		return y;
	}


	/**
	 * Cosine function of vectors.
	 */
	template <typename Type>
	Vector<Type> vcos( const Vector<Type> &x )
	{
		int N = x.dim();
		Vector<Type> y(N);

		for( int i=0; i<N; ++i )
			y[i] = cos(x[i]);

		return y;
	}


	/**
	 * Exponential function of vectors.
	 */
	template <typename Type>
	Vector<Type> vexp( const Vector<Type> &x )
	{
		int N = x.dim();
		Vector<Type> y(N);

		for( int i=0; i<N; ++i )
			y[i] = exp(x[i]);

		return y;
	}


    /**
     * Power function of vectors.
     */
    template <typename Type>
	Vector<Type> vpow( const Vector<Type> &x, Type r )
	{
		int N = x.dim();
		Vector<Type> y(N);

		for( int i=0; i<N; ++i )
			y[i] = pow(x[i],r);

		return y;
	}


	/**
	 * Normal distribution with expectation "u" and variance "r".
	 */
	template <typename Type>
	Vector<Type> gauss( const Vector<Type> &x, Type u, Type r )
	{
		Vector<Type> tmp(x);

		tmp = (tmp-u)*(tmp-u) / ( -2*r*r );
		tmp = vexp(tmp) / Type( (sqrt(2*PI)*r) );

		return tmp;
	}


	/**
	 * Real function of complex vectors and matrixes.
	 */
	template <typename Type>
	Vector<Type> vreal( const Vector< complex<Type> > &x )
	{
		int N = x.dim();
		Vector<Type> y(N);

		for( int i=0; i<N; ++i )
			y[i] = real( x[i] );

		return y;
	}

	template <typename Type>
	Matrix<Type> mreal( const Matrix< complex<Type> > &x )
	{
		int M = x.rows(),
            N = x.cols();
		Matrix<Type> y( M, N );

		for( int i=0; i<M; ++i )
            for( int j=0; j<N; ++j )
                y[i][j] = real( x[i][j] );

		return y;
	}


	/**
	 * Imaginary function of complex vectors and matrixes.
	 */
	template <typename Type>
	Vector<Type> vimag( const Vector< complex<Type> > &x )
	{
		int N = x.dim();
		Vector<Type> y(N);

		for( int i=0; i<N; ++i )
			y[i] = imag( x[i] );

		return y;
	}

	template <typename Type>
	Matrix<Type> mimag( const Matrix< complex<Type> > &x )
	{
		int M = x.rows(),
            N = x.cols();
		Matrix<Type> y( M, N );

		for( int i=0; i<M; ++i )
            for( int j=0; j<N; ++j )
                y[i][j] = imag( x[i][j] );

		return y;
	}

}
// namespace itlab


#endif
// MATHFUNC_H
