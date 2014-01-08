

#ifndef __RIMSHOTPATTERN_H__
#define __RIMSHOTPATTERN_H__

#include "Pattern.h"
#include "hsv.h"

// The drum head is 8.5" across ~~= 21cm
// Circumference ~~= 66cm
// Distance from mic to mic ~~= 18cm (18.187)
// Speed of sound = 343m/s == 34,300 cm/s
// 18 / 34300 == 524.78usec

// Conclusion 1: If no other mic responds within 525usec, strike is at first mic


class RimShotPattern : public Pattern
{
private:
    HSV_t _finalColour;
    HSV_t _currentColour;

    unsigned int _time;
    unsigned int _position;
    bool _isCharging;

public:
    RimShotPattern(LedChain *chain);
    ~RimShotPattern();

    void Logic(unsigned int deltaT);
    void Render();
};

#endif
