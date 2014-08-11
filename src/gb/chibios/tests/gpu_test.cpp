// ANDER MARTINEZ 2014

#include "gb/chibios/gpu_hal.h"

using namespace gamelad;

DotMatrix m;
int main(void) {
	halInit();
	chSysInit();
	
	GPU_HAL gpu;

	for(int i = 0; i < screen_height; i++){
		for(int j = 0; j < screen_width; j++){
			m[i][j] = (j^i) % 4;
		}
	}
	gpu.draw_matrix(m);
	
	while(true);
}