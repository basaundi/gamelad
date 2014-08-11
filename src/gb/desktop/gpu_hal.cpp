// ANDER MARTINEZ 2014

#include "SDL.h"
#include "gpu_hal.h"
#include "gb/core/log.h"

gamelad::GPU_HAL::GPU_HAL(void){
	LOG("Switching GPU HAL on...");

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
        "InputHAL test",                   // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        screen_width,                      // width, in pixels
        screen_height,                     // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
	);
	renderer = SDL_CreateRenderer(window, -1, 0);
	texture = SDL_CreateTexture(renderer,
	                               SDL_PIXELFORMAT_ARGB8888,
	                               SDL_TEXTUREACCESS_STREAMING,
	                               screen_width, screen_height);
}
gamelad::GPU_HAL::~GPU_HAL(void){
	LOG("Switching GPU HAL off...");
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void gamelad::GPU_HAL::reset(void){}

void gamelad::GPU_HAL::draw_matrix(gamelad::DotMatrix m){
	for(int i = 0; i < screen_height; i++){
		for(int j = 0; j < screen_width; j++){
			screen[i][j][0] = 235 - m[i][j] * 70;
			screen[i][j][1] = 235 - m[i][j] * 65;
			screen[i][j][2] = 235 - m[i][j] * 75;
			screen[i][j][3] = 255; // Alpha
		}
	}
	SDL_UpdateTexture(texture, NULL, screen, screen_width * sizeof(uint8_t) * 4);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}