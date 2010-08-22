/*****************************************************************************
 *                                 timing.h
 *
 * Making a coarse estimation for programm's running time. The time unit
 * is second.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef TIMING_H
#define TIMING_H


#include <ctime>


inline static double seconds()
{
	const double secs_per_tick = 1.0 / CLOCKS_PER_SEC;
	return ( double(clock()) ) * secs_per_tick;
}


namespace itlab
{

    class Timing
    {

        public:

            Timing();
            ~Timing();

            void start();
            void stop();
            double read();

        private:

            bool    running;
            double  startTime;
            double  total;

    };
    // class Timing


    #include <timing-impl.h>

}


#endif
//	TIMING_H
