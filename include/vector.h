/*****************************************************************************
 *                                 vector.h
 *
 * Class template of vector which is designed for basic linear algebra
 * operations such as:
 *                      v  +   k    k  +   v    v  +=  k
 *                      v  -   k    k  -   v    v  -=  k
 *                      v  *   k    k  *   v    v  *=  k
 *                      v  /   k    k  /   v    v  /=  k
 *                      v1  +  v2   v1 +=  v2
 *                      v1  -  v2   v1 -=  v2
 *                      v1  *  v2   v1 *=  v2
 *                      v1  /  v2   v1 /=  v2
 *                      -v
 *
 *                      norm( v )   dotProd( v1, v2 )
 *
 * When debugging, use #define BOUNDS_CHECK above your "#include vector.h"
 * line. When done debugging, comment out #define BOUNDS_CHECK for better
 * performance.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
#include <cmath>
#include <cassert>


using namespace std;


namespace itlab
{

    template <typename Type>
    class Vector
    {

    public:

        typedef         Type*   iterator;
        typedef const   Type*   const_iterator;

        // constructors and destructor
        Vector();
        Vector( const Vector<Type> &v );
        Vector( int length, const Type &x = Type(0) );
        Vector( int length, const Type *array );
        ~Vector();

        // assignments
        Vector<Type>& operator=( const Vector<Type> &v );
        Vector<Type>& operator=( const Type &x );

        // accessors
        Type& operator[]( int i );
        const Type& operator[]( int i ) const;
        Type& operator()( int i );
        const Type& operator()( int i ) const;

        // iterators
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
//        iterator begin()
//        {   return pv0; }
//        const iterator begin() const
//        {   return pv0; }
//        iterator end()
//        {   return pv0+nRow; }
//        const iterator end() const
//        {   return pv0+nRow; }

        // type conversion
        operator Type*();
        operator const Type*() const;

        // others
        int size() const;
        int dim() const;
        Vector<Type>& resize( int length );
        Vector<Type> reverse();

    private:

        // data pointer for 0-offset indexing
        Type *pv0;

        // data pointer for 1-offset indexing
        Type *pv1;

        // the row number of vector
        int	 nRow;

        void init( int length );
        void copyFromArray( const Type *v );
        void setByScalar( const Type &x );
        void destroy();

    };
    // class Vector


    #include <vector-impl.h>

}
// namespace itlab


#endif
// VECTOR_H
