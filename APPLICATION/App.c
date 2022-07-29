#include "App.h"
#include "Input.h"
#include "Blink.h"

int main(void)
{
	/* 
	 * To enter the time of ON period in seconds:
	 *		1. Press switch 1 in Tiva C LaunchPad -> You will see a blue blink for a moment as an acknowledment.
	 *		2. Press switch 2 in Tiva C LaunchPad as you like [every press = one second] -> You will see a green blink for a moment as an acknowledment.
	 *		3. After you enter the number of seconds, press switch 1 again -> You will see a blue blink for a moment as an acknowledment.
	 */
	uint8 onPeriod = Input_GetNumOfPresses(BUTTON_1, LED_2, BUTTON_2, LED_3, PULL_UP);
	
	/* 
	 * To enter the time of OFF period in seconds:
	 *		1. Press switch 1 in Tiva C LaunchPad -> You will see a blue blink for a moment as an acknowledment.
	 *		2. Press switch 2 in Tiva C LaunchPad as you like [every press = one second] -> You will see a green blink for a moment as an acknowledment.
	 *		3. After you enter the number of seconds, press switch 1 again -> You will see a blue blink for a moment as an acknowledment.
	 */
	uint8 offPeriod = Input_GetNumOfPresses(BUTTON_1, LED_2, BUTTON_2, LED_3, PULL_UP);
	
	for(;;)
	{
		/* There will be a red blink forever with the entered ON and OFF Periods */
		Blink_Start(BLINKING_GPTM, LED_1, 200, onPeriod, offPeriod);
	}

	return 0;
}