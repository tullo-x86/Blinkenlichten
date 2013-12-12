
#include "PlasmaPulsePattern.h"
#include "stdlib.h"

PlasmaPulsePattern::PlasmaPulsePattern(LedChain *chain)
: Pattern(chain),
_time(0),
_position(0),
_isCharging(true)
{
    _finalColour.h = 220;
    _finalColour.s = 1;
    _finalColour.v = 1;
}

void PlasmaPulsePattern::Logic(unsigned int deltaT)
{
    const unsigned int chargeLength = 1000;
    const unsigned int fireLength = 570;
    const unsigned int period = chargeLength + fireLength;

    _time += deltaT;
    if (_time > period) {
        _time = 0;
        _finalColour.h = rand() % 360;
        _finalColour.s = 0.5 + rand() / (float)RAND_MAX;
        _chain->Clear();
    }

    // Pattern is as follows:
    // 1: Pulse charges up
    // 2: Pulse moves along the chain, fading out as it goes

    if (_time < chargeLength) {
        // Pulse is charging
        _currentColour = _finalColour;
        _currentColour.v *= (float)_time / (float)chargeLength;
        _isCharging = true;
        _position = 0;
    } else {
        _currentColour = _finalColour;
        _isCharging = false;
        // Pulse is firing
        _position += 3;
    }
}

void PlasmaPulsePattern::Render()
{
    if (_isCharging) {
        _chain->SetPixel(0, hsv2rgb(_currentColour.Adjust(0,1,0.25)));
        _chain->SetPixel(1, hsv2rgb(_currentColour));
        _chain->SetPixel(2, hsv2rgb(_currentColour));
        _chain->SetPixel(3, hsv2rgb(_currentColour.Adjust(0,1,0.25)));
        _chain->SetPixel(4, hsv2rgb(_currentColour.Adjust(0,1,0.0625)));
    } else {
        if (_position >= 3) {
            _chain->SetPixel(_position - 1, {0,0,0});
            _chain->SetPixel(_position - 2, {0,0,0});
            _chain->SetPixel(_position - 3, {0,0,0});
        }
        RGB_t finalRgb = hsv2rgb(_finalColour);
        _chain->SetPixel(0 + _position, finalRgb);
        _chain->SetPixel(1 + _position, finalRgb);
        _chain->SetPixel(2 + _position, finalRgb);
        _chain->SetPixel(3 + _position, finalRgb);
        _chain->SetPixel(4 + _position, finalRgb);
    }
}

PlasmaPulsePattern::~PlasmaPulsePattern()
{ }
