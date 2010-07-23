/*****************************************************************************
 *                               linesearch.h
 *
 * Line search algorithm based on quadratic polynomial interpolation.
 *
 * This routine is often used in orther optimation method, so it is designed
 * as a templated base class.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef LINESEARCH_H
#define LINESEARCH_H


#include <vector.h>


namespace itlab
{

    template <typename Dtype, typename Ftype>
    class LineSearch
    {

     public:

        LineSearch();
        ~LineSearch();

        Dtype getStep( Ftype &func, Vector<Dtype> &xk, Vector<Dtype> &dk,
                       int maxItr=10 );

        int getFuncNum() const;
        bool isSuccess() const;

    protected:

        int     funcNum;
        bool    success;

    };
    // class LineSearch


    #include <linesearch-impl.h>

}
// namespace itlab


#endif
// LINESEARCH_H
