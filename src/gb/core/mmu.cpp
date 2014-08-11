// ANDER MARTINEZ 2014

#include <assert.h>
#include "log.h"
#include "mmu.h"

uint8_t gamelad::Memory::rb(uint16_t addr){
	LOG("-- reading [" << std::hex << int(addr) << "]");
	switch(addr & 0xF000){
		case 0x0000:
			if(addr < 0x0100 && in_bios){
				return bios[addr];
			}
			return rom0[addr];
		case 0x1000: case 0x2000: case 0x3000:
			return rom0[addr];
		case 0x4000: case 0x5000: case 0x6000: case 0x7000:
			return romx[addr & 0x3FFF]; // Selected rom bank
		case 0x8000: case 0x9000: // GPU Vram
			return gpu.rb(addr);
		case 0xA000: case 0xB000:
			return eram[addr - 0xA000]; // External RAM
		case 0xC000: case 0xD000:
			return ram0[addr&0x1FFF];
		 case 0xE000: // ECHO
		 	return ram0[addr-0xE000];
		case 0xF000:
			switch(addr & 0x0F00){
				case 0x000: case 0x100: case 0x200: case 0x300:
				case 0x400: case 0x500: case 0x600: case 0x700:
				case 0x800: case 0x900: case 0xA00: case 0xB00:
				case 0xC00: case 0xD00: // ECHO
		 			return ram0[addr-0xE000]; // TODO: Check this
				break;
				case 0xE00:
					// OAM
					if(addr < 0xFEA0) return gpu.rb(addr);
					return 0;
				break;
				case 0xF00: // Zero page
					if(addr == 0xFFFF) return IE;
					if(addr >= 0xFF80){
						return hram[addr & 0x007F];
					}
					switch(addr & 0xF0){
						case 0x00:
							switch(addr){
								case 0xFF00: return input.rb(addr);
								case 0xFF04: case 0xFF05: case 0xFF06: case 0xFF07: /* TIMER.wb(addr, val); */ break;
								case 0xFF0F: return IF;
								default: /* assert(false); */ return 0;
							}
						case 0x10: case 0x20: case 0x30: // Do nothing
							return 0;
						break;
						case 0x40:case 0x50: case 0x60: case 0x70:
							return gpu.rb(addr);
						default:
							assert(false);
					}
			}
	}
	assert(false);
	return 0;
}
void gamelad::Memory::wb(uint16_t addr, uint8_t v){
	LOG("-- writting [0x" << std::hex << int(addr) << "] = " << std::hex << int(v));
	switch(addr & 0xF000){
		// rom0
		case 0x0000: case 0x1000:
		case 0x2000: case 0x3000:
			// TODO: External RAM
			// if(carrtype){
				romx = &(rom0[(v & 0x1F) * 0x4000]);
			// } // endif
			break;
		case 0x4000: case 0x5000: case 0x6000: case 0x7000:
			return;
			// FIXME
			assert(false);
			break;
		// VRAM
		case 0x8000: case 0x9000:
			gpu.wb(addr, v);
			break;
		case 0xA000: case 0xB000:
			eram[addr - 0xA000] = v; // External RAM
			// TODO: change bank
			return;
		// WRAM
		case 0xC000: case 0xD000:
			ram0[addr&0x1FFF] = v;
			return;
		 case 0xE000:
		 	ram0[addr-0xE000] = v;
		 	return;
		case 0xF000:
			switch(addr & 0x0F00){
				case 0x000: case 0x100: case 0x200: case 0x300:
				case 0x400: case 0x500: case 0x600: case 0x700:
				case 0x800: case 0x900: case 0xA00: case 0xB00:
				case 0xC00: case 0xD00:
				// ECHO
					ram0[addr - 0xE000] = v;
					return;
				case 0xE00:
				// OAM
					if(addr < 0xFEA0) gpu.wb(addr, v);
					return;
				break;
				case 0xF00: // Zero page
					if(addr >= 0xFF80){
						hram[addr & 0x007F] = v;
						return;
					}
					switch(addr & 0xF0){
						if(addr == 0xFFFF){
							IE = v;
							return;
						}
						case 0x00:
							switch(addr){
								case 0xFF00: input.wb(addr, v); return;
								case 0xFF04: case 0xFF05: case 0xFF06: case 0xFF07: /* TIMER.wb(addr, val); */ break;
								case 0xFF0F: IF = v; return;
								default: return;
							}
						case 0x10: case 0x20: case 0x30: // Do nothing
						break;
						case 0x40:
							if(addr == 0xFF46){ // DMA
								for(uint8_t i = 0; i < 160; i++){
									uint8_t val = rb((v<<8) + i);
									gpu.wb(0xFE00 + i, val);
								}
								return;
							}
						case 0x50: case 0x60: case 0x70:
							gpu.wb(addr, v);
							break;
						default:
							assert(false);
					}
			}
	}
}
uint16_t gamelad::Memory::rw(uint16_t addr){
	return (rb(addr+1)<<8) | rb(addr);
}
void gamelad::Memory::ww(uint16_t addr, uint16_t v){
	wb(addr+1, v >> 8);
	wb(addr, v & 0x00FF);
}

gamelad::Memory::Memory(gamelad::GPU& gpu_, uint8_t* rom): in_bios(false), gpu(gpu_) {
	rom0 = rom;
	romx = &(rom0[0x4000]);
}

#ifdef DEBUG
#include <iostream>
using namespace std;
void gamelad::Memory::dump(uint16_t from, uint16_t to){
	cerr << "Memory dump:: " << endl;
	cerr << "     | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F" << endl;
	cerr << "----------------------------------------------------" << endl;
	for(uint32_t i = from & 0xFFF0; i < (to & 0xFFF0) + 0x10; i+=0x10){
		cerr << hex << setw(4) << setfill('0') << int(i) << " | ";
		for(uint32_t j = 0x0; j < 0x10; j ++){
			cerr << hex << setw(2) << setfill('0') << int(rb(i | j)) << " ";
		}
		cerr << endl;
	}
}
#endif