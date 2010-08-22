/*****************************************************************************
 *                               matrixallocate.h
 *
 * Allocate and delete two dimension array (matrix).
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef MATRIXALLOCATE_H
#define MATRIXALLOCATE_H


namespace itlab
{

    template<typename Type> void makeMatrix( Type **&, int, int );
    template<typename Type> void deleteMatrix( Type **&, int );


    #include <matrixallocate-impl.h>

}


#endif
// MATRIXALLOCATE_H
