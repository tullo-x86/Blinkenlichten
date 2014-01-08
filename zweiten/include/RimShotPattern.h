

#ifndef __RIMSHOTPATTERN_H__
#define __RIMSHOTPATTERN_H__

#include "Pattern.h"
#include "hsv.h"

// Drumskin of 21cm across = 65.94cm circumference
// 65.94cm * (60LED/m) = 39 LEDs
// 50usec + (1.25 * 24 * 39)usec = ...
// !! 1,220usec (1.22ms) to update LEDs

// Mics are equidistant -- placed at 120° increments, forming an equilateral triangle
// packed in a circle (the drum skin).
// !! Conclusion 1: If all three mics spike at the same time, strike was at the drum centre

// NB: ALL of these are approximate since the speed of sound varies with air temperature
//     -- see http://www.sengpielaudio.com/calculator-speedsound.htm for details.
//     (and there's probably plenty of other considerations like the resonance of the
//     drum skin as well)
// The drum skin is 8.5" diameter ~~= 21cm
// Circumference ~~= 66cm
// Distance from mic to mic ~~= 18cm (18.187)
// Speed of sound = 343m/s == 34,300 cm/s
// 18 / 34300 == 524.78usec (@20°C) -- 515usec @30°C -- 533usec @10°C

// !! Conclusion 2: If no other mic spikes within 525usec, strike is on top of first mic


class RimShotPattern : public Pattern
{
private:

public:
    RimShotPattern(LedChain *chain);
    ~RimShotPattern();

    void Logic(unsigned int deltaT);
    void Render();
};

#endif
