/*****************************************************************************
 *                               vector-impl.h
 *
 * Implementation for Vector class.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


/**
 * initialize
 */
template <typename Type>
void Vector<Type>::init( int length )
{
	assert( pv0 == NULL );
	pv0 = new Type[length];

	assert( pv0 != NULL );
	pv1 = pv0 - 1;
	nRow = length;
}


/**
 * copy vector from normal array
 */
template <typename Type>
inline void Vector<Type>::copyFromArray( const Type *v )
{
	for( int i=0; i<nRow; ++i )
		pv0[i] = v[i];
}


/**
 * set vector by a scalar
 */
template <typename Type>
inline void Vector<Type>::setByScalar( const Type &x )
{
	for( int i=0; i<nRow; ++i )
		pv0[i] = x;
}


/**
 * destroy the vector
 */
template <typename Type>
void Vector<Type>::destroy()
{
	if( pv0 == NULL )
		return;

	delete []pv0;

	pv0 = NULL;
	pv1 = NULL;
}


/**
 * constructors and destructor
 */
template <typename Type>
Vector<Type>::Vector()
: pv0(0), pv1(0), nRow(0)
{
}

template <typename Type>
Vector<Type>::Vector( const Vector<Type> &v )
: pv0(0), pv1(0), nRow(0)
{
	init( v.nRow );
	copyFromArray( v.pv0 );
}

template <typename Type>
Vector<Type>::Vector( int length, const Type &x )
:  pv0(0), pv1(0), nRow(0)
{
	init( length );
	setByScalar( x );
}

template <typename Type>
Vector<Type>::Vector( int length, const Type *array )
:  pv0(0), pv1(0), nRow(0)
{
	init( length );
	copyFromArray( array );
}

template <typename Type>
Vector<Type>::~Vector()
{
	destroy();
}


/**
 * overload evaluate operator= from vector to vector
 */
template <typename Type>
Vector<Type>& Vector<Type>::operator=( const Vector<Type> &v )
{
	if( pv0 == v.pv0 )
		return *this;

	if( nRow == v.nRow )
		copyFromArray( v.pv0 );
	else
	{
		destroy();
		init( v.nRow );
		copyFromArray( v.pv0 );
	}

	return *this;
}


/**
 * overload evaluate operator= from scalar to vector
 */
template <typename Type>
inline Vector<Type>& Vector<Type>::operator=( const Type &x )
{
	setByScalar( x );

	return *this;
}


/**
 * overload operator [] for 0-offset access
 */
template <typename Type>
inline Type& Vector<Type>::operator[]( int i )
{
#ifdef BOUNDS_CHECK
	assert( 0 <= i );
	assert( i < nRow );
#endif

	return pv0[i];
}

template <typename Type>
inline const Type& Vector<Type>::operator[]( int i ) const
{
#ifdef BOUNDS_CHECK
	assert( 0 <= i );
	assert( i < nRow );
#endif

	return pv0[i];
}


/**
 * overload operator () for 1-offset access
 */
template <typename Type>
inline Type& Vector<Type>::operator()( int i )
{
#ifdef BOUNDS_CHECK
	assert( 1 <= i );
	assert( i <= nRow );
#endif

	return pv1[i];
}

template <typename Type>
inline const Type& Vector<Type>::operator()( int i ) const
{
#ifdef BOUNDS_CHECK
	assert( 1 <= i );
	assert( i <= nRow );
#endif

	return pv1[i];
}


/**
 * iterators
 */
template <typename Type>
inline typename Vector<Type>::iterator Vector<Type>::begin()
{
    return pv0;
}

template <typename Type>
inline typename Vector<Type>::const_iterator Vector<Type>::begin() const
{
    return pv0;
}

template <typename Type>
inline typename Vector<Type>::iterator Vector<Type>::end()
{
    return pv0 + nRow;
}

template <typename Type>
inline typename Vector<Type>::const_iterator Vector<Type>::end() const
{
    return pv0 + nRow;
}


/**
 * type conversion functions
 */
template <typename Type>
inline Vector<Type>::operator Type*()
{
	return pv0;
}

template <typename Type>
inline Vector<Type>::operator const Type*() const
{
	return pv0;
}


/**
 * get the vector's total size
 */
template <typename Type>
inline int Vector<Type>::size() const
{
	return  nRow;
}


/**
 * get the vector's dimension
 */
template <typename Type>
inline int Vector<Type>::dim() const
{
	return  nRow;
}


/**
 * reallocate vector's size
 */
template <typename Type>
Vector<Type>& Vector<Type>::resize( int length )
{
	if( nRow == length )
		return *this;

	destroy();
	init( length );

	return *this;
}


/**
 * return vector's reversion
 */
template <typename Type>
Vector<Type> Vector<Type>::reverse()
{
	Vector<Type> tmp(nRow);
	Vector<Type>::iterator  ie = (*this).end(),
                            ib = tmp.begin();

    while( ib != tmp.end() )
        *ib++ = *--ie;

    return tmp;
}


/**
 * get negative vector
 */
template<typename Type>
Vector<Type> operator-( const Vector<Type> &v )
{
	int N = v.dim();
	Vector<Type> tmp( N );

	for( int i=0; i<N; ++i )
		tmp[i] = -v[i];

	return tmp;
}


/**
 * vector-scalar addition.
 */
template <typename Type>
Vector<Type> operator+( const Vector<Type> &v, Type x )
{
	int N = v.dim();
	Vector<Type> tmp( N );

	for( int i=0; i<N; ++i )
		tmp[i] = v[i] + x;

	return tmp;
}

