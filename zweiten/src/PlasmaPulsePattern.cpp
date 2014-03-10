
#include "PlasmaPulsePattern.h"
#include "stdlib.h"
#include <math.h>

PlasmaPulsePattern::PlasmaPulsePattern(LedChain *chain)
: Pattern(chain),
_time(0),
_position(0)
{
    _finalColour.h = 0;
    _finalColour.s = 128;
    _finalColour.v = 255;
}

const unsigned int chargeLength = 1000;
void PlasmaPulsePattern::Logic(unsigned int deltaT)
{
    const unsigned int fireLength = 570;
    const unsigned int period = chargeLength + fireLength;

    _time += deltaT;
    if (_time > period) {
        _time = 0;
        _position = 0;
        _finalColour.h = rand() % 765;
        _finalColour.s = 65 + (rand() % 64);
        _chain->Clear();
    }

    // Pattern is as follows:
    // 1: Pulse charges up
    // 2: Pulse moves along the chain, fading out as it goes

    if (_time < chargeLength) {
        // Pulse is charging
        _currentColour = _finalColour;
        // LTR operation order ensures no overflow
        //  16 * 1000 (=16000) / 1000 (=16) * 16 (=256) - 1 (=255)
        int val = 16 * _time / chargeLength * 15 - 1;
        _currentColour.v = val < 0 ? 0 : val;
    } else {
        _currentColour = _finalColour;
        // Pulse is firing
        _position += 3;
    }
}

const RGB_t black = {0,0,0};
void PlasmaPulsePattern::Render()
{
    if (_time < chargeLength) {
        _chain->SetPixel(0, _currentColour.RshV(2).ToRgb());
        _chain->SetPixel(1, _currentColour.ToRgb());
        _chain->SetPixel(2, _currentColour.ToRgb());
        _chain->SetPixel(3, _currentColour.RshV(2).ToRgb());
        _chain->SetPixel(4, _currentColour.RshV(4).ToRgb());
    } else {
        if (_position >= 3) {
            _chain->SetPixel(_position - 1, black);
            _chain->SetPixel(_position - 2, black);
            _chain->SetPixel(_position - 3, black);
        }
        RGB_t finalRgb = _finalColour.ToRgb();
        _chain->SetPixel(0 + _position, finalRgb);
        _chain->SetPixel(1 + _position, finalRgb);
        _chain->SetPixel(2 + _position, finalRgb);
        _chain->SetPixel(3 + _position, finalRgb);
        _chain->SetPixel(4 + _position, finalRgb);
    }
}

PlasmaPulsePattern::~PlasmaPulsePattern()
{ }
