/*
 * Das Blinkenlichten Zweiten
 * (Blinkenlights No. 2)
 *
 * Created: 2013-11-19
 *  Author: Daniel Tullemans
 */

#include "ws2811.h"
#include <avr/io.h>
#include <util/delay.h>
#include "LedChain.h"

DEFINE_WS2811_FN(send_PortB0, PORTB, 0)

int main(void)
{
    DDRB |= 0x01;

    int length = 10;
    RGB_t buffer[length];
    RGB_t red = {255, 0, 0};
    RGB_t green = {255, 255, 0};

    LedChain chain(&send_PortB0, buffer, length);

    while(1)
    {
        chain.SetPixel(0, red);
        chain.Update();
        _delay_ms(200);
        chain.SetPixel(0, green);
        chain.Update();
        _delay_ms(200);
    }
}

// Need to abstract the LED strings
// Patterns should depend on the string
