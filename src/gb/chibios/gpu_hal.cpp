// ANDER MARTINEZ 2014

#include "gpu_hal.h"

static inline double _min(const double a, const double b) {
  return (a<b)?a:b;
}

gamelad::GPU_HAL::GPU_HAL(void){
	palette[0] = HTML2COLOR(0xFFFFFF);
	palette[1] = HTML2COLOR(0xC0C0C0);
	palette[2] = HTML2COLOR(0x606060);
	palette[3] = HTML2COLOR(0x223311);
}

void gamelad::GPU_HAL::reset(void){
	gdispClear(background);

	swidth = gdispGetWidth();
	sheight = gdispGetHeight();

	ratio = _min(swidth/((double) screen_width), sheight/((double) screen_height));
	padx = (swidth  - screen_width * ratio)/2;
	pady = (sheight - screen_height * ratio)/2;
}

gamelad::GPU_HAL::~GPU_HAL(void){}

void gamelad::GPU_HAL::draw_matrix(gamelad::DotMatrix m){
	/*
	for(int i = pady; i < cend; i++){
		for(int j = padx; j < lend; j++){
			size_t si = (i - pady) / ratio;
			size_t sj = (j - padx) / ratio;
			gdispDrawPixel(j, i, palette[m[si][sj]]);
		}
	}*/
	size_t si = pady;
	size_t sj = padx;
	for(int i = 0; i < screen_height; ){
		for(int j = 0; j < screen_width; ){
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
		}
		sj = padx; ++si;
		for(int j = 0; j < screen_width; ){
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
		}
		sj = padx; ++i; ++si;
		for(int j = 0; j < screen_width; ){
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
		}
		sj = padx; ++si;
		for(int j = 0; j < screen_width; ){
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
		}
		sj = padx; ++i; ++si;
		for(int j = 0; j < screen_width; ){
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
			gdispDrawPixel(sj++, si, palette[m[i][j++]]);
		}
		sj = padx; ++i; ++si;
	}
}
