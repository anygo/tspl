/*****************************************************************************
 *                                    queue.h
 *
 * A simple queue implemented by C++ template class .
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include <cstdlib>


using namespace std;


namespace itlab
{

    /**
     * Queue Node
     */
    template <typename Type>
    struct LinkNode
    {
        Type data;
        LinkNode<Type> *next;

        LinkNode() : next(NULL)
        { }
        LinkNode( const Type &x, LinkNode<Type> *p=NULL ) : data(x), next(p)
        { }
    };


    /**
     * Queue
     */
    template <typename Type>
    class Queue
    {

    public:

        Queue();
        ~Queue();

//        Queue( const Queue<Type> &rhs);
//        Queue<Type>& operator=( const Queue<Type> &rhs);

        inline bool isEmpty() const;
        inline void makeEmpty();

        inline void enqueue( const Type &x );
        inline void dequeue( Type &x );
        inline void getFront( Type &x );

    private:

        LinkNode<Type> *front,
                       *rear;

        inline void handleUnderflow();

    };


    #include <queue-impl.h>

}
// namespace itlab


#endif
// QUEUE_H
