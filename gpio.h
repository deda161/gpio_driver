#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>

//=============================================================================

typedef enum {
	GPIO_State_ON,
	GPIO_State_OFF,
} GPIO_State;

typedef enum {
	PIN_0,
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
} GPIO_Pin;

//=============================================================================

/**
*
*/
uint8_t gpio_configure();

/**
*
*/
uint8_t gpio_deinit();

/**
*
*/
uint8_t gpio_get_state();

#endif