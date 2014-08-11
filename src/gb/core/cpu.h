// ANDER MARTINEZ 2014

#pragma once
#include <cstddef>
#include <stdint.h>
#include "mmu.h"

namespace gamelad{
	#define R16(R, H, L) \
		union{ \
			uint16_t R; \
			struct{ \
				uint8_t L; \
				uint8_t H; \
			}; \
		}

	class CPU{
		// OPCODES
		#include "instructions_decl.h"
	protected:
		bool ime;
		bool halt;
		bool stop;
		bool error;
		unsigned int  clk_; // Total time in ticks
		unsigned char tck_; // Ticks for current instruction

		GPU gpu;
		Memory mem;
		// Registers
		union{
			uint16_t AF;
			struct{
				uint8_t RA; // Accumulator
				union{
					uint8_t RF;
					struct{ // Flag Register
				        bool padding:4; // useless
				        bool FC:1; // bit 4 - Carry
				        bool FH:1; // bit 5 - Half Carry
				        bool FN:1; // bit 6 - Subtraction
				        bool FZ:1; // bit 7 - Zero
				    };
			    };
			};
		};
		R16(BC, RB, RC);
		R16(DE, RD, RE);
		R16(HL, RH, RL);
		uint16_t SP; // Stack Pointer
	    uint16_t PC; // Program Counter
	    uint16_t bAF, bBC, bDE, bHL; // Backup registers

	    uint8_t INT(uint16_t inter);
    public:
		void reset(void);
		void step(void);
		CPU(uint8_t *rom);
	};
};