/*****************************************************************************
 *                                    queue.h
 *
 * A simple queue implemented by C++ template class .
 *
 * Zhang Ming, 2009-10, Xi'an Jiaotong University.
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

        bool isEmpty() const;
        void makeEmpty();

        void enqueue( const Type &x );
        void dequeue();
        void dequeue( Type &x );
        void getFront( Type &x );

    private:

        LinkNode<Type> *front,
                       *rear;

        void handleUnderflow();

    };


    #include <queue-impl.h>

}
// namespace itlab


#endif
// QUEUE_H
