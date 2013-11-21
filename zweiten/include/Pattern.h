/* 
* Pattern.h
*
* Created: 21/11/2013 4:03:28 PM
* Author: Tullo
*/


#ifndef __PATTERN_H__
#define __PATTERN_H__

#include "LedChain.h"

class Pattern
{
protected:
    LedChain* _chain;
    
public:
	virtual ~Pattern();
	virtual void Logic()=0;
	virtual void Render()=0;

protected:
    Pattern(LedChain *chain);
};

#endif //__PATTERN_H__
