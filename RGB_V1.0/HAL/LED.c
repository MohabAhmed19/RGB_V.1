
#include "LED.h"
#include "./MCAL/GPIO.h"
#include "./SERVICE/common.h"

void LED_init(STR_Port_ConfigType *STR_PortConfig)
{	 
	enu_Port_Num		PortNum =STR_PortConfig->PortNum;
	enu_Port_PinNum PinNum = STR_PortConfig->PortPinNum;
	SET_BIT(RCGCGPIO,PortNum);
	SET_BIT(GPIODIR(PortNum),PinNum);
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

void LED_on(STR_Port_ConfigType *STR_PortConfig)
{
	enu_Port_Num		PortNum =STR_PortConfig->PortNum;
	enu_Port_PinNum PinNum = STR_PortConfig->PortPinNum;
	SET_BIT(GPIODATA(PortNum),PinNum);
}

void LED_off(STR_Port_ConfigType *STR_PortConfig)
{
	enu_Port_Num		PortNum =STR_PortConfig->PortNum;
	enu_Port_PinNum PinNum = STR_PortConfig->PortPinNum;
	CLR_BIT(GPIODATA(PortNum),PinNum);
}

void LED_toggle(STR_Port_ConfigType *STR_PortConfig)
{
	enu_Port_Num		PortNum =STR_PortConfig->PortNum;
	enu_Port_PinNum PinNum = STR_PortConfig->PortPinNum;
	TOGGLE_BIT(GPIODATA(PortNum),PinNum);
}