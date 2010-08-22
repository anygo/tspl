/*****************************************************************************
 *                               vector-impl.h
 *
 * Implementation for Matrix math functions.
 *
 * Zhang Ming, 2010-08, Xi'an Jiaotong University.
 *****************************************************************************/


template <typename Type>
Matrix<Type> abs( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = abs( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> cos( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = cos( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> sin( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = sin( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> tan( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = tan( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> acos( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = acos( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> asin( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = asin( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> atan( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = atan( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> exp( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = exp( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> log( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = log( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> log10( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = log10( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> sqrt( const Matrix<Type> &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = sqrt( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> pow( const Matrix<Type> &B, const Matrix<Type> &E )
{
    int m = B.rows(),
        n = B.cols();
    assert( m == E.rows() );
    assert( n == E.cols() );

    Matrix<Type> tmp( m, n );
    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = pow( B[i][j], E[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> pow( const Matrix<Type> &B, const Type &e )
{
    int m = B.rows(),
        n = B.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = pow( B[i][j], e );

    return tmp;
}


template <typename Type>
Matrix<Type> pow( const Type &b, const Matrix<Type> &E )
{
    int m = E.rows(),
        n = E.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = pow( b, E[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> abs( const Matrix< complex<Type> > &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = abs( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> arg( const Matrix< complex<Type> > &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = arg( A[i][j] );

    return tmp;
}


template <typename Type>
Matrix<Type> real( const Matrix< complex<Type> > &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = A[i][j].real();

    return tmp;
}


template <typename Type>
Matrix<Type> imag( const Matrix< complex<Type> > &A )
{
    int m = A.rows(),
        n = A.cols();
    Matrix<Type> tmp( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            tmp[i][j] = A[i][j].imag();

    return tmp;
}
