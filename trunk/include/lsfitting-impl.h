/*****************************************************************************
 *                               lsfitting-impl.h
 *
 * Implementation for LSFitting class.
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


/**
 * constructors and destructor
 */
template <typename Type>
LSFitting<Type>::LSFitting( const Vector<Type> &xn, const Vector<Type> &yn,
                            Funcs<Type> &f )
                 : Interpolation<Type>( xn, yn ), phi(f)
{
    coefs.resize(phi.dim);
}

template <typename Type>
LSFitting<Type>::~LSFitting()
{
}


/**
 * Compute fitted parameters.
 */
template <typename Type>
void LSFitting<Type>::calcCoefs()
{
    int N = xi.size(),
        M = coefs.dim();

    Type tmp;
    Vector<Type> b(M);
    Matrix<Type> C( M, M );

	for( int i=1; i<=M; ++i )
	{
	    tmp = 0;
	    for( int k=0; k<N; ++k )
            tmp += phi(i,xi[k]) * phi(i,xi[k]);
        C(i,i) = tmp;

	    for( int j=i+1; j<=M; ++j )
	    {
	        tmp = 0;
	        for( int k=0; k<N; ++k )
                tmp += phi(i,xi[k]) * phi(j,xi[k]);
            C(i,j) = C(j,i) = tmp;
	    }

	    tmp = 0;
	    for( int k=0; k<N; ++k )
            tmp += phi(i,xi[k]) * yi[k];
        b(i) = tmp;
	}

    coefs = choleskySolver( C, b );
}


/**
 * Compute the value of fitted function at given "x".
 */
template <typename Type>
Type LSFitting<Type>::evaluate( Type x )
{
	Type y = 0;
	for( int j=0; j<coefs.size(); ++j )
		y += coefs[j] * phi( j, x );

	return y;
}


/**
 * Get the fitted parameters.
 */
template <typename Type>
inline Vector<Type> LSFitting<Type>::getCoefs() const
{
	return coefs;
}
