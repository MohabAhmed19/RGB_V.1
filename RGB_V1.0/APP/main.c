#include "TM4C123.h"
#include "./HAL/LED.h"
#include "./HAL/Push_button.h"
#include "./MCAL/SysTick_timer.h"




int main(void)
{
	STR_Port_ConfigType RED_LED_config = {Port_Pin_Output, Port_Pin_High, Port_Pin_Digital, Port_Pin_PUR, Port_Pin_CUR_8mA, Port_F, Port_Pin_1};
	STR_Port_ConfigType BLUE_LED_config = {Port_Pin_Output, Port_Pin_High, Port_Pin_Digital, Port_Pin_PUR, Port_Pin_CUR_8mA, Port_F, Port_Pin_2};
	STR_Port_ConfigType GREEN_LED_config = {Port_Pin_Output, Port_Pin_High, Port_Pin_Digital, Port_Pin_PUR, Port_Pin_CUR_8mA, Port_F, Port_Pin_3};
	STR_Port_ConfigType Push_button1_config = {Port_Pin_Input, Port_Pin_Low, Port_Pin_Digital, Port_Pin_PUR, Port_Pin_CUR_2mA, Port_F, Port_Pin_4};
	enu_Port_PinLevelType PB_state;
	LED_init(&RED_LED_config);
	LED_init(&GREEN_LED_config);
	LED_init(&BLUE_LED_config);
	PB_init(&Push_button1_config);
	SysTick_init(System_clock, 0);
	while(1)
	{
		while(PB_state==0)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		while(PB_state==1)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		LED_on(&RED_LED_config);
		
		while(PB_state==0)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		while(PB_state==1)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		LED_off(&RED_LED_config);
		LED_on(&GREEN_LED_config);
		while(PB_state==0)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		while(PB_state==1)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		LED_off(&RED_LED_config);
		LED_off(&GREEN_LED_config);
		LED_on(&BLUE_LED_config);
		
		while(PB_state==0)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		while(PB_state==1)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		LED_on(&RED_LED_config);
		LED_on(&GREEN_LED_config);
		LED_on(&BLUE_LED_config);
		while(PB_state==0)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		while(PB_state==1)
		{
			PB_pressed(&Push_button1_config, &PB_state);
		}
		LED_off(&RED_LED_config);
		LED_off(&GREEN_LED_config);
		LED_off(&BLUE_LED_config);
	}
}


