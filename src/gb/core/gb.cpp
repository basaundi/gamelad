// ANDER MARTINEZ 2014

#include "gb.h"
#include "log.h"

#include <assert.h> // assert
#include <string.h> // memcpy

gamelad::GB::GB(uint8_t *rom) : CPU(rom) {}

void gamelad::GB::run(void){
	LOG("Running!");
	reset();
	int count = 0;
	bool debug = false;
	while(running()){
		step();
		count++;
		//if(count > 1000000) break;
		//if(count > 10000) debug = true;
		LOG("*************************************************************");
		LOG("A:" << std::hex << int(RA) << " BC: " << int(BC) << " DE: " << int(DE) << " HL: " << int(HL));
		LOG("Z:" << std::hex << FZ << " FN: " << FN << " FH: " << FH << " FC: " << FC);
		LOG("SP: " << std::hex << SP << " PC: " << std::hex << int(PC));
		LOG("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		//if(PC >= 0x0028) debug = true;
		if(debug){
			LOG("Return to step...");
			WAITR();
			count = 0;
		}
	}
}

bool gamelad::GB::running(void){
	return !(error || stop);
}