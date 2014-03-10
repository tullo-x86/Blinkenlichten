#ifndef __HSV_H__
#define __HSV_H__

#include "ws2811_types.h"
#include <math.h>

struct HSV;

// 16-bit HSV colour.
// Acceptable ranges are
// h: 0 - 764
// s: 0 - 128
// v: 0 - 255
typedef struct HSV {
	int16_t h;
	int16_t s;
	int16_t v;

	inline HSV RshV(uint8_t bits) const {
		HSV adjusted = { this->h, this->s, this->v >> bits };
		return adjusted;
	}

    inline RGB_t ToRgb() const {

        int16_t hue = h;
        const int16_t &sat = s,
                      &bri = v;

        int16_t red_val, green_val, blue_val;

        while (hue > 764) hue -= 765;
        while (hue < 0) hue += 765;

        if (hue < 255) {
            red_val = (10880 - sat * (hue - 170)) >> 7;
            green_val = (10880 - sat * (85 - hue)) >> 7;
            blue_val = (10880 - sat * 85) >> 7;
        }
        else if (hue < 510) {
            red_val = (10880 - sat * 85) >> 7;
            green_val = (10880 - sat * (hue - 425)) >> 7;
            blue_val = (10880 - sat * (340 - hue)) >> 7;
        }
        else {
            red_val = (10880 - sat * (595 - hue)) >> 7;
            green_val = (10880 - sat * 85) >> 7;
            blue_val = (10880 - sat * (hue - 680)) >> 7;
        }

        RGB_t outRgb;

        outRgb.r = (uint16_t)((bri + 1) * red_val) >> 8;
        outRgb.g = (uint16_t)((bri + 1) * green_val) >> 8;
        outRgb.b = (uint16_t)((bri + 1) * blue_val) >> 8;

        return outRgb;
    }
} HSV_t;

#endif
