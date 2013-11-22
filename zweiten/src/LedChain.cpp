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
    memset(_buffer, 0x00, _length * sizeof(RGB_t));
}

LedChain::~LedChain() {}

int LedChain::GetLength()
{
    return _length;
}

void LedChain::SetPixel(int index, RGB_t colour)
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

void LedChain::Update()
{
    _sendFrame(_buffer, _length);
}