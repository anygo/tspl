/*****************************************************************************
 *                               steepdesc-impl.h
 *
 * Implementation for SteepDesc class.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


/**
 * constructors and destructor
 */
template <typename Dtype, typename Ftype>
SteepDesc<Dtype, Ftype>::SteepDesc() : LineSearch<Dtype, Ftype>()
{
}

template <typename Dtype, typename Ftype>
SteepDesc<Dtype, Ftype>::~SteepDesc()
{
}


/**
 * Finding the optimal solution. The default tolerance error and maximum
 * iteratin number are "tol=1.0e-6" and "maxItr=100", respectively.
 */
template <typename Dtype, typename Ftype>
void SteepDesc<Dtype, Ftype>::optimize( Ftype &func, Vector<Dtype> &x0,
                                        Dtype tol, int maxItr )
{
    // initialize parameters.
    int k = 0;
    Vector<Dtype> x(x0);
    Dtype fx = func(x);
    this->funcNum++;
    Vector<Dtype> gnorm(maxItr);
    Vector<Dtype> g = func.grad(x);
    gnorm[k++]= norm(g);

    Dtype alpha;
    Vector<Dtype> d(g.dim());

    while( ( gnorm(k) > tol ) && ( k < maxItr ) )
    {
        // descent direction
        d =  - g;

        // one dimension searching
        alpha = this->getStep( func, x, d );
        if( !this->success )
            break;

		// update
        x += alpha*d;
        fx = func(x);
        this->funcNum++;
        g = func.grad(x);
        gnorm[k++] = norm(g);
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
inline Vector<Dtype> SteepDesc<Dtype, Ftype>::getOptValue() const
{
    return xOpt;
}


/**
 * Get the norm of gradient in each iteration.
 */
template <typename Dtype, typename Ftype>
inline Vector<Dtype> SteepDesc<Dtype, Ftype>::getGradNorm() const
{
    return gradNorm;
}


/**
 * Get the minimum value of objective function.
 */
template <typename Dtype, typename Ftype>
inline Dtype SteepDesc<Dtype, Ftype>::getFuncMin() const
{
    return fMin;
}


/**
 * Get the iteration number.
 */
template <typename Dtype, typename Ftype>
inline int SteepDesc<Dtype, Ftype>::getItrNum() const
{
    return gradNorm.dim()-1;
}
