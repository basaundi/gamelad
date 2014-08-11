// ANDER MARTINEZ 2014

#include "cpu.h"
#include "log.h"
#include <assert.h>

void gamelad::CPU::reset(void){
	BC = DE = HL = 0;
	RA = RF = 0;
	SP = PC = 0;

	halt = stop = error = false;
	ime = true;
	LOG("CPU reset");
	/*
	clk = 0;
	*/
	// Skip the bios stuff
	PC = 0x0100;
	SP = 0xFFFE;
	HL = 0x014D;
	RC = 0x13;
	RE = 0xD8;
	RA = 0x01;
	
	gpu.reset();
}

void gamelad::CPU::step(void){	
	int clk = 0;

	uint8_t n;
	uint16_t nn;
	// R++
	// uint8 m
	// uint8 t
	//LOG("");
	//LOGw("PC[0x" << std::hex << PC << "]: ");
	//mem.in_bios = (PC < 0x0100);
	//if(!mem.in_bios) stop = true;
	LOGp(int(PC) << " [" << clk_ << "|" << int(gpu.clk_) << "]: " << int(gpu.LY) << " " << int(RA)
		  << int(RB) << int(RC) << int(RD) << int(RE)
		  << " " << int(RF));
	
	if(halt){
		clk = 1;
	}else{
		uint8_t instr = mem.rb(PC++);
		//LOG("Instruction 0x" << std::hex << int(instr));
		#include "instructions_switch.cc"
	}

	if(ime && mem.IE && mem.IF){
		halt = false;
		ime = false;
		uint8_t fired = mem.IE & mem.IF;
		if(fired & 0x01){ clk = iRST(0, 0x0040); mem.IF &= ~0x01; }
		if(fired & 0x02){ clk = iRST(0, 0x0048); mem.IF &= ~0x02; }
		if(fired & 0x04){ clk = iRST(0, 0x0050); mem.IF &= ~0x04; }
		if(fired & 0x08){ clk = iRST(0, 0x0058); mem.IF &= ~0x08; }
		if(fired & 0x10){ clk = iRST(0, 0x0060); mem.IF &= ~0x10; }
		else{ ime = true; }
	}
    clk_ += clk;
    //tck_ += tck;
	mem.IF |= gpu.step(clk);
}

gamelad::CPU::CPU(uint8_t *rom) : mem(gpu, rom) {}
