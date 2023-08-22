
#include "../MCAL/GPIO.h"
#include "Push_button.h"
#include "./SERVICE/common.h"


void PB_init(STR_Port_ConfigType *STR_PortConfig)
{
	enu_Port_Num		PortNum =STR_PortConfig->PortNum;
	enu_Port_PinNum PinNum = STR_PortConfig->PortPinNum;
	SET_BIT(RCGCGPIO,PortNum);
	
	CLR_BIT(GPIODIR(PortNum), PinNum);
//	*((volatile uint32_t*)0x4002550C)=0x00;
	CLR_BIT(GPIOAFSEL(PortNum), PinNum);
	CLR_BIT(GPIOAMSEL(PortNum), PinNum);
	
	if(STR_PortConfig->PortPinOutputCurrent == Port_Pin_CUR_2mA)
	{
		SET_BIT(GPIODR2R(PortNum),PinNum);
	}
	else if(STR_PortConfig->PortPinOutputCurrent == Port_Pin_CUR_4mA)
	{
		SET_BIT(GPIODR4R(PortNum),PinNum);
	}
	else if(STR_PortConfig->PortPinOutputCurrent == Port_Pin_CUR_8mA)
	{
		SET_BIT(GPIODR8R(PortNum),PinNum);
	}
	if(STR_PortConfig->PortPinInternalAttach==Port_Pin_PUR)
	{
		SET_BIT(GPIOPUR(PortNum), PinNum);
	}
	else if(STR_PortConfig->PortPinInternalAttach==Port_Pin_PDR)
	{
		SET_BIT(GPIOPDR(PortNum), PinNum);
	}
	SET_BIT(GPIODEN(PortNum), PinNum);
	
}

void PB_pressed(STR_Port_ConfigType *STR_PortConfig , enu_Port_PinLevelType *PB_state)
{
	enu_Port_Num		PortNum =STR_PortConfig->PortNum;
	enu_Port_PinNum PinNum = STR_PortConfig->PortPinNum;
	*PB_state = GET_BIT_STATUS(GPIODATA(PortNum),PinNum);
 }
