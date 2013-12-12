/* 
* RainbowFadePattern.cpp
*
* Created: 22/11/2013 9:39:49 AM
* Author: Tullo
*/


#include "RainbowFadePattern.h"

RainbowFadePattern::RainbowFadePattern(LedChain *chain, int phaseLength, int brightness)
: Pattern(chain), 
_phaseLength(phaseLength),
_brightnessIncrement(brightness / phaseLength),
_phase(0),
_step(0)
{

}

void RainbowFadePattern::Logic()
{
    if (++_step >= _phaseLength)
    {
        _step = 0;
        if (++_phase >= 6)
        {
            _phase = 0;
        }
    }
    const int fullBright = _brightnessIncrement * _phaseLength;

    switch(_phase)
    {
        case 0: // Red on, green increasing, blue off
        _colour.r = fullBright;
        _colour.g = _brightnessIncrement * _step;
        _colour.b = 0;
        break;
        	
        case 1: // Red decreasing, green on, blue off
        _colour.r = _brightnessIncrement * (_phaseLength - _step);
        _colour.g = fullBright;
        _colour.b = 0;
        break;
        	
        case 2: // Red off, green on, blue increasing
        _colour.r = 0;
        _colour.g = fullBright;
        _colour.b = _brightnessIncrement * _step;
        break;
        	
        case 3: // Red off, green decreasing, blue on
        _colour.r = 0;
        _colour.g = _brightnessIncrement * (_phaseLength - _step);
        _colour.b = fullBright;
        break;
        	
        case 4: // Red increasing, green off, blue on
        _colour.r = _brightnessIncrement * _step;
        _colour.g = 0;
        _colour.b = fullBright;
        break;
        	
        case 5: // Red on, green off, blue decreasing
        _colour.r = fullBright;
        _colour.g = 0;
        _colour.b = _brightnessIncrement * (_phaseLength - _step);
        break;
    }
}

void RainbowFadePattern::Render()
{
    _chain->ShiftBackward(1);
    _chain->SetPixel(0, _colour);
}

RainbowFadePattern::~RainbowFadePattern()
{
}
