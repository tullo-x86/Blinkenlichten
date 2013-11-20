/*
 * EZChain.h
 *
 * Created: 20/11/2013 3:00:55 PM
 *  Author: Tullo
 */ 


#ifndef EZCHAIN_H_
#define EZCHAIN_H_

#include "LedChain.h"
#include "ws2811.h"

#define EZ_CHAIN(NAME, LENGTH, PORT, PIN) \
DEFINE_WS2811_FN((send_ ## NAME), (PORT), (PIN)) \
RGB_t buffer_ ## NAME[10]; \
LedChain NAME(&(send_ ## NAME), (buffer_ ## NAME), (LENGTH));

#endif /* EZCHAIN_H_ */