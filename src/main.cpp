// ANDER MARTINEZ 2014

#include <iostream>
#include <fstream>
#include "gb/core/log.h"
#include "gb/core/gb.h"

using namespace std;

uint8_t *rom;

int main(int argc, char **argv){
	gamelad::GB *gb;

	if(argc != 2){
		cerr << "USAGE: " << argv[0] << " <rom.gb>" << endl;
		return 1;
	}
	{ // LOAD ROM
		streampos length;
		ifstream rom_file(argv[1], ios::binary);
		rom_file.seekg(0, ios::end);
		length = rom_file.tellg();
		rom_file.seekg(0, ios::beg);
		LOGw("Reading " << length << " bytes from file \"" << argv[1] << "\"... ");
		rom = new uint8_t[length];
		rom_file.read((char*) rom, length);
		LOG("[done]");
		gb = new gamelad::GB(rom);
	}
	gb->run();
	delete[] rom;
	delete gb;
  	return 0;
}
