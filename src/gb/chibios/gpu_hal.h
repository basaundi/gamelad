// ANDER MARTINEZ 2014

#pragma once

#include "ch.h"
#include "hal.h"
#include "gfx.h"

#include "gb/core/gpu_hal.h"

namespace gamelad{
	class GPU_HAL : public iGPU_HAL{
		const static color_t background = HTML2COLOR(0x000000);
		color_t palette[4];
		coord_t	swidth, sheight;
		int padx, pady;
		double ratio;
	public:
		void draw_matrix(DotMatrix m);
		void reset(void);
		GPU_HAL(void);
		~GPU_HAL(void);
	};
}