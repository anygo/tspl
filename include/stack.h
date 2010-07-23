/*****************************************************************************
 *                                    stack.h
 *
 * A C++ template class implemented stack.
 *
 * The defualt initial size of the stack is set to 20. If the elements number
 * exceed initial size, then it will be extended by a factor of 2.
 *
 * Zhang Ming, 2009-10, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef STACK_H
#define STACK_H


#include <iostream>
#include <cstdlib>
#include <constants.h>


using namespace std;


namespace itlab
{

    template <typename Type>
    class Stack
    {

    public:

        explicit Stack( int maxSize = INITSIZE );
        Stack( const Stack<Type> &rhs );
        ~Stack();
        Stack<Type>& operator=( const Stack<Type> &rhs );

        bool isEmpty() const;
        void makeEmpty();

        void push( const Type &x );
        void pop();
        void pop( Type &x );
        void getTop( Type &x );

    private:

        int top;
        int capacity;

        Type *elements;

        void handleOverflow();
        void handleUnderflow();

    };
    // class Stack


    #include <stack-impl.h>

}
// namespace itlab


#endif
// STACK_H
