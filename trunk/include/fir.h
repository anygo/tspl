/*****************************************************************************
 *                                  fir.h
 *
 * Finite Impulse Response Digital Filter.
 *
 * This class is designed for designing the FIR filter using window function
 * method. The unit of frequency and gain parameters are "Hz" and "dB",
 * respectively.
 *
 * The valid filter types are:
 *                   lowpass, highpass, bandpass and bandstop
 * and the valid windows are:
 *     Rectangle, Bartlett, Blackman, Hanning, Hamming, Gauss and Kaiser
 *
 * The length of filter( filter's order plus one ) are multiples of 4, which
 * is the least number(L=4n) satisfying the design specifies.
 *
 * Zhang Ming, 2010-03
 *****************************************************************************/


#ifndef FIR_H
#define FIR_H


#include <iomanip>
#include <window.h>
#include <dfd.h>


namespace itlab
{

    class FIR : public DFD
    {

     public:

        FIR( const string &select, const string &win );
        FIR( const string &select, const string &win, double a );
        ~FIR();

        void    design();
        void    dispInfo() const;
        Vector<double> getCoefs() const;

    private:

        void    orderEst();
        void    idealCoef();
        void    calcCoef();
        double  frqeResp( double freq );
        void    calcGain();
        bool    isSatisfy();

        string  windType;           // window type

        Vector<double>  wind,       // window function
                        coefs,      // coefficients
                        edgeGain;   // gain at edge frquency
        double  alpha;              // window parameter

    };
    // class FIR


    #include <fir-impl.h>

}
// namespace itlab


#endif
// FIR_H
