/*****************************************************************************
 *                                  utilities.h
 *
 * Some usable routines converted from "Matlab", which are used in wavelet
 * transform and time-frequency analysis, such as "filp"(same to .reverse()),
 * "dyadup", "wkeep", "wextend" and so on.
 *
 * Warning: the convolution routine "conv" is implemented by it's definition
 * in time domain, so if the sequence to be convoluted are long, you should
 * use the fast convolution algorithm "fastConv", which is implemented in
 * frequency domain by usin FFT.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


#ifndef UTILITIES_H
#define UTILITIES_H


#include <string>
#include <vector.h>


namespace itlab
{

    /**
     * Modulus after division. return a integer in the range of 0 to n-1.
     * e.g. -1%5=-1, mod(-1,5)=4
     */
    int mod( int m, int n )
    {
        if( n != 0 )
        {
            int r = m % n;
            if( r < 0 )
                r += n;

            return r;
        }
        else
        {
            cerr << "The dividend shouldn't be zero." << endl;
            return 0;
        }
    }


    /**
     * Rounds the elements of a/b to the nearest integers
     * greater than or equal to a/b.
     * e.g. ceil(10,2) = 5, ceil(10,3)=4.
     */
    int ceil( int m, int n )
    {
        if( n != 0 )
        {
            int q = m / n;
            if( m%n != 0 )
                q += 1;

            return q;
        }
        else
        {
            cerr << "The dividend shouldn't be zero." << endl;
            return 0;
        }
    }


    /**
     * To determine the input integer is or isn't the power of positive
     * integer of 2. If it is, return true, or return false.
     */
    bool isPower2( int n )
    {
        int bits = 0;
        while( n )
        {
            bits += n & 1;
            n >>= 1;
        }

        return ( bits == 1 );
    }


    /**
     * Get binary log of integer argument -- exact if n is a power of 2.
     */
    int fastLog2( int n )
    {
        int log = -1;
        while(n)
        {
            log++;
            n >>= 1;
        }

        return log;
    }


    /**
	 * Generates a row vector of n points linearly spaced between and
	 * including a and b.
	 */
	template <typename Type>
	Vector<Type> linspace( Type a, Type b, int n )
	{
		if( a > b )
            swap( a, b );

		if( n < 1 )
		    return Vector<Type>();
		else if( n == 1 )
		    return Vector<Type>( 1, a );
        else
        {
            Type dx = (b-a) / (n-1);

            Vector<Type> tmp(n);
            for( int i=0; i<n; ++i )
                tmp[i] = a + i*dx;

            return tmp;
        }
	}


    /**
     * Flip vector left to right.
     */
    template <typename Type>
    Vector<Type> flip( const Vector<Type> &v )
    {
        int length = v.dim();
        Vector<Type> tmp( length );

        for( int i=0; i<length; ++i )
            tmp[i] = v(length-i);

        return tmp;
    }


    /**
     * dyadic upsampling
     * w = dyadup(v, evenodd), where v is a vector, returns an extended
     * copy of vector v obtained by inserting zeros. Whether the zeros
     * are inserted as even- or odd-indexed elements of w depends on the
     * value of positive integer evenodd:
     * If evenodd is even, then w[2k]=0, w[2k+1]=v[k], w.size()=2*v.size()+1.
     * If evenodd is odd, then w[2k]=v[k], w[2k+1]=0. w.size()=2*v.size()-1.
     */
    template <typename Type>
    Vector<Type> dyadUp( const Vector<Type> &v, int evenodd )
    {
        int length = v.dim();
        Vector<Type> tmp;

        if( evenodd%2 == 0 )
        {
            tmp.resize( 2*length+1 );
            for( int i=0; i<length; ++i )
            {
                tmp[2*i] = 0;
                tmp[2*i+1] = v[i];
            }
            tmp[2*length] = 0;
        }
        else
        {
            tmp.resize( 2*length-1 );
            for( int i=0; i<length-1; ++i )
            {
                tmp[2*i] = v[i];
                tmp[2*i+1] = 0;
            }
            tmp[2*length-2] = v[length-1];
        }

        return tmp;
    }


    /**
     * dyadic downsampling
     * w = dyadup(v, evenodd), where v is a vector, returns a version of v
     * that has been downsampled by 2. Whether w contains the even or odd
     * indexed samples of v depends on the value of positive integer evenodd:
     * If evenodd is even, then w[k]=v[2*k], w.size()=(v.size()+1)/2.
     * If evenodd is odd, then w[k]=v[2*k+1], w.size()=v.size()/2.
     */
    template <typename Type>
    Vector<Type> dyadDown( Vector<Type> &v, int evenodd )
    {
        int length = v.dim();
        Vector<Type> tmp;

        if( evenodd%2 == 0 )
        {
            tmp.resize( (length+1)/2 );
            for( int i=0; i<tmp.dim(); ++i )
                tmp[i] = v[2*i];
        }
        else
        {
            tmp.resize( length/2 );
            for( int i=0; i<tmp.dim(); ++i )
                tmp[i] = v[2*i+1];
        }

        return tmp;
    }


    /**
     * Keep part of vector.
     * For a vector, w = wkeep(v,L,opt) extracts the vector w from the vector v.
     * The length of w is L. If direction = "center" ("left", "rigth", respectively),
     * w is the central (left, right, respectively) part of v. w = wkeep(x,L) is
     * equivalent to w = wkeep(v,L,"center").
     * w = wkeep(v,L,first) returns the vector v[first] to v[first+L-1].
     */
    template <typename Type>
    Vector<Type> wkeep( const Vector<Type> &v, int length, int first )
    {
        Vector<Type> tmp(length);

        if( ( 0 < length ) && ( length <= v.dim()-first ) )
        {
            for( int i=0; i<length; ++i )
                tmp[i] = v(first+i);

            return tmp;
        }
        else
        {
            cerr << "Invalid length input." << endl;
            return tmp;
        }
    }

    template <typename Type>
    Vector<Type> wkeep( const Vector<Type> &v, int length, const string &direction )
    {
        int lv = v.dim();
        Vector<Type> tmp(length);

        if( ( 0 <= length ) && ( length <= lv ) )
        {
            if( direction == "right" )
                for( int i=0; i<length; ++i )
                    tmp[i] = v[lv-length+i];
            else if( direction == "left" )
                for( int i=0; i<length; ++i )
                    tmp[i] = v[i];
            else
            {
                int first = (lv-length)/2;
                for( int i=0; i<length; ++i )
                    tmp[i] = v[first+i];
            }

            return tmp;
        }
        else
        {
            cerr << "Invalid length input." << endl;
            return tmp;
        }
    }


    /**
     * extend vector
     * The extension types are specified by the string "direction", include "left",
     * "right" and "both". The default type is "both". The valid extension modes,
     * which specified by strint "mode" are: zero padding("zpd"), periodized
     * extension("ppd") and symetirc extension("sym"). The default mode is "zpd".
     */
    template <typename Type>
    Vector<Type> wextend( const Vector<Type> &v, int extLength,
                          const string &direction, const string &mode )
    {
        if( extLength >= 0 )
        {
            Vector<Type> tmp;
            int lv = v.dim();

            if( direction == "right" )
            {
                tmp.resize( lv+extLength );
                for( int i=0; i<lv; ++i )
                    tmp[i] = v[i];

                if( mode == "sym" )
                    for( int i=0; i<extLength; ++i )
                        tmp[lv+i] = v[lv-1-i];
                else if( mode == "ppd" )
                    for( int i=0; i<extLength; ++i )
                        tmp[lv+i] = v[i];
                else
                    for( int i=0; i<extLength; ++i )
                        tmp[lv+i] = 0;
            }
            else if( direction == "left" )
            {
                tmp.resize( lv+extLength );

                if( mode == "sym" )
                    for( int i=0; i<extLength; ++i )
                        tmp[i] = v[extLength-1-i];
                else if( mode == "ppd" )
                    for( int i=0; i<extLength; ++i )
                        tmp[i] = v[lv-extLength+i];
                else
                    for( int i=0; i<extLength; ++i )
                        tmp[i] = 0;

                for( int i=0; i<lv; ++i )
                    tmp[i+extLength] = v[i];
            }
            else
            {
                tmp.resize( lv+2*extLength );
                for( int i=0; i<lv; ++i )
                    tmp[i+extLength] = v[i];

                if( mode == "sym" )
                    for( int i=0; i<extLength; ++i )
                    {
                        tmp[i] = v[extLength-1-i];
                        tmp[lv+extLength+i] = v[lv-1-i];
                    }
                else if( mode == "ppd" )
                    for( int i=0; i<extLength; ++i )
                    {
                        tmp[i] = v[lv-extLength+i];
                        tmp[lv+extLength+i] = v[i];
                    }
                else
                    for( int i=0; i<extLength; ++i )
                    {
                        tmp[i] = 0;
                        tmp[lv+extLength+i] = 0;
                    }
            }
            return tmp;
        }
        else
        {
            cerr << "The extesion length should be greater zero." << endl;
            return Vector<Type>(0);
        }
    }


    /**
     * convolution and ploynonal multiplication
     * x=conv(s,f), convolves v s and f, s.size() >= f.size().
     */
    template <typename Type>
    Vector<Type> conv( const Vector<Type> &signal, const Vector<Type> &filter )
    {
        int sigLength = signal.dim();
        int filLength = filter.dim();
        int length = sigLength + filLength - 1;

        Vector<Type> x(length);

        for( int i=1; i<=length; ++i )
        {
            x(i) = 0;
            if( i < filLength )
                for( int j=1; j<=i; ++j )
                    x(i) += filter(j) * signal(i-j+1);
            else if( i <= sigLength )
                for( int j=1; j<=filLength; ++j )
                    x(i) += filter(j) * signal(i-j+1);
            else
                for( int j=i-sigLength+1; j<=filLength; ++j )
                    x(i) += filter(j) * signal(i-j+1);
        }
        return x;
    }

}
// namespace itlab


#endif
// UTILITIES_H
