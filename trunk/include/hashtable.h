/*****************************************************************************
 *                                    hashtable.h
 *
 * Hash table implemented by C++ template class.
 *
 * This class provides "search", "insert" and "remove" operations by using a
 * Hash Table. We use the quadratic probing method to prevent the element
 * number exceeding half of the total table size.
 *
 * Zhang Ming, 2009-10, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


namespace itlab
{

    template <typename Object, typename Key>
    class HashTable
    {

    public:

        explicit HashTable( int size=7 );
        HashTable( const HashTable<Object, Key> &rhs );
        ~HashTable();
        HashTable<Object, Key>& operator=( const HashTable<Object, Key> &rhs );

        void makeEmpty();

        bool search( const Key k, Object &x ) const;
        bool insert( const Object &x );
        bool remove( const Key k, Object &x );

        enum EntryFlag { ACTIVE, EMPTY, DELETED };

    private:

        struct HashEntry
        {
            Object      element;
            EntryFlag   info;

            HashEntry( const Object &x=Object(), EntryFlag i=EMPTY )
              : element(x), info(i)
            { }
        };

        HashEntry *array;

        int currentSize;
        int tableSize;

        bool isActive( int currentPos ) const;
        int findPos( const Key k ) const;
        void rehash( );

        int myhash( const Key k ) const;

    };


    bool isPrime( int n );
    int  nextPrime( int n );


    #include <hashtable-impl.h>

}
// namespace itlab


#endif
// HASHTABLE_H
