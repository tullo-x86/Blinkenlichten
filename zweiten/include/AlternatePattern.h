/* 
* AlternatePattern.h
*
* Created: 21/11/2013 4:32:34 PM
* Author: Tullo
*/


#ifndef __ALTERNATEPATTERN_H__
#define __ALTERNATEPATTERN_H__

#include "Pattern.h"

class AlternatePattern : public Pattern
{
private:
    RGB_t _colour1;
    RGB_t _colour2;
    bool _switch;

public:
	AlternatePattern(LedChain *chain, RGB_t colour1, RGB_t colour2);
	~AlternatePattern();

    void Logic(unsigned int deltaT);
    void Render();
};

#endif //__ALTERNATEPATTERN_H__
