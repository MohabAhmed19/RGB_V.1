#ifndef __GPIO_h
#define __GPIO_h

#include <TM4C123GH6PM.h>

/*GPIO ports base address*/
#define GPIO_APB
#ifdef GPIO_APB
#define GPIO_OFFSET(x) ((x)<4? (0x40004000+0x1000*(x)):(0x40024000+0x1000*((x)-4)))
#elif GPIO_AHB
#define GPIO_OFFSET(X) (0x40058000 + 0x1000 * (x))
#else
#error "please choose a bus for GPIOs"
#endif

/* registers address*/
#define RCGCGPIO			(*((volatile uint32_t*)(0x400FE608)))

#define GPIODATA(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x3FC)))
#define GPIODIR(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x400)))
#define GPIOIS(x)			(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x404)))
#define GPIOIBE(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x408)))
#define GPIOIEV(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x40C)))
#define GPIOIM(x)			(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x410)))
#define GPIORIS(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x414)))
#define GPIOMIS(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x418)))
#define GPIOICR(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x41C)))
#define GPIOAFSEL(x)	(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x420)))
#define GPIODR2R(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x500)))
#define GPIODR4R(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x504)))
#define GPIODR8R(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x508)))
#define GPIOODR(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x50C)))
#define GPIOPUR(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x510)))
#define GPIOPDR(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x514)))
#define GPIODEN(x)		(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x51C)))
#define GPIOAMSEL(x)	(*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x528)))



/*ENUMS*/

typedef enum
{
	Port_Pin_Input, Port_Pin_Output
}enu_Port_PinDirectionType;

typedef enum
{
	Port_Pin_Low, Port_Pin_High
}enu_Port_PinLevelType;


typedef enum
{
	Port_Pin_Digital, Port_Pin_Analog
}enu_Port_PinModeType;

typedef enum
{
	Port_Pin_PUR, Port_Pin_PDR
}enu_Port_PinInternalAttach;

typedef enum
{
	Port_Pin_CUR_2mA, Port_Pin_CUR_4mA, Port_Pin_CUR_8mA
}enu_Port_PinOutputCurrent;

typedef enum
{
	Port_A=0, Port_B, Port_C, Port_D, Port_E, Port_F
}enu_Port_Num;

typedef enum
{
	Port_Pin_0, Port_Pin_1, Port_Pin_2, Port_Pin_3, Port_Pin_4, Port_Pin_5, Port_Pin_6, Port_Pin_7
}enu_Port_PinNum;

/* Struts*/
typedef struct
{
	enu_Port_PinDirectionType 	PortPinDirection;
	enu_Port_PinLevelType				PortPinLevel;
	enu_Port_PinModeType				PortPinMode;
	enu_Port_PinInternalAttach	PortPinInternalAttach;
	enu_Port_PinOutputCurrent		PortPinOutputCurrent;
	enu_Port_Num								PortNum;
	enu_Port_PinNum							PortPinNum;
}STR_Port_ConfigType;



#endif //GPIO