/*****************************************************************************
 *                               vector-impl.h
 *
 * Implementation for Vector math functions.
 *
 * Zhang Ming, 2010-08, Xi'an Jiaotong University.
 *****************************************************************************/


template <typename Type>
Vector<Type> abs( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = abs(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> cos( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = cos(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> sin( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = sin(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> tan( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = tan(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> acos( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = acos(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> asin( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = asin(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> atan( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = atan(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> exp( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = exp(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> log( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = log(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> log10( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = log10(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> sqrt( const Vector<Type> &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = sqrt(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> pow( const Vector<Type> &b, const Vector<Type> &e )
{
    assert( b.dim() == e.dim() );

    Vector<Type> tmp( b.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR1 = b.begin();
    typename Vector<Type>::const_iterator itrR2 = e.begin();

    while( itrL != tmp.end() )
        *itrL++ = pow( *itrR1++, *itrR2++ );

    return tmp;
}


template <typename Type>
Vector<Type> pow( const Vector<Type> &b, const Type &e )
{
    Vector<Type> tmp( b.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = b.begin();

    while( itrL != tmp.end() )
        *itrL++ = pow( *itrR++, e );

    return tmp;
}


template <typename Type>
Vector<Type> pow( const Type &b, const Vector<Type> &e )
{
    Vector<Type> tmp( e.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector<Type>::const_iterator itrR = e.begin();

    while( itrL != tmp.end() )
        *itrL++ = pow( b, *itrR++ );

    return tmp;
}


/**
 * Normal distribution with expectation "u" and variance "r".
 */
template <typename Type>
Vector<Type> gauss( const Vector<Type> &x, const Type &u, const Type &r )
{
    Vector<Type> tmp(x);

    tmp = (tmp-u)*(tmp-u) / ( -2*r*r );
    tmp = exp(tmp) / Type( (sqrt(2*PI)*r) );

    return tmp;
}


template <typename Type>
Vector<Type> abs( const Vector< complex<Type> > &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector< complex<Type> >::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = abs(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> arg( const Vector< complex<Type> > &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector< complex<Type> >::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = arg(*itrR++);

    return tmp;
}


template <typename Type>
Vector<Type> real( const Vector< complex<Type> > &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector< complex<Type> >::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = (*itrR++).real();

    return tmp;
}


template <typename Type>
Vector<Type> imag( const Vector< complex<Type> > &v )
{
    Vector<Type> tmp( v.dim() );
    typename Vector<Type>::iterator itrL = tmp.begin();
    typename Vector< complex<Type> >::const_iterator itrR = v.begin();

    while( itrL != tmp.end() )
        *itrL++ = (*itrR++).imag();

    return tmp;
}
