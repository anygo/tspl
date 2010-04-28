/*****************************************************************************
 *                                 statistics.h
 *
 * Some generally used routines about probability and statistics, such as
 * minimum, maximum, median, mean, variance, standard variance, skew, kurtosis
 * and the PDF(probability density function).
 *
 * Zhang Ming, 2010-03
 *****************************************************************************/


#ifndef STATISTICS_H
#define STATISTICS_H


#include <vector.h>


namespace itlab
{

    /**
     * Get the minimum value of a sequence.
     */
    template <typename Type>
    Type min( const Vector<Type> &v )
    {
        Type m = v[0];
        for( int i=1; i<v.size(); ++i )
            if( m > v[i] )
                m = v[i];

        return m;
    }


    /**
     * Get the maximum value of a sequence.
     */
    template <typename Type>
    Type max( const Vector<Type> &v )
    {
        Type M = v[0];
        for( int i=1; i<v.size(); ++i )
            if( M < v[i] )
                M = v[i];

        return M;
    }


    /**
     * Get the median value of a sequence.
     */
    template <typename Type>
    Type mid( const Vector<Type> &v )
    {
        Vector<Type> tmp(v);
        int index,
            N = tmp.size(),
            K = N/2;

        for( int k=0; k<=K; ++k )
        {
            index = k;
            for( int i=k+1; i<N; ++i )
                if( tmp[index] < tmp[i] )
                    index = i;

            if( index != k )
                swap( tmp[index], tmp[k] );
        }

        return tmp[K];
    }


    /**
     * Mean value of a (random) sequence.
     */
    template <typename Type>
    inline Type mean( const Vector<Type> &v )
    {
        return sum(v) / v.dim();
    }


    /**
     * Variance of a (random) sequence.
     */
    template <typename Type>
    Type var( const Vector<Type> &v )
    {
        int N = v.dim();
        Type m = mean( v );
        Type var = 0;

        for( int i=0; i<N; ++i )
            var += ( v[i]-m ) * ( v[i]-m );
        if( N>1 )
            var /= N-1;
//        var /= N;

        return  var;
    }


    /**
     * Standard variance of a (random) sequence.
     */
    template <typename Type>
    inline Type stdVar( const Vector<Type> &v )
    {
        return sqrt( var(v) );
    }


    /**
     * Make Standardization of a (random) sequence.
     */
    template <typename Type>
    inline Vector<Type> standard( const Vector<Type> &v )
    {
        return (v-mean(v)) / stdVar(v);
    }


    /**
     * Skew of a (random) sequence.
     */
    template <typename Type>
    Type skew( const Vector<Type> &v )
    {
        Type m = mean(v),
             s = stdVar(v),
             tmp = 0,
             result = 0;

        for( int i=0; i<v.dim(); ++i )
        {
            tmp = (v[i]-m);
            result += tmp * tmp * tmp;
        }
        result /= v.size()*s*s*s;

        return result;
    }


    /**
     * Kurtosis of a (random) sequence.
     */
    template <typename Type>
    Type kurt( const Vector<Type> &v )
    {
        Type m = mean(v),
             d = var(v),
             tmp = 0,
             result = 0;

        for( int i=0; i<v.dim(); ++i )
        {
            tmp = (v[i]-m);
            result += tmp * tmp * tmp * tmp;
        }
        result /= v.size()*d*d;

        return result-3;
    }


    /**
     * Fast algorithm of PDF(probability density function) estimation
     * of a random sequence. The binning method and third-order cardinal
     * spline kernel function are used for reducing the computation
     * amount. Lambda is the coeffcient of kernel bandwidth "kb", the
     * optimal "kb"( 2.11/Lx^0.2 * std(xn) ) is chosen when "lambda=1.0".
     * If you want to compute more point's probability, you can use a
     * smaller "lambda", such as 0.5, in this case you'd better make a
     * smoothing for the result.
     */
    template <typename Type>
    Vector<Type> pdf( Vector<Type> &xn, Type lambda=1 )
    {
        int i, k,
            tmpInt,
            Lpx,
            Lx = xn.size();

        Type tmpDbl,
             kb = Type( lambda * 2.107683*stdVar(xn)/pow(Lx, 0.2) );

        Vector<Type> r(Lx);
        Vector<int>  pos(Lx),
                     index(Lx);

        // binning the data into blocks, each block width is "kb"
        for( i=0; i<Lx; ++i )
        {
            tmpDbl = xn[i] / kb;
            pos[i] = floor(tmpDbl);
            r[i] = tmpDbl - pos[i];
        }

        // compute the blocks index
        tmpInt = 1 - min(pos);
        for( i=0; i<Lx; ++i )
            index[i] = pos[i]+tmpInt;

        // weights for left, middle and right block
        Vector<Type> weightl(Lx),
                     weightc(Lx),
                     weightr(Lx);
        for( i=0; i<Lx; ++i )
        {
            tmpDbl = r[i];
            weightl[i] = (1-tmpDbl)*(1-tmpDbl) / Type(2.0);
            weightc[i] = Type(0.5) + tmpDbl*(1-tmpDbl);
            weightr[i] = tmpDbl*tmpDbl / Type(2.0);
        }

        Lpx = max(index) - min(index) + 3;
        Vector<Type> px(Lpx);

        // compute probability density function
        for( i=0; i<Lx; ++i )
        {
            k = index[i];
            px[k-1] += weightl[i] / Lx ;
            px[k]   += weightc[i] / Lx ;
            px[k+1] += weightr[i] / Lx ;
        }

        return px;
    }

}
// namespace itlab


#endif
// STATISTICS_H
