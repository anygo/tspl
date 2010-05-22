/*****************************************************************************
 *                               lud-impl.h
 *
 * Implementation for LUD class.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


/**
 * constructor and destructor
 */
template<typename Real>
LUD<Real>::LUD()
{
}

template<typename Real>
LUD<Real>::~LUD()
{
}


/**
 * permute copy
 */
template <typename Real>
Vector<Real> LUD<Real>::permuteCopy( const Vector<Real> &A,
                                     const Vector<int> &piv )
{
    int pivLength = piv.dim();
    if( pivLength != A.dim() )
        return Vector<Real>();

    Vector<Real> x(pivLength);
    for( int i=0; i<pivLength; ++i )
        x[i] = A[piv[i]];

    return x;
}

template <typename Real>
Matrix<Real> LUD<Real>::permuteCopy( const Matrix<Real> &A,
                                     const Vector<int> &piv, int j0, int j1 )
{
    int pivLength = piv.dim();
    Matrix<Real> X( pivLength, j1-j0+1 );

    for( int i=0; i<pivLength; ++i )
        for( int j=j0; j<=j1; ++j )
            X[i][j-j0] = A[piv[i]][j];

    return X;
}


/**
 * Return pivot permutation vector
 */
template<typename Real>
inline Vector<int> LUD<Real>::getPivot() const
{
    return piv;
}


/**
 * LU Decomposition
 */
template <typename Real>
void LUD<Real>::dec(const Matrix<Real> &A)
{
    m = A.rows();
    n = A.cols();
    piv.resize(m);
    LU = A;

    // Use a "left-looking", dot-product, Crout/Doolittle algorithm.
    for( int i=0; i<m; ++i )
        piv[i] = i;

    pivsign = 1;
    Real *LUrowi = 0;
    Vector<Real> LUcolj(m);

    // outer loop
    for( int j=0; j<n; ++j )
    {
        // Make a copy of the j-th column to localize references.
        for( int i=0; i<m; ++i )
            LUcolj[i] = LU[i][j];

        // Apply previous transformations.
        for( int i=0; i<m; ++i )
        {
            LUrowi = LU[i];

            // Most of the time is spent in the following dot product.
            int kmax = (i < j)? i : j;
            Real s = 0;

            for( int k=0; k<kmax; ++k )
                s += LUrowi[k]*LUcolj[k];

            LUrowi[j] = LUcolj[i] -= s;
        }

        // Find pivot and exchange if necessary.
        int p = j;
        for( int i=j+1; i<m; ++i )
            if( abs(LUcolj[i]) > abs(LUcolj[p]) )
                p = i;

        if( p != j )
        {
            int k=0;
            for( k=0; k<n; ++k )
                swap( LU[p][k], LU[j][k] );

            k = piv[p];
            piv[p] = piv[j];
            piv[j] = k;
            pivsign = -pivsign;
        }

        // compute multipliers
        if( (j < m) && ( LU[j][j] != 0 ) )
            for( int i=j+1; i<m; ++i )
                LU[i][j] /= LU[j][j];
    }
}


/**
 * Return lower and upper triangular factor L and U.
 */
template <typename Real>
void LUD<Real>::getL( Matrix<Real> &L )
{
    L.resize( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            if( i > j )
                L[i][j] = LU[i][j];
            else if ( i == j )
                L[i][j] = 1;
            else
                L[i][j] = 0;
}

template <typename Real>
void LUD<Real>::getU( Matrix<Real> &U )
{
    U.resize( n, n );

    for( int i=0; i<n; ++i )
        for( int j=0; j<n; ++j )
            if( i <= j )
                U[i][j] = LU[i][j];
            else
                U[i][j] = 0;
}


/**
 * Compute determinant using LU factors.
 */
template <typename Real>
Real LUD<Real>::det()
{
    if( m != n )
        return 0;

    Real d = Real(pivsign);
    for( int j=0; j<n; ++j )
        d *= LU[j][j];

    return d;
}


/**
 * true if upper triangular factor U is nonsingular, 0 otherwise.
 */
template <typename Real>
inline bool LUD<Real>::isNonsingular()
{
    for( int j=0; j<n; ++j )
        if( LU[j][j] == 0 )
            return false;

    return true;
}


/**
 * Solve A*x = b, where x and b are vectors of length equal
 * to the number of rows in A.
 */
template <typename Real>
Vector<Real> LUD<Real>::solve(const Vector<Real> &b)
{
    // dimensions: A is mxn, X is nxk, B is mxk
    if( b.dim() != m )
        return Vector<Real>();

    if( !isNonsingular() )
        return Vector<Real>();

    Vector<Real> x = permuteCopy( b, piv );

    // solve L*Y = B(piv)
    for( int k=0; k<n; ++k )
        for( int i=k+1; i<n; ++i )
            x[i] -= x[k]*LU[i][k];

    // solve U*X = Y;
    for( int k=n-1; k>=0; --k )
    {
        x[k] /= LU[k][k];
        for( int i=0; i<k; ++i )
            x[i] -= x[k]*LU[i][k];
    }

    return x;
}


/**
 * Solve A*X = B
 */
template <typename Real>
Matrix<Real> LUD<Real>::solve(const Matrix<Real> &B)
{
    // dimensions: A is mxn, X is nxk, B is mxk
    if( B.rows() != m )
        return Matrix<Real>(0,0);

    if( !isNonsingular() )
        return Matrix<Real>(0,0);

    // copy right hand side with pivoting
    int nx = B.cols();
    Matrix<Real> X = permuteCopy( B, piv, 0, nx-1 );

    // solve L*Y = B(piv,:)
    for( int k=0; k<n; ++k )
        for( int i=k+1; i<n; ++i )
            for( int j=0; j<nx; ++j )
                X[i][j] -= X[k][j]*LU[i][k];

    // solve U*X = Y;
    for( int k=n-1; k>=0; --k )
    {
        for( int j=0; j<nx; ++j )
            X[k][j] /= LU[k][k];

        for( int i=0; i<k; ++i )
            for( int j=0; j<nx; ++j )
                X[i][j] -= X[k][j]*LU[i][k];
    }

    return X;
}
