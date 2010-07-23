/*****************************************************************************
 *                                 bfgs.h
 *
 * BFGS quasi-Newton method.
 *
 * This class is designed for finding the minimum value of objective function
 * in one dimension or multidimension. Inexact line search algorithm is used
 * to get the step size in each iteration. BFGS (Broyden-Fletcher-Goldfarb
 * -Shanno) modifier formula is used to compute the inverse of Hesse matrix.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef BFGS_H
#define BFGS_H


#include <matrix.h>
#include <linesearch.h>


namespace itlab
{

    template <typename Dtype, typename Ftype>
    class BFGS : public LineSearch<Dtype, Ftype>
    {

    public:

        BFGS();
        ~BFGS();

        void optimize( Ftype &func, Vector<Dtype> &x0, Dtype tol=Dtype(1.0e-6),
                       int maxItr=100 );

        Vector<Dtype> getOptValue() const;
        Vector<Dtype> getGradNorm() const;
        Dtype getFuncMin() const;
        int getItrNum() const;

    private:

        // iteration number
        int itrNum;

        // minimum value of objective function
        Dtype fMin;

        // optimal solution
        Vector<Dtype> xOpt;

        // gradient norm for each iteration
        Vector<Dtype> gradNorm;

    };
    // class BFGS


    #include <bfgs-impl.h>

}
// namespace itlab


#endif
// BFGS_H
