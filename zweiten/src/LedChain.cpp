/* 
* LedChain.cpp
*
* Created: 20/11/2013 12:20:18 PM
* Author: Tullo
*/

#include "string.h"
#include "LedChain.h"

LedChain::LedChain(SendFrame sendFrame, RGB_t *buffer, int length)
{
    _length = length;
    _buffer = buffer;
    _sendFrame = sendFrame;
    
    // Initialise the framebuffer
    Clear();
}

LedChain::~LedChain() {}

void LedChain::SetPixel(int index, const RGB_t &colour)
{
    _buffer[index] = colour;
}

void LedChain::ShiftBackward(int count)
{
    for (int i = _length - count - 1; i >= 0; i--)
    {
        _buffer[i + count] = _buffer[i];
    }
}

void LedChain::Clear()
{
    memset(_buffer, 0x00, _length * sizeof(RGB_t));
}

void LedChain::Update()
{
    _sendFrame(_buffer, _length);
}
