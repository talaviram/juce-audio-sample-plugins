/*
  ==============================================================================

    Parameters.h
    Created: 8 Dec 2015 11:12:56am
    Author:  Tal Aviram

  ==============================================================================
*/

#ifndef PARAMETERS_H_INCLUDED
#define PARAMETERS_H_INCLUDED

// id strings used for parameters
#define PARAM_ID_CLIP "clip"
#define PARAM_ID_BITS "bits"
#define PARAM_ID_SAMPLERATE "samplerate"
#define PARAM_ID_LEVEL "level"
#define PARAM_ID_NONLIN "nonlin"
#define PARAM_ID_NONLIN_MODE "nonlinmode"
#define PARAM_ID_POSTFILT "postfilt"
#define PARAM_ID_POSTFILT_MODE "postfiltmode"
// parameter human friendly names
#define PARAM_NAME_CLIP "Headroom"
#define PARAM_NAME_BITS "Quantize Bit Depth"
#define PARAM_NAME_SAMPLERATE "Sample Rate"
#define PARAM_NAME_LEVEL "Output"
#define PARAM_NAME_NONLIN "Non-Linearty"
#define PARAM_NAME_NONLIN_MODE "Non-Linearty Mode"
#define PARAM_NAME_POSTFILT "Post Filter"
#define PARAM_NAME_POSTFILT_MODE "Post Filter Mode"

class Parameters
{
public:
    enum {
        kSampleRateMode_Sample = 0,
        kSampleRateMode_SampleAndHold,
        kNumSampleRateModes
    };
    
    enum {
        kNonLinearityMode_Odd = 0,
        kNonLinearityMode_Even,
        kNumNonLinearityModes
    };
};



#endif  // PARAMETERS_H_INCLUDED
