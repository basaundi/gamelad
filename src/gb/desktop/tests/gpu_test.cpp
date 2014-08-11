// ANDER MARTINEZ 2014

#include <iostream>
#include "SDL.h"

#include "gb/sdl/gpu_hal.h"

using namespace std;

int main(int argc, char**argv){
	gamelad::GPU_HAL gpu;
	gamelad::DotMatrix m;

	for(int i = 0; i < gamelad::screen_height; i++){
		for(int j = 0; j < gamelad::screen_width; j++){
			m[i][j] = (uint8_t) rand() % 4;
		}
	}

	SDL_Delay(200);
	gpu.draw_matrix(m);
	SDL_Delay(1000);

	return 0;
}
