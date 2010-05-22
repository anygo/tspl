/*****************************************************************************
 *                                    binaryheap.h
 *
 * Minimum binary heap implemented by C++ template class.
 *
 * This class provides the following operatins of a minimum binary heap:
 *      build a heap
 *      insert an element into the heap
 *      find the minimum element in the heap
 *      delete the minimum element in the heap
 *
 * The defualt initial size of the heap is set to 20. If the elements number
 * exceed initial size, then it will be extended by a factor of 2.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#ifndef BINARYHEAP_H
#define BINARYHEAP_H


#include <iostream>
#include <cstdlib>
#include <constants.h>


using namespace std;


namespace itlab
{

    template <typename Type>
    class BinaryHeap
    {

    public:

        explicit BinaryHeap( int maxSize = INITSIZE );
        BinaryHeap( Type *array, int length );
        ~BinaryHeap();

//        BinaryHeap( const BinaryHeap<Type> &rhs );
//        BinaryHeap<Type>& operator=( const BinaryHeap<Type> &rhs );

        inline bool isEmpty() const;
        inline void makeEmpty();

        inline void insert( const Type &x );
        inline void findMin( Type &x );
        inline void deleteMin();
        inline void deleteMin( Type &minItem );

    private:

        Type    *elements;

        int currentSize;
        int capacity;

        void filterDown( int hole );
        void filterUp( int hole );

        void handleOverflow();
        inline void handleUnderflow();

    };
    // class BinaryHeap


    #include <binaryheap-impl.h>

}
// namespace itlab


#endif
// BINARYHEAP_H
