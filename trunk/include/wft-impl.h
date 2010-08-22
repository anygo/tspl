/*****************************************************************************
 *                                wft-impl.h
 *
 * Implementation for Windowed Fourier Transform.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


/**
 * Compute WFT of 1D signal("xn") using "wn" as window. The time-frequency
 * coeffitions are stored in "coefs". The column represents time, and row
 * represents frequency.
 */
template <typename Type>
Matrix< complex<Type> > wft( const Vector<Type> &xn, const Vector<Type> &wn,
                             const string &mode )
{
    int Lx = xn.size(),
        Lw = wn.size();

    // extends the input signal
    Vector<Type> tmp = wextend( xn, Lw/2, "both", mode );

    Matrix< complex<Type> > coefs( Lw/2+1, Lx );
    Vector<Type> sn( Lw );
    Vector< complex<Type> > Sk( Lw/2+1 );

    for( int i=0; i<Lx; ++i )
    {
        // intercept xn by wn function
        for( int j=0; j<Lw; ++j )
            sn[j] = tmp[i+j] * wn[j];

        // compute the Foureier transform
        fft( sn, Sk );
        coefs.setColumn( Sk, i+1 );
    }

    return coefs;
}


/**
 * Compute the inverse windowed Fourier transform of "coefs". The window
 * "wn" should be the same as forward transform. The reconstruction signal
 * is stored in "xn".
 */
template <typename Type>
Vector<Type> iwft( const Matrix< complex<Type> > &coefs, const Vector<Type> &wn )
{
    int Lw = wn.size(),
        Lx = coefs.cols();

    Vector<Type> xn(Lx);
    Matrix<Type> tmp( Lw, Lx );
    Vector< complex<Type> > Sk( Lw/2+1 );
    Vector<Type> sn( Lw );

    // compute the inverse Fourier transform of coefs
    for( int i=0; i<Lx; ++i )
    {
        Sk = coefs.getColumn(i+1);
        ifft( Sk, sn );

        tmp.setColumn( sn, i+1 );
    }

    int mid = Lw / 2;
    for( int i=0; i<Lx; ++i )
        xn[i] = tmp[mid][i] / wn[mid];

    return xn;
}


//    template <typename Type>
//    Matrix< complex<Type> > wft( const Vector<Type> &xn, const Vector<Type> &wn,
//                                 const string &mode = "zpd" )
//    {
//        int Lx = xn.size(),
//            Lw = wn.size();
//
//        // extends the input signal
//        Vector<Type> tmp = wextend( xn, Lw/2, "both", mode );
//
//        Matrix< complex<Type> > coefs( Lw/2+1, Lx );
//        Vector<double> sn( Lw );
//        Vector< complex<double> > Sk( Lw/2+1 );
//        fftw_plan r2cP;
//
//        for( int i=0; i<Lx; ++i )
//        {
//            // intercept xn by wn function
//            for( int j=0; j<Lw; ++j )
//                sn[j] = tmp[i+j] * wn[j];
//
//            // compute the Foureier transform
//            r2cP = fftw_plan_dft_r2c_1d( Lw, sn.begin(),
//                   reinterpret_cast<fftw_complex*>(Sk.begin()),
//                   FFTW_ESTIMATE );
//            fftw_execute( r2cP );
//
//            coefs.setColumn( Sk, i+1 );
//        }
//        fftw_destroy_plan( r2cP );
//
//        return coefs;
//    }
//
//
//    template <typename Type>
//    Vector<Type> iwft( const Matrix< complex<Type> > &coefs, const Vector<Type> &wn )
//    {
//        int Lw = wn.size(),
//            Lx = coefs.cols();
//
//        Vector<Type> xn(Lx);
//        Matrix<double> tmp( Lw, Lx );
//        Vector< complex<double> > Sk( Lw/2+1 );
//        Vector<double> sn( Lw );
//        fftw_plan c2rP;
//
//        // compute the inverse Fourier transform of coefs
//        for( int i=0; i<Lx; ++i )
//        {
//            Sk = coefs.getColumn(i+1);
//            c2rP = fftw_plan_dft_c2r_1d( Lw,
//               reinterpret_cast<fftw_complex*>(Sk.begin()),
//               sn.begin(), FFTW_ESTIMATE );
//            fftw_execute( c2rP );
//            sn /= double(Lw);
//
//            tmp.setColumn( sn, i+1 );
//        }
//        fftw_destroy_plan( c2rP );
//
//        int mid = Lw / 2;
//        for( int i=0; i<Lx; ++i )
//            xn[i] = tmp[mid][i] / wn[mid];
//
//        return xn;
//    }
