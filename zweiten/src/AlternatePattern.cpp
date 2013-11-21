/* 
* AlternatePattern.cpp
*
* Created: 21/11/2013 4:32:34 PM
* Author: Tullo
*/


#include "AlternatePattern.h"

AlternatePattern::AlternatePattern(LedChain *chain, RGB_t colour1, RGB_t colour2)
: Pattern(chain)
{
    _colour1 = colour1;
    _colour2 = colour2;
    _switch = false;
}

void AlternatePattern::Logic()
{
    _switch = !_switch;
}

void AlternatePattern::Render()
{
    for (int i=0; i < _chain->GetLength(); i++)
    {
        bool first = i % 2 == 0;
        _chain->SetPixel(i, (first != _switch) ? _colour1 : _colour2);
    }
}

AlternatePattern::~AlternatePattern()
{
    // TODO Would removing the base virtual destructor remove the need to do the dodgy with delete()?
}
