#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

/*
 * function to setup the timer 
 */
void timer_init(uint16_t period)
{
	*CMU_HFPERCLKEN0 |=(1<<6);
	*TIMER1_TOP = period;
	*TIMER1_IEN = 1;
	*TIMER1_CMD = 1;
	
	/*
	 * TODO enable and set up the timer
	 * 
	 * 1. Enable clock to timer by setting bit 6 in CMU_HFPERCLKEN0
	 * 2. Write the period to register TIMER1_TOP
	 * 3. Enable timer interrupt generation by writing 1 to TIMER1_IEN 	
	 * 4. Start the timer by writing 1 to TIMER1_CMD
	 * 
	 * This will cause a timer interrupt to be generated every (period)
	 * cycles. Remember to configure the NVIC as well, otherwise the
	 * interrupt handler will not be invoked. 
	 */
}
