/* 
* LedChain.h
*
* Created: 20/11/2013 12:20:18 PM
* Author: Tullo
*/


#ifndef __LEDCHAIN_H__
#define __LEDCHAIN_H__

#include "ws2811_types.h"

class LedChain
{
private:
    RGB_t *_buffer;
    int _length;
    SendFrame _sendFrame;

public:
	LedChain(SendFrame sendFrame, RGB_t *buffer, int length);
	~LedChain();

    void SetPixel(int index, RGB_t colour);
    void Update();

private:
	LedChain( const LedChain &c );
	LedChain& operator=( const LedChain &c );

};

#endif //__LEDCHAIN_H__