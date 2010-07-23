/*****************************************************************************
 *                                    matrixallocate.h
 *
 * Allocate and delete two dimension array (matrix).
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef MATRIXALLOCATE_H
#define MATRIXALLOCATE_H


namespace itlab
{

    /**
     * Allocate matrix by specified rows and columns.
     */
    template<typename Type>
    inline void makeMatrix( Type **&m, int rows, int cols )
    {
        m = new Type*[rows];
        for( int i=0; i<rows; ++i )
            m[i] = new Type[cols];
    }


    /**
     * Delete the matrix with specified rows.
     */
    template<typename Type>
    inline void deleteMatrix( Type **&m, int rows )
    {
        for( int i=0; i<rows; ++i )
            delete []m[i];

        delete []m;
        m = 0;
    }

}


#endif
// MATRIXALLOCATE_H
