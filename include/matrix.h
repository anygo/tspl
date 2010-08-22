/*****************************************************************************
 *                                 matrix.h
 *
 * Class template of matrix which is designed for basic linear algebra
 * operations such as:
 *              A + x    x + A    A += x    A1 + A2   A1 += A2
 *              A - x    x - A    A -= x    A1 - A2   A1 -= A2
 *              A * x    x * A    A *= x    A1 * A2   A1 *= A2
 *              A / x    x / A    A /= x    A1 / A2   A1 /= A2
 *          norm(A)       transpose(A)   diag(A)         eye(N)
 *          prod(A1,A2)   prod(A,b)      tranProd(A,B)   tranProd(A,b)
 *
 * The class also provides the basic math functions such as:
 *              cos    sin    tan    acos   asin   atan
 *              abs    exp    log    log10  sqrt   pow
 *
 * When debugging, use #define BOUNDS_CHECK above your "#include matrix.h"
 * line. When done debugging, comment out #define BOUNDS_CHECK for better
 * performance.
 *
 * Zhang Ming, 2010-01 (revised 2010-08), Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef MATRIX_H
#define MATRIX_H


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

        // computed assignment
        Matrix<Type>& operator+=( const Type& );
        Matrix<Type>& operator-=( const Type& );
        Matrix<Type>& operator*=( const Type& );
        Matrix<Type>& operator/=( const Type& );
        Matrix<Type>& operator+=( const Matrix<Type>& );
        Matrix<Type>& operator-=( const Matrix<Type>& );
        Matrix<Type>& operator*=( const Matrix<Type>& );
        Matrix<Type>& operator/=( const Matrix<Type>& );

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

    // input and output
    template<typename Type> ostream& operator<<( ostream&, const Matrix<Type>& );
    template<typename Type> istream& operator>>( istream&, Matrix<Type>& );

    // arithmetic operators
    template<typename Type> Matrix<Type> operator-( const Matrix<Type>& );
    template<typename Type> Matrix<Type> operator+( const Matrix<Type>&, const Type& );
    template<typename Type> Matrix<Type> operator+( const Type&, const Matrix<Type>& );
    template<typename Type> Matrix<Type> operator+( const Matrix<Type>&, const Matrix<Type>& );
    template<typename Type> Matrix<Type> operator-( const Matrix<Type>&, const Type& );
    template<typename Type> Matrix<Type> operator-( const Type&, const Matrix<Type>& );
    template<typename Type> Matrix<Type> operator-( const Matrix<Type>&, const Matrix<Type>& );
    template<typename Type> Matrix<Type> operator*( const Matrix<Type>&, const Type& );
    template<typename Type> Matrix<Type> operator*( const Type&, const Matrix<Type>& );
    template<typename Type> Matrix<Type> operator*( const Matrix<Type>&, const Matrix<Type>& );
    template<typename Type> Matrix<Type> operator/( const Matrix<Type>&, const Type& );
    template<typename Type> Matrix<Type> operator/( const Type&, const Matrix<Type>& );
    template<typename Type> Matrix<Type> operator/( const Matrix<Type>&, const Matrix<Type>& );

    // utilities
    template<typename Type> Type norm( const Matrix<Type>& );
    template<typename Type> void swap( Matrix<Type>&, Matrix<Type>& );
    template<typename Type> Vector<Type> sum( const Matrix<Type>& );
    template<typename Type> Vector<Type> min( const Matrix<Type>& );
    template<typename Type> Vector<Type> max( const Matrix<Type>& );

    // linear algebra
    template<typename Type> Matrix<Type> eye( int, const Type& );
    template<typename Type> Vector<Type> diag( const Matrix<Type>& );
    template<typename Type> Matrix<Type> transpose( const Matrix<Type>& );
    template<typename Type> Matrix<Type>& prod( const Matrix<Type>&, const Matrix<Type>&, Matrix<Type>& );
    template<typename Type> Vector<Type>& prod( const Matrix<Type>&, const Vector<Type>&, Vector<Type>& );
    template<typename Type> Matrix<Type> prod( const Matrix<Type>&, const Matrix<Type>& );
    template<typename Type> Vector<Type> prod( const Matrix<Type>&, const Vector<Type>& );
    template<typename Type> Matrix<Type> tranProd( const Matrix<Type>&, const Matrix<Type>& );
    template<typename Type> Vector<Type> tranProd( const Matrix<Type>&, const Vector<Type>& );
    template<typename Type> Matrix<Type> tranProd( const Vector<Type>&, const Vector<Type>& );


    #include <matrix-impl.h>

}
// namespace itlab


#endif
// MATRIX_H
