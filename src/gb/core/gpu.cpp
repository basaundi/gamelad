// ANDER MARTINEZ 2014

#include <assert.h>
#include <cstring>
#include "log.h"
#include "gpu.h"

uint8_t gamelad::GPU::rb(uint16_t addr){
	if((addr >= 0x8000) && (addr < 0xA000)){ // VRAM
		return vram[addr - 0x8000];
	}else if(addr >= 0xFF40){
		uint16_t g_addr = addr - 0xFF40;
		return vreg[g_addr];
	}else{ // OAM
		return sprt[addr - 0xFE00];
	}
}
void gamelad::GPU::wb(uint16_t addr, uint8_t v){
	if((addr >= 0x8000) && (addr < 0xA000)){ // VRAM
		vram[addr - 0x8000] = v;
	}else if(addr >= 0xFF40){
		uint16_t g_addr = addr - 0xFF40;
		vreg[g_addr] = v;
	}else{ // OAM
		sprt[addr - 0xFE00] = v;
	}
}

gamelad::GPU::GPU(){
	state_ = OAM;
	LCDC = 0;
	STAT = SCY = SCX = LY = LYCM = DMA = 0;
	BGP = OBP0 = OBP1 = WY = WX = 0;
}

gamelad::GPU::~GPU(){
}

bool gamelad::GPU::step(int clk){
	clk_ += clk;
	bool interrupt = false;
	switch(state_){
		case HBLANK:
			if(clk_ >= 51){
				if(LY == 143){ // last scanline
					state_ = VBLANK;
					hal.draw_matrix(m);
					interrupt = true;
				}else{
					state_ = OAM;
				}
				LY++;
				clk_ = 0;
			}
		break;
		case VBLANK:
			if(clk_ >= 114){
				clk_ = 0;
				LY++;
				if(LY > 153){
					LY = 0;
					state_ = OAM;
				}
			}
		break;
		case OAM:
			if(clk_ >= 20){
				clk_ = 0;
				state_ = VRAM;
			}
		break;
		case VRAM:
			if(clk_ >= 43){
				state_ = HBLANK;
				clk_ = 0;
				if(display_on){
					render_line();
				}
			}
		break;
	}
	STAT = ((LY == LYCM) * 4) | state_;
	return interrupt;
}
void gamelad::GPU::reset(void){
	hal.reset();
	state_ = OAM;
	LCDC = 0;
	STAT = SCY = SCX = LY = LYCM = DMA = 0;
	BGP = OBP0 = OBP1 = WY = WX = 0;
	memset(vram, 0, 0xA000 - 0x8000);
}

void gamelad::GPU::render_line(void){
	int map_w = 32;

	uint8_t *bg = &(vram[bgmap? 0x1C00 : 0x1800]);
	uint8_t *tiles = &(vram[tile_set? 0x0000 : 0x1000]);

	uint8_t pal[4];
	uint8_t palO0[4];
	uint8_t palO1[4];
	for(int i=0; i < 4; i++){
		pal[i]   = (BGP >>(i*2))&3;
		palO0[i] = (OBP0>>(i*2))&3;
		palO1[i] = (OBP1>>(i*2))&3;
	}

	int ty = (SCY + LY);
	int tline = (ty & 7) << 1; // % 8
	ty >>= 3;
	uint8_t mask = 0x80;
	map_w *= ty;


	if(bg_on){
		mask = 0x80;
		for(int x = 0; x < screen_width; x++){
			int tx = (SCX + x) / 8;

			int tile = bg[map_w + tx];
			if(!tile_set && tile > 127){
				tile = (int8_t) tile;
			}
			int tileaddr = (tile << 4) + tline;
			uint8_t tile_l = tiles[tileaddr];
			uint8_t tile_h = tiles[tileaddr + 1];

			m[LY][x] = pal[bool(tile_l & mask) << 1 | bool(tile_h & mask)];
			mask = ((mask >> 1) | (mask << 7));
		}
	}
	if(sprt_on){
		int count = 0;
		for(int i = 0; i < 0xA0; i+=4){
			if(sprt[i] <= LY && LY < sprt[i]+ 8){ // y <= LY < y + 8
				mask = 0x80;
				for(int j = sprt[i+1]; j > 0 && j > sprt[i+1] - 8; j--){
					int tileaddr = (sprt[i+2] << 4) + tline;
					uint8_t tile_l = vram[tileaddr];
					uint8_t tile_h = vram[tileaddr + 1];
					if(sprt[i+3] & 0x10){ // Palette
						m[LY][j] = palO1[bool(tile_l & mask) << 1 | bool(tile_h & mask)];
					}else{
						m[LY][j] = palO0[bool(tile_l & mask) << 1 | bool(tile_h & mask)];
					}

				}
				if(++count > 9) break;
			}
		}
	}
}
