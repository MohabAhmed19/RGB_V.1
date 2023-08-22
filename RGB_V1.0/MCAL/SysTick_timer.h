#ifndef __SysTick_timmer_h
#define __SysTick_timmer_h

#include <TM4C123GH6PM.h>

//registers definition
#define SysTick_base (0xE000E000)

#define STCTRL			 (*((volatile uint32_t*)(SysTick_base + 0x010)))
#define STRELOAD		 (*((volatile uint32_t*)(SysTick_base + 0x014)))
#define STCURRENT		 (*((volatile uint32_t*)(SysTick_base + 0x018)))
	
//magic numbers
#define Enable (0)
#define INTEN (1)
#define CLK_SRC (2)
#define COUNT (16)
#define internal_oscillator_over_four (0)
#define System_clock (1)
#define SYS_FRQUENCY (16000000)

//enums
typedef enum
{incomplete, complete}
Systick_state;

void SysTick_init(uint8_t CLOCK_SOURCE, uint8_t INTERRUPT);

void Set_timer_ms(uint32_t time_ms);

void SysTick_complete(Systick_state *SysTick_state);

void Delay_ms(uint32_t time_ms);

#endif //__SysTick_timmer_h