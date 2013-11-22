/* 
* RainbowFadePattern.cpp
*
* Created: 22/11/2013 9:39:49 AM
* Author: Tullo
*/


#include "RainbowFadePattern.h"

// phaseLength is used for bitshifting; don't set it higher than 7
RainbowFadePattern::RainbowFadePattern(LedChain *chain, int phaseLength)
: Pattern(chain), 
_phaseLength(phaseLength), 
_phase(0),
_step(0)
{ }

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

    switch(_phase)
    {
        case 0: // Red on, green increasing, blue off
        _colour.r = 1 << _phaseLength;
        _colour.g = 1 << _step;
        _colour.b = 0;
        break;
        	
        case 1: // Red decreasing, green on, blue off
        _colour.r = (1 << _phaseLength) >> (_step);
        _colour.g = 1 << _phaseLength;
        _colour.b = 0;
        break;
        	
        case 2: // Red off, green on, blue increasing
        _colour.r = 0;
        _colour.g = 1 << _phaseLength;
        _colour.b = 1 << _step;
        break;
        	
        case 3: // Red off, green decreasing, blue on
        _colour.r = 0;
        _colour.g = (1 << _phaseLength) >> (_step);
        _colour.b = 1 << _phaseLength;
        break;
        	
        case 4: // Red increasing, green off, blue on
        _colour.r = 1 << _step;
        _colour.g = 0;
        _colour.b = 1 << _phaseLength;
        break;
        	
        case 5: // Red on, green off, blue decreasing
        _colour.r = 1 << _phaseLength;
        _colour.g = 0;
        _colour.b = (1 << _phaseLength) >> (_step);
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