template <typename Type>
inline Vector<Type> operator+( Type x, const Vector<Type> &v )
{
	return v+x;
}

template <typename Type>
Vector<Type> operator+=( Vector<Type> &v, Type x )
{
	int N = v.dim();
	for( int i=0; i<N; ++i )
		v[i] += x;

	return v;
}


/**
 * vector-scalar substraction.
 */
template <typename Type>
Vector<Type> operator-( const Vector<Type> &v, Type x )
{
	int N = v.dim();
	Vector<Type> tmp( N );

	for( int i=0; i<N; ++i )
		tmp[i] = v[i] - x;

	return tmp;
}

template <typename Type>
Vector<Type> operator-( Type x, const Vector<Type> &v )
{
	int N = v.dim();
	Vector<Type> tmp( N );

	for( int i=0; i<N; ++i )
		tmp[i] = x - v[i];

	return tmp;
}

template <typename Type>
Vector<Type> operator-=( Vector<Type> &v, Type x )
{
	int N = v.dim();
	for( int i=0; i<N; ++i )
		v[i] -= x;

	return v;
}


/**
 * vector-scalar multiplication.
 */
template <typename Type>
Vector<Type> operator*( const Vector<Type> &v, Type x )
{
	int N = v.dim();
	Vector<Type> tmp( N );

	for( int i=0; i<N; ++i )
		tmp[i] = v[i] * x;

	return tmp;
}

template <typename Type>
inline Vector<Type> operator*( Type x, const Vector<Type> &v )
{
	return v*x;
}

template <typename Type>
Vector<Type> operator*=( Vector<Type> &v, Type x )
{
	int N = v.dim();
	for( int i=0; i<N; ++i )
		v[i] *= x;

	return v;
}


/**
 * vector-scalar division.
 */
template <typename Type>
Vector<Type> operator/( const Vector<Type> &v, Type x )
{
	int N = v.dim();
	Vector<Type> tmp( N );

	for( int i=0; i<N; ++i )
		tmp[i] = v[i] / x;

	return tmp;
}

template <typename Type>
Vector<Type> operator/( Type x, const Vector<Type> &v )
{
	int N = v.dim();
	Vector<Type> tmp( N );

	for( int i=0; i<N; ++i )
		tmp[i] = x / v[i];

	return tmp;
}

template <typename Type>
Vector<Type> operator/=( Vector<Type> &v, Type x )
{
	int N = v.dim();
	for( int i=0; i<N; ++i )
		v[i] /= x;

	return v;
}


/**
 * vector-vector addition.
 */
template <typename Type>
Vector<Type> operator+( const Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	Vector<Type> tmp( N );
	for( int i=0; i<N; ++i )
		tmp[i] = v1[i] + v2[i];

	return tmp;
}

template <typename Type>
Vector<Type> operator+=( Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	for( int i=0; i<N; ++i )
		v1[i] += v2[i];

	return v1;
}


/**
 * vector-vector substraction.
 */
template <typename Type>
Vector<Type> operator-( const Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	Vector<Type> tmp( N );
	for( int i=0; i<N; ++i )
		tmp[i] = v1[i] - v2[i];

	return tmp;
}

template <typename Type>
Vector<Type> operator-=( Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	for( int i=0; i<N; ++i )
		v1[i] -= v2[i];

	return v1;
}


/**
 * vector-vector multiplication.
 */
template <typename Type>
Vector<Type> operator*( const Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	Vector<Type> tmp( N );
	for( int i=0; i<N; ++i )
		tmp[i] = v1[i] * v2[i];

	return tmp;
}

template <typename Type>
Vector<Type> operator*=( Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	for( int i=0; i<N; ++i )
		v1[i] *= v2[i];

	return v1;
}


/**
 * vector-vector division.
 */
template <typename Type>
Vector<Type> operator/( const Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	Vector<Type> tmp( N );
	for( int i=0; i<N; ++i )
		tmp[i] = v1[i] / v2[i];

	return tmp;
}

template <typename Type>
Vector<Type> operator/=( Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	for( int i=0; i<N; ++i )
		v1[i] /= v2[i];

	return v1;
}


/**
 * Inner product for vectors.
 */
template <typename Type>
Type dotProd( const Vector<Type> &v1, const Vector<Type> &v2 )
{
	int N = v1.dim();
	assert( N == v2.dim() );

	Type sum = 0;
	for( int i=0; i<N; ++i )
		sum += v1[i] * v2[i];

	return sum;
}


/**
 * Vector's sum.
 */
template <typename Type>
Type sum( const Vector<Type> &v )
{
	int N = v.dim();
	Type sum = 0;

	for( int i=0; i<N; ++i )
		sum +=  v[i];
	return sum;
}


/**
 * Vector's norm in Euclidean space.
 */
template <typename Type>
Type norm( const Vector<Type> &v )
{
	int N = v.dim();
	Type sum = 0;

	for( int i=0; i<N; ++i )
		sum +=  v[i] * v[i];

	return sqrt(sum);
}


/**
 * Overload the output stream function.
 */
template <typename Type>
std::ostream& operator<<( std::ostream &out, const Vector<Type> &v )
{
	int N = v.dim();
	out << "size: " << N << " by 1" << "\n";

	for( int i=0; i<N; ++i )
		out << v[i] << " " << "\n";

	return out;
}


/**
 * Overload the input stream function.
 */
template <typename Type>
std::istream& operator>>( std::istream &in, Vector<Type> &v )
{
	int N;
	in >> N;

	if( !( N == v.dim() ) )
		v.resize( N );

	for( int i=0; i<N; ++i )
		in >> v[i];

	return in;
}
