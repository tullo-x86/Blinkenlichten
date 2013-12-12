/* 
* RainbowFadePattern.h
*
* Created: 22/11/2013 9:39:49 AM
* Author: Tullo
*/


#ifndef __RAINBOWFADEPATTERN_H__
#define __RAINBOWFADEPATTERN_H__

#include "Pattern.h"

class RainbowFadePattern : public Pattern
{
private:
    RGB_t _colour;
    const int _phaseLength;
    uint8_t _phase;
    uint8_t _step;
    uint8_t _brightnessIncrement;

public:
	RainbowFadePattern(LedChain *chain, int phaseLength, int brightness);
	~RainbowFadePattern();

	void Logic(unsigned int deltaT);
	void Render();
};

#endif
