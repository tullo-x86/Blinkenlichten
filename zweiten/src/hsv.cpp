#include "hsv.h"
/*
RGB_t hsv2rgb(HSV_t hsv) {
    float min;
    float chroma;
    float hDash;
    float x;

    float r=0,
    	  g=0,
    	  b=0;

    float v = fmax(fmin(hsv.v, 1.0f), 0.0f);

    chroma = fmax(fmin(hsv.s, 1.0f), 0.0f) * v;
    hDash = hsv.h / 60.0;
    x = chroma * (1.0 - fabs(fmod(hDash, 2.0f) - 1.0));

    if(hDash < 1.0)
    {
    	r = chroma;
    	g = x;
    }
    else if(hDash < 2.0)
    {
    	r = x;
    	g = chroma;
    }
    else if(hDash < 3.0)
    {
    	g = chroma;
    	b = x;
    }
    else if(hDash < 4.0)
    {
    	g = x;
    	b = chroma;
    }
    else if(hDash < 5.0)
    {
    	r = x;
    	b = chroma;
    }
    else
    {
    	r = chroma;
    	b = x;
    }

    min = v - chroma;

    r += min;
    g += min;
    b += min;

    RGB_t rgb = { (uint8_t)(r*255), (uint8_t)(g*255), (uint8_t)(b*255) };
    return rgb;
}
*/