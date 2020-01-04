/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>

int main (void)
{

	
	
	void configure_port_pins(void)
	{
		struct port_config config_port_pin;
		port_get_config_defaults(&config_port_pin);
		
		/*button
		
		config_port_pin.direction  = PORT_PIN_DIR_INPUT;
		config_port_pin.input_pull = PORT_PIN_PULL_UP;
		port_pin_set_config(BUTTON_0_PIN, &config_port_pin);
		
		*/
		
		//led
		
		config_port_pin.direction = PORT_PIN_DIR_OUTPUT;
		
		port_pin_set_config(PIN_PA20, &config_port_pin); //D2
		port_pin_set_config(PIN_PB12, &config_port_pin); //D3
		port_pin_set_config(PIN_PA21, &config_port_pin); //D4
		port_pin_set_config(PIN_PB13, &config_port_pin); //D5
		port_pin_set_config(PIN_PB30, &config_port_pin); //D6
		port_pin_set_config(PIN_PB04, &config_port_pin); //D7
		port_pin_set_config(PIN_PB05, &config_port_pin); //D8
		port_pin_set_config(PIN_PB31, &config_port_pin); //D9
		port_pin_set_config(PIN_PA27, &config_port_pin); //D10
		
		
	}
	
	
	
	system_init();
	configure_port_pins();
	delay_init();
	
	
	bool pin_state = port_pin_get_input_level(BUTTON_0_PIN);
	while (pin_state == true) {
		port_pin_set_output_level(EXT3_PIN_GPIO_1, false);
		delay_ms(500);
		port_pin_set_output_level(EXT3_PIN_GPIO_1, true);
		delay_ms(500);
	}

}