#ifndef __HSV_H__
#define __HSV_H__

#include "ws2811_types.h"
#include <math.h>

struct HSV;

typedef struct HSV {
	float h;
	float s;
	float v;

	inline HSV Adjust(float dH, float cS, float cV) {
		HSV adjusted = { this->h + dH, this->s * cS, this->v * cV };
		return adjusted;
	}
} HSV_t;


RGB_t hsv2rgb(HSV_t hsv);

#endif
