/*****************************************************************************
 *                                    sort.h
 *
 * Some sort algorithms.
 *
 * This file includes several usually used sorting algorithm, such as: bubble
 * sorting, selection sorting, insertion sorting, quick sorting, merging
 * sorting, and heap sorting.
 *
 * Zhang Ming, 2010-07, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef SORT_H
#define SORT_H


#include <vector>


using namespace std;


namespace itlab
{

    template<typename Type> void bubbleSort( vector<Type>&, int, int );
    template<typename Type> void selectSort( vector<Type>&, int, int );
    template<typename Type> void insertSort( vector<Type>&, int, int );
    template<typename Type> void quickSort( vector<Type>&, int, int );
    template<typename Type> void mergSort( vector<Type>&, int, int );
    template<typename Type> void heapSort( vector<Type>&, int, int );

    template<typename Type> const Type& median3( vector<Type>&, int, int );
    template<typename Type> void merg( vector<Type>&, int, int, int, int );
    template<typename Type> void filterDown( vector<Type>&, int, int );


    #include <sort-impl.h>

}
// namespace itlab


#endif
// SORT_H
