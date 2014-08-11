// ANDER MARTINEZ 2014

#pragma once
#include <cstdint>

namespace gamelad{
	const static int screen_width = 160;
	const static int screen_height = 144;

	typedef uint8_t DotMatrix[screen_height][screen_width];
	class iGPU_HAL{
		virtual void draw_matrix(DotMatrix m) = 0;
		virtual void reset(void) = 0;
	};
}