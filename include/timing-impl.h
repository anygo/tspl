/*****************************************************************************
 *                               timing-impl.h
 *
 * Implementation for Timing class.
 *
 * Zhang Ming, 2010-01
 *****************************************************************************/


/**
 * constructor and destructor
 */
Timing::Timing() : running(false), startTime(0), total(0)
{
}

Timing::~Timing()
{
}


/**
 * timing start
 */
inline void Timing::start()
{
	running = true;
	total = 0;
	startTime = seconds();
}


/**
 * timing stop
 */
inline void Timing::stop()
{
	if( running )
	{
		 total += ( seconds() - startTime );
		 running = false;
	}
}


/**
 * Get the time between start() and stop().
 */
inline double Timing::read()
{
	if( running )
		stop();

	return total;
}
