/*****************************************************************************
 *                                    random.h
 *
 * Random Number Generator.
 *
 * This class can generate an "int" random number or an "int"/"double" random
 * number in interval [a,b]. The default initial state is set to 1, of cause
 * it can be set to any integer by routine "seed(int)".
 *
 * Zhang Ming, 2010-04, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef RANDOM_H
#define RANDOM_H


namespace itlab
{

    class Random
    {

    public:

        explicit Random( int initValue=1 );
        ~Random();

        void seed( int value );
        int random();
        int random( int low, int high );
        double random( double low, double high );

    private:

        static const int A = 48271;
        static const int M = 2147483647;
        static const int Q = 44488;
        static const int R = 3399;

        int state;

    };


    #include <random-impl.h>

}
// namespace itlab


#endif
// RANDOM_H
