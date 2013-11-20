/*
 * ws2811_types.h
 *
 * Created: 20/11/2013 12:27:13 PM
 *  Author: Tullo
 */ 


#ifndef WS2811_TYPES_H_
#define WS2811_TYPES_H_

#include <avr/io.h>

// RGB value structure.
typedef struct __attribute__ ((__packed__)) {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB_t;

#ifndef ARRAYLEN
#define ARRAYLEN(A) (sizeof(A) / sizeof(A[0]))
#endif

typedef void(*SendFrame)(const RGB_t *buffer, uint16_t length);

#endif /* WS2811_TYPES_H_ */