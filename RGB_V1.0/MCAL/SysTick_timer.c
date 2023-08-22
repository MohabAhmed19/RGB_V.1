#include "SysTick_timer.h"
#include "./SERVICE/common.h"

void SysTick_init(uint8_t CLOCK_SOURCE, uint8_t INTERRUPT)
{
	
	
	if(CLOCK_SOURCE == internal_oscillator_over_four)
	{
		CLR_BIT(STCTRL, CLK_SRC);
	}
	else if(CLOCK_SOURCE == System_clock)
	{
		SET_BIT(STCTRL, CLK_SRC);
	}
	
	if(INTERRUPT == 1)
	{
		SET_BIT(STCTRL, INTEN);
	}
	else if(INTERRUPT == 0)
	{
		CLR_BIT(STCTRL, INTEN);
	}
}

void Set_timer_ms(uint32_t time_ms)
{
	uint32_t TICKs = SYS_FRQUENCY*(time_ms/1000);
	
	STRELOAD = TICKs;
}

void SysTick_complete(Systick_state *SysTick_state)
{
	*SysTick_state = GET_BIT_STATUS(STCTRL, COUNT);
}

void Delay_ms(uint32_t time_ms)
{
	SET_BIT(STCTRL, Enable);
	Systick_state state;
	Set_timer_ms(time_ms);
	do{
	SysTick_complete(&state);	
	}
	while(state == incomplete);
	CLR_BIT(STCTRL, Enable);
}