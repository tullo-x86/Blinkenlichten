

#ifndef __PLASMAPULSEPATTERN_H__
#define __PLASMAPULSEPATTERN_H__

#include "Pattern.h"
#include "hsv.h"

class PlasmaPulsePattern : public Pattern
{
private:
    HSV_t _finalColour;
    HSV_t _currentColour;

    unsigned int _time;
    unsigned int _position;
    bool _isCharging;

public:
    PlasmaPulsePattern(LedChain *chain);
    ~PlasmaPulsePattern();

    void Logic(unsigned int deltaT);
    void Render();
};

#endif
