

#ifndef __PLASMAPULSEPATTERN_H__
#define __PLASMAPULSEPATTERN_H__

#include "Pattern.h"

class PlasmaPulsePattern : public Pattern
{
private:
    RGB_t _finalColour;
    RGB_t _currentColour;

    unsigned int _time;
    unsigned int _position;

public:
    PlasmaPulsePattern(LedChain *chain, RGB_t colour);
	~PlasmaPulsePattern();

	void Logic(unsigned int deltaT);
	void Render();
};

#endif
