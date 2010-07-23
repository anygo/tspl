/*****************************************************************************
 *                               qrd-impl.h
 *
 * Implementation for QRD class.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


/**
 * constructor and destructor
 */
template<typename Real>
QRD<Real>::QRD()
{
}

template<typename Real>
QRD<Real>::~QRD()
{
}


/**
 * Create a QR factorization object for A.
 */
template <typename Real>
void QRD<Real>::dec( const Matrix<Real> &A )
{

    m = A.rows();
    n = A.cols();
    QR = A;
    RDiag = Vector<Real>(n);

    int i=0,
        j=0,
        k=0;

    // main loop.
    for( k=0; k<n; ++k )
    {
        // Compute 2-norm of k-th column without under/overflow.
        Real nrm = 0;
        for( i=k; i<m; ++i )
            nrm = hypot( nrm, QR[i][k] );

        if( nrm != 0 )
        {
            // Form k-th Householder vector.
            if( QR[k][k] < 0 )
                nrm = -nrm;

            for( i=k; i<m; ++i )
                QR[i][k] /= nrm;

            QR[k][k] += 1;

            // Apply transformation to remaining columns.
            for( j=k+1; j<n; ++j )
            {
                Real s = 0;
                for( i=k; i<m; ++i )
                    s += QR[i][k]*QR[i][j];

                s = -s/QR[k][k];
                for( i=k; i<m; ++i )
                    QR[i][j] += s*QR[i][k];
            }
        }

        RDiag[k] = -nrm;
    }
}


/**
 * Flag to denote the matrix is of full rank.
 */
template <typename Real>
inline bool QRD<Real>::isFullRank() const
{
    for( int j=0; j<n; ++j )
        if( RDiag[j] == 0 )
            return false;

    return true;
}


/**
 * Retreive the Householder vectors from QR factorization
 */
template <typename Real>
void QRD<Real>::getH( Matrix<Real> &H )
{
    H.resize( m, n );

    for( int i=0; i<m; ++i )
        for( int j=0; j<n; ++j )
            if( i >= j )
                H[i][j] = QR[i][j];
            else
                H[i][j] = 0;
}


/**
 * Return the upper triangular factorof the QR factorization.
 */
template <typename Real>
void QRD<Real>::getQ( Matrix<Real> &Q )
{
    Q.resize( m, n );
    int i = 0,
        j = 0,
        k = 0;

    for( k=n-1; k>=0; --k )
    {
        for( i=0; i<m; ++i )
            Q[i][k] = 0;

        Q[k][k] = 1;
        for( j=k; j<n; ++j )
            if( QR[k][k] != 0 )
            {
                Real s = 0;
                for( i=k; i<m; ++i )
                    s += QR[i][k] * Q[i][j];

                s = -s / QR[k][k];
                for( int i=k; i<m; ++i )
                    Q[i][j] += s*QR[i][k];
            }
    }
}


/**
 * Return the orthogonal factorof the QR factorization.
 */
template <typename Real>
void QRD<Real>::getR( Matrix<Real> &R )
{
    R.resize( n, n );

    for( int i=0; i<n; ++i )
        for( int j=0; j<n; ++j )
            if( i < j )
                R[i][j] = QR[i][j];
            else if( i == j )
                R[i][j] = RDiag[i];
            else
                R[i][j] = 0;
}


/**
 * Least squares solution of A*x = b
 * Return x: a n-length vector that minimizes the two norm
 * of Q*R*X-B. If B is non-conformant, or if QR.isFullRank()
 * is false, the routinereturns a null (0-length) vector.
 */
template <typename Real>
Vector<Real> QRD<Real>::solve( const Vector<Real> &b )
{
    // arrays must be conformant
    if( b.dim() != m )
        return Vector<Real>();

    // matrix is rank deficient
    if( !isFullRank() )
        return Vector<Real>();

    Vector<Real> x = b;

    // compute y = transpose(Q)*b
    for( int k=0; k<n; ++k )
    {
        Real s = 0;
        for( int i=k; i<m; ++i )
            s += QR[i][k]*x[i];

        s = -s/QR[k][k];
        for( int i=k; i<m; ++i )
            x[i] += s*QR[i][k];
    }

    // solve R*x = y;
    for( int k=n-1; k>=0; --k )
    {
        x[k] /= RDiag[k];
        for( int i=0; i<k; ++i )
            x[i] -= x[k]*QR[i][k];
    }

    // return n x nx portion of x
    Vector<Real> x_(n);
    for( int i=0; i<n; ++i )
        x_[i] = x[i];

    return x_;
}


/**
 * Least squares solution of A*X = B
 * return X: a n x k Array that minimizes the two norm of Q*R*X-B.
 * If B is non-conformant, or if QR.isFullRank() is false, the
 * routinereturns a null (0) array.
 */
template <typename Real>
Matrix<Real> QRD<Real>::solve( const Matrix<Real> &B )
{
    // arrays must be conformant
    if( B.rows() != m )
        return Matrix<Real>(0,0);

    // matrix is rank deficient
    if( !isFullRank() )
        return Matrix<Real>(0,0);

    int nx = B.cols();
    Matrix<Real> X = B;
    int i=0,
        j=0,
        k=0;

    // compute Y = transpose(Q)*B
    for( k=0; k<n; ++k )
        for( j=0; j<nx; ++j )
        {
            Real s = 0;
            for( i=k; i<m; ++i )
                s += QR[i][k]*X[i][j];

            s = -s/QR[k][k];
            for( i=k; i<m; ++i )
                X[i][j] += s*QR[i][k];
        }

    // solve R*X = Y;
    for( k=n-1; k>=0; --k )
    {
        for( j=0; j<nx; ++j )
            X[k][j] /= RDiag[k];

        for( i=0; i<k; ++i )
            for( j=0; j<nx; ++j )
                X[i][j] -= X[k][j]*QR[i][k];
    }

    // return n x nx portion of X
    Matrix<Real> X_( n, nx );
    for( i=0; i<n; ++i )
        for( j=0; j<nx; ++j )
            X_[i][j] = X[i][j];

     return X_;
}
