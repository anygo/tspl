/*****************************************************************************
 *                                 matrix.h
 *
 * Class template of matrix which is designed for basic linear algebra
 * operations such as:
 *                      A  +   x    x  +   A    A  +=  x
 *                      A  -   x    x  -   A    A  -=  x
 *                      A  *   x    x  *   A    A  *=  x
 *                      A  /   x    x  /   A    A  /=  x
 *                      A1  +  A2   A1 +=  A2
 *                      A1  -  A2   A1 -=  A2
 *                      A1  *  A2   A1 *=  A2
 *                      A1  /  A2   A1 /=  A2
 *
 *          norm( A )       transpose( A )   diag( A )          inverse( A )
 *          prod( A1, A2 )  prod( A, b )     tranProd( A, B )   tranProd( A, b )
 *
 * When debugging, use #define BOUNDS_CHECK above your "#include matrix.h"
 * line. When done debugging, comment out #define BOUNDS_CHECK for better
 * performance.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef MATRIX_H
#define MATRIX_H


#include <constants.h>
#include <vector.h>


namespace itlab
{

    template <typename Type>
    class Matrix
    {

    public:

        // constructors and destructor
        Matrix();
        Matrix( const Matrix<Type> &A );
        Matrix( int rows, int columns, const Type &x = Type(0) );
        Matrix( int rows, int columns, const Type *v );
        ~Matrix();

        // assignments
        Matrix<Type>& operator=( const Matrix<Type> &A );
        Matrix<Type>& operator=( const Type &x );

        // accessors
        Type* operator[]( int i );
        const Type* operator[]( int i ) const;
        Type& operator()( int row, int column );
        const Type& operator()( int row, int column ) const;

        // type conversion
        operator Type**();
        operator const Type**() const;

        // others
        long size() const;
        int dim( int dimension ) const;
        int rows() const;
        int cols() const;
        Matrix<Type>& resize( int rows, int columns );
        Vector<Type> getRow( int row ) const;
        Vector<Type> getColumn( int column ) const;
        void setRow( const Vector<Type> &v, int row );
        void setColumn( const Vector<Type> &v, int column );

    private:

        // 0-based and 1-based data pointer
        Type *pv0, *pv1;

        // 0-based and 1-based row pointer's pointer
        Type **prow0, **prow1;

        // row number, column number and total number
        int	 nRow;
        int	 nColumn;
        long nTotal;

        void init( int rows, int columns );
        void copyFromArray( const Type *v );
        void setByScalar( const Type &x );
        void destroy();

    };
    // class Matrix


    #include <matrix-impl.h>

}
// namespace itlab


#endif
// MATRIX_H
