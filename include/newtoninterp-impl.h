/*****************************************************************************
 *                               newtoninterp-impl.h
 *
 * Implementation for NewtonInterp class.
 *
 * Zhang Ming, 2010-04
 *****************************************************************************/


/**
 * constructors and destructor
 */
template <typename Type>
NewtonInterp<Type>::NewtonInterp( const Vector<Type> &xn, const Vector<Type> &yn )
                    : Interpolation<Type>( xn, yn ), coefs(yn)
{
}

template <typename Type>
NewtonInterp<Type>::~NewtonInterp()
{
}


/**
 * Compute polynomial' coefsficients.
 */
template <typename Type>
void NewtonInterp<Type>::calcCoefs()
{
    int N = xi.size();
	for( int j=1; j<N; ++j )
		for( int i=N-1; i>=j; --i )
			coefs[i] = (coefs[i]-coefs[i-1]) / (xi[i]-xi[i-j]);
}


/**
 * Compute the value of polynomial at given "x".
 */
template <typename Type>
Type NewtonInterp<Type>::evaluate( Type x )
{
    int N = xi.size();
	Type y = 0,
         tmp = 0;

	for( int j=0; j<N; ++j )
	{
		tmp = coefs[j];
		for( int i=0; i<j; ++i )
			tmp *= x-xi[i];

		y += tmp;
	}

	return y;
}


/**
 * Get polynomial' coefsficients.
 */
template <typename Type>
inline Vector<Type> NewtonInterp<Type>::getCoefs() const
{
	return coefs;
}
