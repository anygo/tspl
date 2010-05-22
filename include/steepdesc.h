/*****************************************************************************
 *                               steepdesc.h
 *
 * Steepest descent optimal method( gradient algorithm ).
 *
 * This class is designed for finding the minimum value of objective function
 * in one dimension or multidimension. Inexact line search algorithm is used
 * to get the step size in each iteration.
 *
 * Zhang Ming, 2010-03
 *****************************************************************************/


#ifndef STEEPDESC_H
#define STEEPDESC_H


#include <linesearch.h>


namespace itlab
{

    template <typename Dtype, typename Ftype>
    class SteepDesc : public LineSearch<Dtype, Ftype>
    {

    public:

        SteepDesc();
        ~SteepDesc();

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
    // class SteepDesc


    #include <steepdesc-impl.h>

}
// namespace itlab


#endif
// STEEPDESC_H
