/*****************************************************************************
 *                                    stack.h
 *
 * A C++ template class implemented stack.
 *
 * The defualt initial size of the stack is set to 20. If the elements number
 * exceed initial size, then it will be extended by a factor of 2.
 *
 * Zhang Ming, 2009-10
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

        inline bool isEmpty() const;
        inline void makeEmpty();

        inline void push( const Type &x );
        inline void pop();
        inline void pop( Type &x );
        inline void getTop( Type &x );

    private:

        int top;
        int capacity;

        Type *elements;

        void handleOverflow();
        inline void handleUnderflow();

    };
    // class Stack


    #include <stack-impl.h>

}
// namespace itlab


#endif
// STACK_H
