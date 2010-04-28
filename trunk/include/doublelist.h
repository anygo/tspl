/*****************************************************************************
 *                                 doublelist.h
 *
 * Double List.
 *
 * This class template includes a smart pointer supporting "*", "++", "--",
 * "==" and "!=" operations,  which makes it easy to implement the frequently
 * used operations, such as "is empty", "make empty", "begin", "end", "fornt",
 * "back", "push front", "push back", "pop front", "pop back", "insert",
 * "erase" and so on.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#ifndef DOUBLELIST_H
#define DOUBLELIST_H


#include <iostream>


namespace itlab
{

    /**
     * List Node
     */
    template <typename Type>
    struct Node
    {
        Type        data;
        Node<Type>  *prev;
        Node<Type>  *next;

        Node( const Type &d=Type(), Node<Type> *p=NULL, Node<Type> *n=NULL )
          : data(d), prev(p), next(n)
        { }
    };
    // class Node


    /**
     * List Iterator
     */
    template <typename Type> class DList;

    template <typename Type>
    class ListItr
    {

        friend class DList<Type>;

    public:

        ListItr();
        ListItr( Node<Type> *p );
        ~ListItr();

        inline Type& operator*();
        inline const Type& operator*() const;

        inline ListItr& operator++();
        inline ListItr operator++( int );

        inline ListItr& operator--();
        inline ListItr operator--( int );

        inline bool operator==( const ListItr &rhs ) const;
        inline bool operator!=( const ListItr &rhs ) const;

    private:

        Node<Type> *current;

    };
    // class ListItr


    /**
     * Double List
     */
    template <typename Type>
    class DList
    {

    public:

        DList();
        DList( const DList<Type> &rhs );
        ~DList();

        DList<Type>& operator=( const DList<Type> &rhs );

        typedef ListItr<Type>   Iterator;
        typedef const Iterator  Const_Iterator;

        inline void clear();
        inline bool isEmpty() const;
        inline int size() const;

        inline Iterator begin();
        inline Const_Iterator begin() const;

        inline Iterator end();
        inline Const_Iterator end() const;

        inline Type& front();
        inline const Type& front() const;

        inline Type& back();
        inline const Type& back() const;

        inline void pushFront( const Type &x );
        inline void pushBack( const Type &x );

        inline void popFront();
        inline void popBack();

        Iterator insert( Iterator itr, const Type &x );
        Iterator erase( Iterator itr );
        Iterator erase( Iterator start, Iterator end );

    private:

        int         listSize;
        Node<Type>  *head;
        Node<Type>  *tail;

        inline void init();

    };
    // class DList


    #include <doublelist-impl.h>

}
// namespace itlab


#endif
// DOUBLELIST_H
