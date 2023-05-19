#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>
#include "stm32f407xx.h"

//=============================================================================

typedef enum {
	GPIO_State_NotConfigure = -1,
	GPIO_State_SET = 0,
	GPIO_State_RESET,
} GPIO_State_e;

typedef enum {
	PIN_0 = 0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15,
} GPIO_Pin_e;

typedef enum {
	GPIO_Mode_Input = 0,
	GPIO_Mode_Output,
	GPIO_Mode_AltFunc,
	GPIO_Mode_Analog,
}GPIO_Mode_e;

typedef enum {
	GPIO_OutputType_PushPull = 0,
	GPIO_OutputType_OpenDrain,
}GPIO_OutputType_e;

typedef enum {
	GPIO_Speed_Low = 0,
	GPIO_Speed_Medium,
	GPIO_Speed_High,
	GPIO_Speed_VeryHigh,
} GPIO_Speed_e;

typedef enum {
	GPIO_PUPD_PullUp,
	GPIO_PUPD_PullDown
} GPIO_PUPD_e;

typedef struct {
	GPIO_TypeDef* port;
	GPIO_Pin_e pin;
	GPIO_Mode_e mode;
	GPIO_Speed_e speed;
	GPIO_OutputType_e output;
	GPIO_PUPD_e pupd;
} GPIO_Config_s;

//=============================================================================

/**
* Configure Pin as Mode
* - config - Configuration of a specific MCU pin
* + result
*/
uint8_t gpio_configure(GPIO_Config_s* config);

/**
* Deinit configuration
* - config - Configuration
* + result
*/
uint8_t gpio_deinit(GPIO_Config_s* config);

/**
* Get state of pin
* - port - GPIO port
* - pin - specific pin if MCU
* + Pin state (or "Not Configure")
*/
uint8_t gpio_get_state(GPIO_TypeDef* port, GPIO_Pin_e pin);

/**
* Set output state
* - Gpio port
* - pin
*/
void gpio_set_output_state(GPIO_TypeDef* port,
						   GPIO_Pin_e pin,
						   GPIO_State_e state);

//=============================================================================

#define GPIO_DEFAULT_OUTPUT(_port, _pin) {	\
										.port = _port,	\
										.pin = _pin, 	\
										.mode = GPIO_Mode_Output, \
										.speed = GPIO_Speed_High,\
										.output = GPIO_OutputType_PushPull,\
										.pupd = GPIO_PUPD_PullUp, \
										}
#define GPIO_TOGGLE(port, pin)


#endif