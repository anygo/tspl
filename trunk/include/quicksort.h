/*****************************************************************************
 *                                    quicksort.h
 *
 * Quick sort algorithm.
 *
 * If the number of the sorted items is less than 20, the "inserting sort"
 * algorithm is used, or the recursive version "quick sort" algorithm is used.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#ifndef QUICKSORT_H
#define QUICKSORT_H


#include <vector>
#include <algorithm>


using namespace std;


namespace itlab
{

    /**
     * Insertion sort routine for that is used by quicksort.
     * "a"      ---->   array of Comparable items.
     * "left"   ---->   the left-most index of the subarray.
     * "right"  ---->   the right-most index of the subarray.
     */
    template <typename Type>
    void insertSort( vector<Type> &a, int left, int right )
    {
        for( int p=left+1; p<=right; p++ )
        {
            Type tmp = a[p];
            int j;

            for( j=p; j>left && tmp<a[j-1]; --j )
                a[j] = a[j-1];
            a[j] = tmp;
        }
    }


    /**
     * Return median of left, center, and right.
     * Order these and hide the pivot.
     */
    template <typename Type>
    const Type& median3( vector<Type> &a, int left, int right )
    {
        int center = (left+right) / 2;

        if( a[center] < a[left] )
            swap( a[left], a[center] );

        if( a[right] < a[left] )
            swap( a[left], a[right] );

        if( a[right] < a[center] )
            swap( a[center], a[right] );

        swap( a[center], a[right-1] );

        return a[right-1];
    }


    /**
     * Internal quicksort method that makes recursive calls.
     * Uses median-of-three partitioning and a cutoff of 20.
     * "a"      ---->   array of Comparable items.
     * "left"   ---->   the left-most index of the subarray.
     * "right"  ---->   the right-most index of the subarray.
     */
    template <typename Type>
    void quickSort( vector<Type> &a, int left, int right )
    {
        if( left+20 <= right )
        {
            Type pivot = median3( a, left, right );

            // begin partitioning
            int i = left, j = right-1;
            for( ; ; )
            {
                while( a[++i] < pivot ) { }
                while( pivot < a[--j] ) { }

                if( i < j )
                    swap( a[i], a[j] );
                else
                    break;
            }

            // Restore pivot
            swap( a[i], a[right-1] );

            // Sort small elements
            quickSort( a, left, i-1 );

            // Sort large elements
            quickSort( a, i+1, right );
        }
        else
        {
            insertSort( a, left, right );
        }
    }

}
// namespace itlab


#endif
// QUICKSORT_H
