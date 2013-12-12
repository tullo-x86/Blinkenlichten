

#ifndef __PLASMAPULSEPATTERN_H__
#define __PLASMAPULSEPATTERN_H__

#include "Pattern.h"

class PlasmaPulsePattern : public Pattern
{
private:
    RGB_t _colour;

public:
    PlasmaPulsePattern(LedChain *chain, RGB_t colour);
	~PlasmaPulsePattern();

	void Logic();
	void Render();

    inline int GetFrameDelay() { return 30; };
};

#endif
