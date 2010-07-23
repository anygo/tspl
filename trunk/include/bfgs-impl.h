/*****************************************************************************
 *                               bfgs-impl.h
 *
 * Implementation for BFGS class.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


/**
 * constructors and destructor
 */
template <typename Dtype, typename Ftype>
BFGS<Dtype, Ftype>::BFGS() : LineSearch<Dtype, Ftype>()
{
}

template <typename Dtype, typename Ftype>
BFGS<Dtype, Ftype>::~BFGS()
{
}


/**
 * Finding the optimal solution. The default tolerance error and maximum
 * iteratin number are "tol=1.0e-6" and "maxItr=100", respectively.
 */
template <typename Dtype, typename Ftype>
void BFGS<Dtype, Ftype>::optimize( Ftype &func, Vector<Dtype> &x0,
                                   Dtype tol, int maxItr )
{
    // initialize parameters.
    int k = 0,
        cnt = 0,
        N = x0.dim();

    Dtype ys,
          yHy,
          alpha;
    Vector<Dtype> d(N),
                  s(N),
                  y(N),
                  v(N),
                  Hy(N),
                  gPrev(N);
    Matrix<Dtype> H = eye( N, Dtype(1.0) );

    Vector<Dtype> x(x0);
    Dtype fx = func(x);
    this->funcNum++;
    Vector<Dtype> gnorm(maxItr);
    Vector<Dtype> g = func.grad(x);
    gnorm[k++]= norm(g);

    while( ( gnorm(k) > tol ) && ( k < maxItr ) )
    {
        // descent direction
        d = -prod( H, g );

        // one dimension searching
        alpha = this->getStep( func, x, d );

        // check flag for restart
        if( !this->success )
            if( norm(H-eye(N,Dtype(1.0))) < EPS )
                break;
            else
            {
                H = eye( N, Dtype(1.0) );
                cnt++;
                if( cnt == maxItr )
                    break;
            }
        else
        {
            // update
            s = alpha * d;
            x += s;
            fx = func(x);
            this->funcNum++;
            gPrev = g;
            g = func.grad(x);
            y = g - gPrev;

            Hy = prod( H, y );
            ys = dotProd( y, s );
            yHy = dotProd( y, Hy );
            if( (ys < EPS) || (yHy < EPS) )
                H = eye( N, Dtype(1.0) );
            else
            {
                v = sqrt(yHy) * ( s/ys - Hy/yHy );
                H = H + tranProd(s,s)/ys - tranProd(Hy,Hy)/yHy + tranProd(v,v);
            }
            gnorm[k++] = norm(g);
        }
    }

    xOpt = x;
    fMin = fx;
    gradNorm.resize(k);
    for( int i=0; i<k; ++i )
        gradNorm[i] = gnorm[i];

    if( gradNorm[k-1] > tol )
        this->success = false;
}


/**
 * Get the optimum point.
 */
template <typename Dtype, typename Ftype>
inline Vector<Dtype> BFGS<Dtype, Ftype>::getOptValue() const
{
    return xOpt;
}


/**
 * Get the norm of gradient in each iteration.
 */
template <typename Dtype, typename Ftype>
inline Vector<Dtype> BFGS<Dtype, Ftype>::getGradNorm() const
{
    return gradNorm;
}


/**
 * Get the minimum value of objective function.
 */
template <typename Dtype, typename Ftype>
inline Dtype BFGS<Dtype, Ftype>::getFuncMin() const
{
    return fMin;
}


/**
 * Get the iteration number.
 */
template <typename Dtype, typename Ftype>
inline int BFGS<Dtype, Ftype>::getItrNum() const
{
    return gradNorm.dim()-1;
}
