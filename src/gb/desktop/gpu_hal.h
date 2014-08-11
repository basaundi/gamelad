// ANDER MARTINEZ 2014

#pragma once
#include "SDL.h"
#include "gb/core/gpu_hal.h"

namespace gamelad{
	class GPU_HAL : public iGPU_HAL{
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		uint8_t screen[screen_height][screen_width][4];
	public:
		void draw_matrix(DotMatrix m);
		void reset(void);
		GPU_HAL(void);
		~GPU_HAL(void);
	};
}