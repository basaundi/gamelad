// ANDER MARTINEZ 2014

#pragma once
#include <cstddef>
#include "cpu.h"

namespace gamelad{
	class GB : CPU{
	public:
		void load_ROM(void* ROM, size_t size);
		void run(void);
		bool running(void);
		GB(uint8_t *rom);
	};
};