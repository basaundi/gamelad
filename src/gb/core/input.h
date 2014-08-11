// ANDER MARTINEZ 2014

#pragma once
#include <stdint.h>

#include "gb/core/input_hal.h"

namespace gamelad{
	class InputHAL;

	class INPUT{
		bool out = false;
		bool row1 = false;
		InputHAL hal;
	public:
		uint8_t rb(uint16_t addr);
		void wb(uint16_t addr, uint8_t v);
	};
}
