
#ifndef __Push_button_h
#define __Push_button_h

#include "./MCAL/GPIO.h"

void PB_init(STR_Port_ConfigType *STR_PortConfig);

void PB_pressed(STR_Port_ConfigType *STR_PortConfig , enu_Port_PinLevelType *PB_state);

#endif //_Push_button_h