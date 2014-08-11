// ANDER MARTINEZ 2014

#include "ch.h"
#include "hal.h"

#include "gb/core/input_hal.h"

int main(void) {
	halInit();
	chSysInit();

	gamelad::InputHAL ih;

	palSetPadMode(GPIOD, GPIOD_LED3, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOD, GPIOD_LED4, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOD, GPIOD_LED5, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOD, GPIOD_LED6, PAL_MODE_OUTPUT_PUSHPULL);
	//	palSetPad(GPIOA, 9); // LED7 GPIOA_LED7?

	while(true){
		if(ih.is_pressed(ih.DOWN)){
			palSetPad(GPIOD, GPIOD_LED6); // Blue
		}
		if(ih.is_pressed(ih.UP)){
			palSetPad(GPIOD, GPIOD_LED3); // Blue
		}
		if(ih.is_pressed(ih.LEFT)){
			palSetPad(GPIOD, GPIOD_LED4); // Blue
		}
		if(ih.is_pressed(ih.RIGHT)){
			palSetPad(GPIOD, GPIOD_LED5); // Blue
		}
		if(ih.is_pressed(ih.A)){
			palSetPad(GPIOD, GPIOD_LED6); // Blue
		}
		if(ih.is_pressed(ih.B)){
			palSetPad(GPIOD, GPIOD_LED5); // Blue
		}
		if(ih.is_pressed(ih.START)){
			palSetPad(GPIOD, GPIOD_LED6); // Blue
		}
		if(ih.is_pressed(ih.SELECT)){
			palSetPad(GPIOD, GPIOD_LED5); // Blue
		}
		chThdSleepMilliseconds(100);
		palClearPad(GPIOD, GPIOD_LED3);
		palClearPad(GPIOD, GPIOD_LED4);
		palClearPad(GPIOD, GPIOD_LED5);
		palClearPad(GPIOD, GPIOD_LED6);
		chThdSleepMilliseconds(1);
	}
}