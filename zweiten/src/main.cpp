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

EZ_CHAIN(chain, 240, PORTB, 0)

int main(void)
{
    DDRB |= 0x01;

    const RGB_t red = {24, 0, 0};
    const RGB_t green = {0, 24, 0};

    AlternatePattern alternate(&chain, red, green);
    RainbowFadePattern fade(&chain, 33, 100);
    RainbowFadePattern fastFade(&chain, 10, 100);

    const uint8_t patternCount = 2;
    Pattern *patterns[patternCount] = { &fade, &fastFade };
    uint8_t patternIdx = 0;
    
    unsigned int ms = 0;
    const unsigned int maxMs = 60000;
    while(1)
    {
        Pattern *currentPattern = patterns[patternIdx];
        currentPattern->Logic();
        currentPattern->Render();
        chain.Update();
        _delay_ms(15);
        ms += 15;

        if (ms >= maxMs)
        {
            ms = 0;
            if (++patternIdx >= patternCount) patternIdx = 0;
        }
    }
}

// Need to abstract the LED strings
// Patterns should depend on the string
