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

EZ_CHAIN(chain, 10, PORTB, 0)

int main(void)
{
    DDRB |= 0x01;

    RGB_t red = {255, 0, 0};
    RGB_t yellow = {0, 255, 0};
    RGB_t green = {0, 255, 0};
    RGB_t blue = {0, 0, 255};

    AlternatePattern p(&chain, red, green);
    
    while(1)
    {
        p.Logic();
        p.Render();
        chain.Update();
        _delay_ms(200);
    }
}

// Need to abstract the LED strings
// Patterns should depend on the string
