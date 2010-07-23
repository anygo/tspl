/*****************************************************************************
 *                               random-impl.h
 *
 * Implementation for Random class.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


/**
 * constructors and destructor
 */
Random::Random( int initValue )
{
    if( initValue < 0 )
        initValue += M;

    state = initValue;
    if( state == 0 )
        state = 1;
}

Random::~Random()
{
}


/**
 * Set the internal state.
 */
inline void Random::seed( int value )
{
    state = value;
}


/**
 * Return a pseudorandom int, and then change the internal state.
 */
int Random::random()
{
    int tmpState = A*( state%Q ) - R*( state/Q );

    if( tmpState >= 0 )
        state = tmpState;
    else
        state = tmpState + M;

    return state;
}


/**
 * Return an int in the closed range [low, high], and
 * then change the internal state.
 */
inline int Random::random( int low, int high )
{
    double normalization = random() / double(M);
    return (int) ( low + normalization*(high-low) );
}


/**
 * Return a pseudorandom double in the open range (low, high),
 * and then change the internal state.
 */
inline double Random::random( double low, double high )
{
    double normalization = random() / double(M);
    return (double) ( low + normalization*(high-low) );
}
