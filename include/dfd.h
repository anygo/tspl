/*****************************************************************************
 *                                  dfd.h
 *
 * Digital Filter Design.
 *
 * This is a base class for FIR and IIR filter design. It contains the design
 * specifies and some universal parameters of filter.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef DFD_H
#define DFD_H


#include <string>
#include <constants.h>
#include <vector.h>


namespace itlab
{

    const double    FREQ_MIN    =   1.0E-3;     // min freqency
    const double    FREQ_MAX    =   1.0E12;     // max freqency
    const double    GAIN_PASS   =   -1.0E-2;    // max passband gain
    const double    GAIN_TRAN   =   -3.0103;    // min pb, max sb gain
    const double    GAIN_STOP   =   -1.0E02;    // min stopband gain

    class DFD
    {

     public:

        DFD( const string &select );
        virtual ~DFD();

        void setParams( double fs, double f1, double a1,
                        double f2, double a2 );
        void setParams( double fs, double f1, double a1, double f2,
                        double f3, double a2, double f4, double a3 );

        virtual void design() = 0;
        virtual void dispInfo() const = 0;

    protected:

        double  fsamp;              // sampling frequency
        double  wpass1, wpass2;     // passband edge frequency
        double  wstop1, wstop2;     // stopband edge frequency

        double  apass1, apass2;     // passband gain
        double  astop1, astop2;     // stopband gain

        string  filtType;           // filter type
        int     order;              // length of filter

        inline double getValue( double x, double min, double max );

    };
    // class DFD


    #include <dfd-impl.h>

}
// namespace itlab


#endif
// DFD_H
