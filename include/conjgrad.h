/*****************************************************************************
 *                               confgrad.h
 *
 * Conjugate gradient optimal method.
 *
 * This class is designed for finding the minimum value of objective function
 * in one dimension or multidimension. Inexact line search and PRP (Polak-
 * Ribiere-Polyak) formula are used to get the step size and conjgate
 * coefficient "beta" in each iteration.
 *
 * Zhang Ming, 2010-03
 *****************************************************************************/


#ifndef CONJGRAD_H
#define CONJGRAD_H


#include <linesearch.h>
#include <utilities.h>


namespace itlab
{

    template <typename Dtype, typename Ftype>
    class ConjGrad : public LineSearch<Dtype, Ftype>
    {

    public:

        ConjGrad();
        ~ConjGrad();

        void optimize( Ftype &func, Vector<Dtype> &x0, int reLen,
                       Dtype tol=Dtype(1.0e-6), int maxItr=100 );

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
    // class ConjGrad


    #include <conjgrad-impl.h>

}
// namespace itlab


#endif
// CONJGRAD_H
