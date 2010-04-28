/*****************************************************************************
 *                               cholesky-impl.h
 *
 * Implementation for Cholesky class.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


/**
 * constructor and destructor
 */
template<typename Real>
Cholesky<Real>::Cholesky() : spd(true)
{
}

template<typename Real>
Cholesky<Real>::~Cholesky()
{
}


/**
 * return true, if original matrix is symmetric positive-definite.
 */
template<typename Real>
inline bool Cholesky<Real>::isSpd() const
{
    return spd;
}


/**
 * Constructs a lower triangular matrix L, such that L*L'= A.
 * If A is not symmetric positive-definite (SPD), only a partial
 * factorization is performed. If isspd() evalutate true then
 * the factorizaiton was successful.
 */
template <typename Real>
void Cholesky<Real>::dec( const Matrix<Real> &A )
{
    int m = A.rows();
    int n = A.cols();

    spd = (m == n);
    if( !spd )
        return;

    L = Matrix<Real>(n,n);

    // main loop.
    for( int j=0; j<n; ++j )
    {
        Real d = 0;
        for( int k=0; k<j; ++k )
        {
            Real s = 0;
            for( int i=0; i<k; ++i )
                s += L[k][i]*L[j][i];

            L[j][k] = s = (A[j][k]-s) / L[k][k];
            d = d + s*s;
            spd = spd && (A[k][j] == A[j][k]);
        }

        d = A[j][j] - d;
        spd = spd && ( d > 0 );

        L[j][j] = sqrt( d > 0 ? d : 0 );
        for( int k=j+1; k<n; ++k )
            L[j][k] = 0;
    }
}


/**
 * return the lower triangular factor, L, such that L*L'=A.
 */
template<typename Real>
inline Matrix<Real> Cholesky<Real>::getL() const
{
    return L;
}


/**
 * Solve a linear system A*x = b, using the previously computed
 * cholesky factorization of A: L*L'.
 */
template <typename Real>
Vector<Real> Cholesky<Real>::solve( const Vector<Real> &b )
{
    int n = L.rows();
    if( b.dim() != n )
        return Vector<Real>();

    Vector<Real> x = b;

    // solve L*y = b
    for( int k=0; k<n; ++k )
    {
        for( int i=0; i<k; ++i )
            x[k] -= x[i]*L[k][i];

        x[k] /= L[k][k];
    }

    // solve L'*x = y
    for( int k=n-1; k>=0; --k )
    {
        for( int i=k+1; i<n; ++i )
            x[k] -= x[i]*L[i][k];

        x[k] /= L[k][k];
    }

    return x;
}


/**
 * Solve a linear system A*X = B, using the previously computed
 * cholesky factorization of A: L*L'.
 */
template <typename Real>
Matrix<Real> Cholesky<Real>::solve( const Matrix<Real> &B )
{
    int n = L.rows();
    if( B.rows() != n )
        return Matrix<Real>();

    Matrix<Real> X = B;
    int nx = B.cols();

    // solve L*Y = B
    for( int j=0; j<nx; ++j )
        for( int k=0; k<n; ++k )
        {
            for( int i=0; i<k; ++i )
                X[k][j] -= X[i][j]*L[k][i];

            X[k][j] /= L[k][k];
        }

    // solve L'*X = Y
    for( int j=0; j<nx; ++j )
        for( int k=n-1; k>=0; --k )
        {
            for( int i=k+1; i<n; ++i )
                X[k][j] -= X[i][j]*L[i][k];

            X[k][j] /= L[k][k];
        }

    return X;
}
