/*
 * Das Blinkenlichten Zweiten
 * (Blinkenlights No. 2)
 *
 * Created: 2013-11-19
 *  Author: Daniel Tullemans
 */
#define F_CPU 16000000UL

#include "ws2811.h"
#include <avr/io.h>
#include <util/delay.h>
#include "EZChain.h"
#include "AlternatePattern.h"
#include "RainbowFadePattern.h"

EZ_CHAIN(chain, 10, PORTB, 0)

int main(void)
{
    DDRB |= 0x01;

    const RGB_t red = {255, 0, 0};
    const RGB_t yellow = {0, 255, 0};
    const RGB_t green = {0, 255, 0};
    const RGB_t blue = {0, 0, 255};

    AlternatePattern alternate(&chain, red, green);
    RainbowFadePattern fade(&chain, 7);

    const uint8_t patternCount = 2;
    Pattern *patterns[2] = { &alternate, &fade };
    uint8_t patternIdx = 0;
    
    int ms = 0;
    const int maxMs = 3000;
    while(1)
    {
        Pattern *currentPattern = patterns[patternIdx];
        currentPattern->Logic();
        currentPattern->Render();
        chain.Update();
        _delay_ms(currentPattern->GetFrameDelay());
        ms += currentPattern->GetFrameDelay();

        if (ms >= maxMs)
        {
            ms = 0;
            if (++patternIdx >= patternCount) patternIdx = 0;
        }
    }
}

// Need to abstract the LED strings
// Patterns should depend on the string
