// ANDER MARTINEZ 2014

#include "gb/core/gb.h"
// ./vendor/ugfx/tools/file2c/binaries/linux/file2c -sc -n rom ROM > src/rom.h
#include "rom.h"

gamelad::GB gb((uint8_t*) rom);

int main(void) {
	halInit();
	chSysInit();
	gfxInit();

	//gamelad::GB gb((uint8_t*) rom);
	gb.run();

	while(true);
    return 0;
}