

#include "gpio.h"

/*
 * function to set up GPIO mode and interrupts
 */
void setupGPIO()
{
	/*
	 * TODO set input and output pins for the joystick 
	 */
	*GPIO_PA_MODEL = 0x33333333;

	/*
	 * Example of HW access from C code: turn on joystick LEDs D4-D8 check 
	 * efm32gg.h for other useful register definitions 
	 */
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;	/* enable GPIO clock */
	*GPIO_PA_CTRL = 2;	/* set high drive strength */
	*GPIO_PA_MODEH = 0x55555555;	/* set pins A8-15 as output */
	*GPIO_PA_DOUT = 0xFF00;	/* turn on LEDs D4-D8 (LEDs are active
				 * low) */
	
	illuminate_LED(3);
	while(*GPIO_PA_DIN = 0xff){
		//wait 
	}
	illuminate_LED(0);

	illuminate_LED(1);

}

void illuminate_LED(uint8_t pin){
	*GPIO_PA_DOUT &= ~( (1 << pin) << 8 );
}

void dilluminate_LED(uint8_t pin){
	*GPIO_PA_DOUT |= (1 << pin ) << 8;
}
