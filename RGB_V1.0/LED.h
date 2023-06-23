#ifndef __LED_h
#define __LED_h

#include "GPIO.h"
#include "common.h"

void LED_init(STR_Port_ConfigType *STR_PortConfig);


void LED_on(STR_Port_ConfigType *STR_PortConfig);


void LED_off(STR_Port_ConfigType *STR_PortConfig);


void LED_toggle(STR_Port_ConfigType *STR_PortConfig);

#endif