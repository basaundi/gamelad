// ANDER MARTINEZ 2014

#pragma once
#include <stdint.h>

#ifdef DESKTOP
#include "gb/desktop/gpu_hal.h"
#else
#include "gb/chibios/gpu_hal.h"
#endif

namespace gamelad{
	class GPU_HAL;

	class GPU{
		friend class CPU;
		
		GPU_HAL hal;
		DotMatrix m;
		unsigned int clk_;
		enum {HBLANK, VBLANK, OAM, VRAM} state_;
		
		uint8_t vram[0xA000 - 0x8000]; // 8kB Video RAM
		uint8_t sprt[0xFEA0 - 0xFE00]; // Sprite attribute table (OAM)
		union{
			uint8_t vreg[0xFFFE - 0xFF40]; // Video input output registers
			struct{
				union{
					uint8_t LCDC; // LCD Control (R/W)
					struct{
						bool bg_on:1;      // 0x01
						bool sprt_on:1;    // 0x02
						bool sprt_sz:1;    // 0x04
						bool bgmap:1;      // 0x08
						bool tile_set:1;   // 0x10
						bool window:1;     // 0x20
						bool tilemap:1;    // 0x40
						bool display_on:1; // 0x80
					};
				};
				uint8_t STAT; // LCDC Status (R/W)
				uint8_t SCY;  // Scroll Y (R/W)
				uint8_t SCX;  // Scroll X (R/W)
				uint8_t LY;   // LCDC Y-Coordinate (R)
				uint8_t LYCM; // LY Compare  (R/W)
				uint8_t DMA;  // DMA Transfer and Start Address (W)
				uint8_t BGP;  // BG & Window Palette Data  (R/W)
				uint8_t OBP0; // Object Palette 0 Data (R/W)
				uint8_t OBP1; // Object Palette 1 Data (R/W)
				uint8_t WY;   // Window Y Position  (R/W)
				uint8_t WX;   // Window X Position  (R/W)
			};
		};
	public:
		GPU(void);
		~GPU(void);
		void reset(void);
		uint8_t rb(uint16_t addr);
		void wb(uint16_t addr, uint8_t v);

		bool step(int clk);
		void render_line(void);
	};
}