#include "gpio.h"

#include "stm32f407xx.h"

//=============================================================================

/**
* Enable clocking for current port
* - Gpio port
*/
void gpio_setup_clocks(GPIO_TypeDef* port);

//=============================================================================


uint8_t gpio_configure(GPIO_Config_s* config)
{
	//SetUp clock
	gpio_setup_clocks(config->port);

	// Configure MODER
	uint8_t pin_position = config->pin * 2;

	if (pin_position > 30U) return 1;

	config->port->MODER &= ~(3 << pin_position);
	config->port->MODER |= (config->mode << pin_position);

	// Configure OTYPER
	config->port->OTYPER |= (config->output << config->pin);

	// Configure OSPEEDR
	config->port->OSPEEDR &= ~(3 << pin_position);
	config->port->OSPEEDR |= (config->speed << pin_position);

	// Configure PUPDR
	config->port->PUPDR &= ~(3 << pin_position);
	config->port->PUPDR |= (config->pupd << pin_position);

	return 0;
}

uint8_t gpio_deinit(GPIO_Config_s* config)
{
	return 1;
}

uint8_t gpio_get_state(GPIO_TypeDef* port, GPIO_Pin_e pin)
{
	return 1;
}

void gpio_set_output_state(GPIO_TypeDef* port,
	GPIO_Pin_e pin,
	GPIO_State_e state)
{
	if (state == GPIO_State_NotConfigure)
		return;
	else if (state == GPIO_State_SET)
		port->BSRR |= (1 << pin);
	else if (state == GPIO_State_RESET)
		port->BSRR |= (1 << (pin << 16));

}

void gpio_setup_clocks(GPIO_TypeDef* port)
{
	if (port == GPIOA)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	else if (port == GPIOB)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	else if (port == GPIOC)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	else if (port == GPIOD)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	else if (port == GPIOE)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	else
		return;
}