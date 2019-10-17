#include "dac.h"

#define DAC_CLOCK_BIT 17

void setupDAC()
{
	*CMU_HFPERCLKEN0 |= (1 << DAC_CLOCK_BIT); // Enable the DAC by setting bit 17 in CMU_HFPERCLKEN0
	*DAC0_CTRL = 0x50010; // Prescale DAC clock by writing 0x50010 to DAC0_CTRL
	*DAC0_CH0CTRL = 1; // Enable left audo channel
	*DAC0_CH1CTRL = 1; // Enable right audio channel
}



	/* Write a continuous stream of samples to the DAC
	 * data registers, DAC0_CH0DATA and DAC0_CH1DATA, for example from a
	 * timer interrupt 
	 * 
	 * 
	 * 
	 * 
	 */