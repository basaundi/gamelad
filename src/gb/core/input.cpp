// ANDER MARTINEZ 2014

#include <assert.h>
#include "input.h"
#include "log.h"

uint8_t gamelad::INPUT::rb(uint16_t addr){
	if(!out) return 0;
	if(row1){
		return ~(
			0xF0 |
			(hal.is_pressed(InputHAL::A))    |
			(hal.is_pressed(InputHAL::B)<<1) |
			(hal.is_pressed(InputHAL::SELECT)<<2) |
			(hal.is_pressed(InputHAL::START)<<3)
		);
	}
	return ~(
		0xF0 |
		(hal.is_pressed(InputHAL::RIGHT))   |
		(hal.is_pressed(InputHAL::LEFT)<<1) |
		(hal.is_pressed(InputHAL::UP)<<2)   |
		(hal.is_pressed(InputHAL::DOWN)<<3)
	);
}

void gamelad::INPUT::wb(uint16_t addr, uint8_t v){
	out  = bool(v & 0x30);
	row1 = bool(v & 0x10);
}
