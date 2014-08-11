// ANDER MARTINEZ 2014

#include "ch.h"
#include "hal.h"
#include "gb/core/input_hal.h"

gamelad::InputHAL::InputHAL(void){
	palSetPadMode(GPIOA, 10, PAL_MODE_INPUT); // Ground/Right
	palSetPadMode(GPIOA,  5, PAL_MODE_INPUT); // Ground/Left
	palSetPadMode(GPIOA,  8, PAL_MODE_INPUT); // Down/Down
	palSetPadMode(GPIOD, 11, PAL_MODE_INPUT); // Up/Up
	palSetPadMode(GPIOA,  3, PAL_MODE_INPUT); // Button A/B
	palSetPadMode(GPIOB,  6, PAL_MODE_INPUT); // START / Button C (UART2 TXD2)
	palSetPadMode(GPIOA, 15, PAL_MODE_OUTPUT_PUSHPULL); // genesisSELECTline
	palSetPad(GPIOA, 15); // Set to V_H by default
}
gamelad::InputHAL::~InputHAL(void){
	// Nothing to do.
}
bool gamelad::InputHAL::is_pressed(Key key){
	bool r;
	switch(key){
		case UP:
			return (palReadPad(GPIOD, 11) == PAL_LOW);
		break;
		case DOWN:
			return (palReadPad(GPIOA,  8) == PAL_LOW);
		break;
		case LEFT:
			return (palReadPad(GPIOA,  5) == PAL_LOW);
		break;
		case RIGHT:
			return (palReadPad(GPIOA, 10) == PAL_LOW);
		break;
		case A:
			palClearPad(GPIOA, 15);
			chThdSleepMilliseconds(2);
			r = (palReadPad(GPIOA,  3) == PAL_LOW);
			palSetPad(GPIOA, 15);
			return r;
		break;
		case B:
			return (palReadPad(GPIOA,  3) == PAL_LOW);
		break;
		case SELECT:
			return (palReadPad(GPIOB,  6) == PAL_LOW);
		break;
		case START:
			palClearPad(GPIOA, 15);
			chThdSleepMilliseconds(2);
			r = (palReadPad(GPIOB,  6) == PAL_LOW);
			palSetPad(GPIOA, 15);
			return r;
		break;
	}
	return false;
}