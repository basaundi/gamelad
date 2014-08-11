// ANDER MARTINEZ 2014

#include <assert.h>

#include "cpu.h"
#include "log.h"

// **********************
// * 3.3.1. 8-Bit Loads *
// **********************
uint8_t gamelad::CPU::iLD(uint8_t instr, uint8_t* R, uint8_t n){
	*R = n;
	return 2;
}
uint8_t gamelad::CPU::iLD(uint8_t instr, uint8_t* R1, uint8_t* R2){
	*R1 = *R2;
    return 1;
}
uint8_t gamelad::CPU::iLD(uint8_t instr, uint8_t* R, uint16_t addr){
	*R = mem.rb(addr);
    if(instr == 0xFA) return 4;
	return 2;
}
uint8_t gamelad::CPU::iLD(uint8_t instr, uint16_t addr, uint8_t n){
	mem.wb(addr, n);
	return 3;
}
uint8_t gamelad::CPU::iLD(uint8_t instr, uint16_t addr, uint8_t* R){
	mem.wb(addr, *R);
    if(instr == 0xea) return 4;
	return 2;
}

uint8_t gamelad::CPU::iLDH(uint8_t instr, uint16_t Cv, uint8_t* R){
    LOG(":: LD(0xFF00 + " << std::hex << int(Cv) << ", " << int(*R) << ");");
    mem.wb(0xFF00 + Cv, *R);
    return 2;
}
uint8_t gamelad::CPU::iLDH(uint8_t instr, uint8_t* R, uint16_t addr){
	LOG(":: LD(0xFF00 + " << std::hex << int(addr) << ");");
    *R = mem.rb(0xFF00 + addr);
    if(instr == 0xF0) return 3;
    return 2;
}
uint8_t gamelad::CPU::iLDH(uint8_t instr, uint8_t n, uint8_t* R){
    LOG(":: LD([0xFF00 + " << std::hex << int(n) << "], " << int(*R) << ");");
	mem.wb(0xFF00 + n, *R);
    if(instr == 0xE0) return 3;
    return 2;
}

uint8_t gamelad::CPU::iLDHL(uint8_t instr, uint16_t *RR, int8_t n){
    // Stub... 
    int8_t i = (int8_t) n;
    HL = *RR + i;
    return 3;
}

uint8_t gamelad::CPU::iLDI(uint8_t instr, uint16_t HLv, uint8_t* R){
	mem.wb(HL++, *R);
	return 2;
}
uint8_t gamelad::CPU::iLDI(uint8_t instr, uint8_t* R, uint16_t HLv){
	*R = mem.rb(HL++);
	return 2;
}
uint8_t gamelad::CPU::iLDD(uint8_t instr, uint16_t HLv, uint8_t* R){
    mem.wb(HL--, *R);
    return 2;
}
uint8_t gamelad::CPU::iLDD(uint8_t instr, uint8_t* R, uint16_t HLv){
    *R = mem.rb(HL--);
    return 2;
}

// ***********************
// * 3.3.2. 16-Bit Loads *
// ***********************
uint8_t gamelad::CPU::iLD(uint8_t instr, uint16_t* RR, uint16_t nn){
    *RR = nn;
    return 3;
}
uint8_t gamelad::CPU::iLD(uint8_t instr, uint16_t* RR1, uint16_t* RR2){ // SP, HL ?!
	mem.ww(*RR1, *RR2);
    return 1;
}
uint8_t gamelad::CPU::iLD(uint8_t instr, uint16_t addr, uint16_t* RR){ // nn SP
	mem.ww(addr, *RR);
    return 4;
}
uint8_t gamelad::CPU::iPOP(uint8_t instr, uint16_t* RR){
	*RR = mem.rw(SP);
	SP += 2;
	return 3;
}
uint8_t gamelad::CPU::iPUSH(uint8_t instr, uint16_t* RR){
	SP -= 2;
	mem.ww(SP, *RR);
    return 3;
}

// ********************
// * 3.3.3. 8-Bit ALU *
// ********************
uint8_t gamelad::CPU::iADC(uint8_t instr, uint8_t *R, uint16_t addr){
    uint8_t n = mem.rb(addr);
    FN = 0;
    uint8_t a = *R;
    *R += n;
    *R += FC;
    FZ = ((*R) == 0);
    if((*R^n^a)&0x10) FH = 1;
    return 2;
}
uint8_t gamelad::CPU::iADC(uint8_t instr, uint8_t *R, uint8_t n){
    FN = 0;
    uint8_t a = *R;
    *R += n;
    *R += FC;
    FZ = ((*R) == 0);
    if((*R^n^a)&0x10) FH = 1;
    return 2;
}
uint8_t gamelad::CPU::iADC(uint8_t instr, uint8_t *R, uint8_t *R2){
    FN = 0;
    uint8_t a = *R;
    *R += *R2;
    *R += FC;
    FZ = ((*R) == 0);
    if((*R ^ *R2 ^ a) & 0x10) FH = 1;
    return 1;
}
uint8_t gamelad::CPU::iADD(uint8_t instr, uint16_t* RR, int8_t n){
    FN = 0;
    FH = ((*RR & 0xF) > (0xF - n & 0xF));
    FC = n && (*RR > (0xFF - n));
    *RR += n;
    FZ = ((*RR) == 0);
    return 4;
}
uint8_t gamelad::CPU::iADD(uint8_t instr, uint16_t *RR1, uint16_t *RR2){
    //FN = 0;
    //FH = ((*RR1 & 0xFF) > (0xFF - *RR2 & 0xFF));
    //FC = ((*RR2 > 0) && (*RR1 > (0xFFFF - *RR2)));
    *RR1 += *RR2;
    FZ = ((*RR1) == 0);
    return 3;
}
uint8_t gamelad::CPU::iADD(uint8_t instr, uint8_t *R, uint16_t addr){
    uint8_t n = mem.rb(addr);
    FN = 0;
    FH = ((*R & 0xF) > (0xF - n & 0xF));
    FC = n && (*R > (0xFF - n));
    *R += n;
    FZ = ((*R) == 0);
    return 3;
}
uint8_t gamelad::CPU::iADD(uint8_t instr, uint8_t* R, uint8_t n){
    FN = 0;
    FH = ((*R & 0xF) > (0xF - n & 0xF));
    FC = n && (*R > (0xFF - n));
    *R += n;
    FZ = ((*R) == 0);
    return 1;
}
uint8_t gamelad::CPU::iADD(uint8_t instr, uint8_t* R1, uint8_t* R2){
    FN = 0;
    FH = ((*R1 & 0xF) > (0xF - *R2 & 0xF));
	FC = *R2 && (*R1 > (0xFF - *R2));
    *R1 += *R2;
    FZ = ((*R1) == 0);
    return 1;
}

uint8_t gamelad::CPU::iAND(uint8_t instr, uint16_t addr){
    RA &= mem.rb(addr);
    FZ = ((RA) == 0);
    FN = false;
    FC = false;
    FH = false;
    return 2;
}
uint8_t gamelad::CPU::iAND(uint8_t instr, uint8_t n){
    RA &= n;
    FZ = ((RA) == 0);
    FN = false;
    FC = false;
    FH = false;
    return 2;
}
uint8_t gamelad::CPU::iAND(uint8_t instr, uint8_t *R){
    RA &= *R;
    FZ = ((RA) == 0);
    FN = false;
    FC = false;
    FH = false;
    return 1;
}

uint8_t gamelad::CPU::iDEC(uint8_t instr, uint16_t addr){
    uint8_t v = mem.rb(addr) - 1;
    mem.wb(addr, v);
    return 3;
}
uint8_t gamelad::CPU::iDEC(uint8_t instr, uint16_t *RR){
    --(*RR);
    return 1;
}
uint8_t gamelad::CPU::iDEC(uint8_t instr, uint8_t *R){
    FZ = !(--(*R));
    return 1;
}
uint8_t gamelad::CPU::iINC(uint8_t instr, uint16_t addr){
	uint8_t v = mem.rb(addr) + 1;
	mem.wb(addr, v);
	FZ = (v == 0);
    FN = false;
    FC = false;
    FH = false;
	return 3;
}

uint8_t gamelad::CPU::iINC(uint8_t instr, uint16_t *RR){
	FZ = !(++(*RR));
    FN = false;
    FC = false;
    FH = false;
	return 1;
}
uint8_t gamelad::CPU::iINC(uint8_t instr, uint8_t *R){
	FZ = !(++(*R));
    FN = false;
    FC = false;
    FH = false;
	return 1;
}

uint8_t gamelad::CPU::iOR(uint8_t instr, uint16_t addr){
    RA |= mem.rb(addr);
    FZ = ((RA) == 0);
    FN = false;
    FC = false;
    FH = false;
    return 1;
}
uint8_t gamelad::CPU::iOR(uint8_t instr, uint8_t n){
    RA |= n;
    FZ = ((RA) == 0);
    FN = false;
    FC = false;
    FH = false;
    return 2;
}
uint8_t gamelad::CPU::iOR(uint8_t instr, uint8_t *R){
    RA |= *R;
    FZ = ((RA) == 0);
    FN = false;
    FC = false;
    FH = false;
    return 1;
}

// ****************************
// * 3.3.4. 16-Bit Arithmetic *
// ****************************
uint8_t gamelad::CPU::iSBC(uint8_t instr, uint8_t* R, uint16_t addr){
    return iSBC(instr, R, mem.rb(addr));
}
uint8_t gamelad::CPU::iSBC(uint8_t instr, uint8_t *R, uint8_t n){
    uint8_t r = *R;
    short a = *R;
    a -= n;
    a -= FC;
    *R = (uint8_t) a;
    FN = true;
    FC = (a < 0);
    FZ = !a;
    if((*R^n^r)&0x10) FH = 1;
    return 2;
}
uint8_t gamelad::CPU::iSBC(uint8_t instr, uint8_t *R1, uint8_t *R2){
    uint8_t r = *R1;
    short a = *R1;
    a -= *R2;
    a -= FC;
    *R1 = (uint8_t) a;
    FN = true;
    FC = (a < 0);
    FZ = !a;
    if((*R1 ^ *R2 ^ r)&0x10) FH = 1;
    return 2;
}
uint8_t gamelad::CPU::iSUB(uint8_t instr, uint8_t *R, uint16_t addr){
    return iSUB(instr, R, mem.rb(addr));
}
uint8_t gamelad::CPU::iSUB(uint8_t instr, uint8_t *R, uint8_t n){
    FN = 0;
    FH = ((*R & 0xF) > (0xF - n & 0xF)); // TODO: Check this
    FC = (*R > (0xFF - n)); // TODO: Check this
    *R -= n;
    FZ = ((*R) == 0);
    return 2;
}
uint8_t gamelad::CPU::iSUB(uint8_t instr, uint8_t* R1, uint8_t* R2){
    FN = 0;
    FH = ((*R1 & 0xF) > (0xF - *R2 & 0xF)); // TODO: Check this
    FC = (*R1 > (0xFF - *R2)); // TODO: Check this
    *R1 -= *R2;
    FZ = ((*R1) == 0);
    return 1;
}
uint8_t gamelad::CPU::iXOR(uint8_t instr, uint16_t addr){
    return iXOR(instr, mem.rb(addr));
}
uint8_t gamelad::CPU::iXOR(uint8_t instr, uint8_t n){
    RA ^= n;
    FZ = !RA;
    FN = false;
    FC = false;
    FH = false;
    return 2;
}
uint8_t gamelad::CPU::iXOR(uint8_t instr, uint8_t* R){
	RA ^= *R;
    FZ = !RA;
    FN = false;
    FC = false;
    FH = false;
	return 1;
}


// ************************
// * 3.3.5. Miscellaneous *
// ************************
uint8_t gamelad::CPU::iNOP(uint8_t instr){
	return 1;
}
uint8_t gamelad::CPU::iUNDEF(uint8_t instr){
	LOG("!!!! UNDEF !!!");
	stop = true;
	halt = true;
	error= true;
	return 0;
}
uint8_t gamelad::CPU::iSWAP(uint8_t instr, uint16_t addr){
    // Stub...
    iUNDEF(instr); return 0;
}
uint8_t gamelad::CPU::iSWAP(uint8_t instr, uint8_t *R){
    *R = ((*R & 0x0F) << 4) | ((*R & 0xF0) >> 4);
    FZ = !(*R);
    return 1;
}
uint8_t gamelad::CPU::iDAA(uint8_t instr){
    if(FH || ((RA & 0x0F) > 9)) RA += 6;
    FZ = 0;
    if(FH ||(RA > 0x99)) {
        RA += 0x60;
        FZ = 1;
    }
    return 1;
}
uint8_t gamelad::CPU::iCCF(uint8_t instr){
    FC = !FC;
    return 1;
}
uint8_t gamelad::CPU::iCP(uint8_t instr, uint16_t addr){
    return iCP(instr, mem.rb(addr));
}
uint8_t gamelad::CPU::iCP(uint8_t instr, uint8_t n){
	LOG("-- CP A(" << std::hex << int(RA) << ") - " << std::hex << int(n));
	FN = 1;
	FZ = FH = FC = 0;
	if(RA == n){ // Equal
		FZ = 1;
	}else{
		if(RA < n){
			FC = 1;
		}
		FH = (RA ^ (RA - n) ^ n) & 0x10;
	}
	return 2;
}

uint8_t gamelad::CPU::iCP(uint8_t instr, uint8_t *R){
    FN = 1;
    FZ = FH = FC = 0;
    if(RA == *R){ // Equal
        FZ = 1;
    }else{
        if(RA < *R){
            FC = 1;
        }
        FH = (RA ^ (RA - *R) ^ *R) & 0x10;
    }
    return 1;
}
uint8_t gamelad::CPU::iCPL(uint8_t instr){
    RA = ~RA;
    FZ = (RA == 0);
    return 1;
}
uint8_t gamelad::CPU::iDI(uint8_t instr){
	LOG("Disabling interrupts...")
	ime = false;
	return 1;
}
uint8_t gamelad::CPU::iMAP(uint8_t instr_, uint8_t instr){
    int clk = 0;
    uint8_t n;
    uint16_t nn;
    #include "instructions_switch_map.cc"
    return clk;
}
uint8_t gamelad::CPU::iEI(uint8_t instr){
	LOG("Enabling interrupts...")
	ime = true;
	return 1;
}
uint8_t gamelad::CPU::iSTOP(uint8_t instr){ // DJNZn !!!
    int8_t i = (int8_t) mem.rb(PC++);
    RB--;
    if(RB){
        PC += i;
        return 3;
    }
    return 2;
}
uint8_t gamelad::CPU::iHALT(uint8_t instr){
    halt = true;
    return 1;
}
uint8_t gamelad::CPU::iSCF(uint8_t instr){
    FC = true;
    return 1;
}

// ***************************
// * 3.3.6. Rotates & Shifts *
// ***************************

uint8_t gamelad::CPU::iRLE(uint8_t instr, uint16_t addr){
    uint8_t n = mem.rb(addr);
    iRLE(instr, &n);
    mem.wb(addr, n);
    return 4;
}
uint8_t gamelad::CPU::iRLE(uint8_t instr, uint8_t *R){
    bool co = (*R) & 0x80;
    *R = ((*R)<<1) | FC;
    FC = co;
    FZ = ((*R) == 0);
    if(instr == 0x17) return 1;
    return 2;
}
uint8_t gamelad::CPU::iRLC(uint8_t instr, uint16_t addr){
    uint8_t n = mem.rb(addr);
    iRLC(instr, &n);
    mem.wb(addr, n);
    return 4;
}
uint8_t gamelad::CPU::iRLC(uint8_t instr, uint8_t *R){
    FN = 0; // No SUB
    FH = 0;
    FC = *R & 0x80;
    *R = (*R << 1) | FC;
    FZ = ((*R) == 0);
    if(instr == 0x07) return 1;
    return 2;
}
uint8_t gamelad::CPU::iRR(uint8_t instr, uint16_t addr){
    uint8_t n = mem.rb(addr);
    iRR(instr, &n);
    mem.wb(addr, n);
    return 4;
}
uint8_t gamelad::CPU::iRR(uint8_t instr, uint8_t *R){
    FC = *R & 0x01;
    *R = ((*R) >> 1)| 0x80*FC;
    FZ = ((*R) == 0);
    return 2;
}
uint8_t gamelad::CPU::iRRC(uint8_t instr, uint16_t addr){
    uint8_t n = mem.rb(addr);
    iRRC(instr, &n);
    mem.wb(addr, n);
    return 4;
}
uint8_t gamelad::CPU::iRRC(uint8_t instr, uint8_t *R){
	FC = *R & 0x01;
	*R = (*R >> 1) | (*R << 8);
    if(instr == 0x0F) return 1;
    return 2;
}
uint8_t gamelad::CPU::iSLA(uint8_t instr, uint16_t addr){
    uint8_t n = mem.rb(addr);
    iSLA(instr, &n);
    mem.wb(addr, n);
    return 4;
}
uint8_t gamelad::CPU::iSLA(uint8_t instr, uint8_t *R){
    FC = *R & 0x80;
    *R <<= 1;
    FZ = ((*R) == 0);
    FN = 0;
    FH = 0;
    return 2;
}
uint8_t gamelad::CPU::iSRA(uint8_t instr, uint16_t addr){
    uint8_t n = mem.rb(addr);
    iSRA(instr, &n);
    mem.wb(addr, n);
    return 4;
}
uint8_t gamelad::CPU::iSRA(uint8_t instr, uint8_t *R){
    FC = *R & 0x01;
    bool l0 = *R & 0x10;
    *R = (*R >> 1) | l0;
    FZ = ((*R) == 0);
    FN = 0;
    FH = 0;
    return 2;
}
uint8_t gamelad::CPU::iSRL(uint8_t instr, uint16_t addr){
    uint8_t n = mem.rb(addr);
    iSRL(instr, &n);
    mem.wb(addr, n);
    return 4;
}
uint8_t gamelad::CPU::iSRL(uint8_t instr, uint8_t *R){
    FC = *R & 0x01;
    *R >>= 1;
    FZ = ((*R) == 0);
    FN = 0;
    FH = 0;
    return 2;
}

// **********************
// * 3.3.7. Bit Opcodes *
// **********************
uint8_t gamelad::CPU::iBIT(uint8_t instr, uint8_t b, uint16_t addr){
    uint8_t n = mem.rb(addr);
    uint8_t mask = 0x01 << b;
    FN = true;
    FZ = !(n & mask);
    return 3;
}
uint8_t gamelad::CPU::iBIT(uint8_t instr, uint8_t b, uint8_t *R){
    uint8_t mask = 0x01 << b;
    FN = true;
    FZ = !(*R & mask);
    return 2;
}

uint8_t gamelad::CPU::iSET(uint8_t instr, uint8_t b, uint16_t addr){
    uint8_t mask = 0x01 << b;
    mem.wb(addr, mem.rb(addr) | mask);
    return 4;
}
uint8_t gamelad::CPU::iSET(uint8_t instr, uint8_t b, uint8_t *R){
    uint8_t mask = 0x01 << b;
    *R |= mask;
    return 2;
}

uint8_t gamelad::CPU::iRES(uint8_t instr, uint8_t b, uint16_t addr){
    uint8_t mask = 0xFE << b;
    mem.wb(addr, mem.rb(addr) & mask);
    return 4;
}
uint8_t gamelad::CPU::iRES(uint8_t instr, uint8_t b, uint8_t *R){
    uint8_t mask = 0xFE << b;
    *R &= mask;
    return 2;
}

// ****************
// * 3.3.8. Jumps *
// ****************
uint8_t gamelad::CPU::iJP(uint8_t instr, uint16_t nn){
	LOG("**** jumping to 0x" << std::hex << int(nn));
	PC = nn;
	if(instr == 0xC3) return 3;
    return 1;
}
uint8_t gamelad::CPU::iJP(uint8_t instr, bool cc, uint16_t nn){
	if(cc){
        LOG("**** jumping to 0x" << std::hex << int(nn));
        PC = nn;
        return 4;
    }
	return 3;
}
uint8_t gamelad::CPU::iJR(uint8_t instr, uint8_t n){
    int8_t j = (int8_t) n;
    LOG("**** jumping to 0x" << std::hex << int(PC + j));
    PC += j;
	return 3;
}
uint8_t gamelad::CPU::iJR(uint8_t instr, bool cc, uint8_t n){
    int8_t j = (int8_t) n;
    LOG("**** jumping to 0x" << std::hex << int(PC + j));
	if(cc){
        PC += j;
        return 3;
    }
	return 2;
}

// ****************
// * 3.3.9. Calls *
// ****************
uint8_t gamelad::CPU::iCALL(uint8_t instr, uint16_t nn){
    LOG("Calling " << std::hex << int(nn));
    SP-=2;
	mem.ww(SP, PC);
	PC = nn;
    return 5;
}
uint8_t gamelad::CPU::iCALL(uint8_t instr, bool cc, uint16_t nn){
	if(cc){
		SP -= 2;
		mem.ww(SP, PC);
		SP = nn;
	}
    return 5;
}

// ********************
// * 3.3.10. Restarts *
// ********************
uint8_t gamelad::CPU::iRST(uint8_t instr, uint8_t n){
    bAF = AF; bBC = BC; bDE = DE; bHL = HL; // Reserve regs
	// Push present address onto stack.
	// Jump to address $0000 + n.
	SP -= 2;
    mem.ww(SP, PC);
	PC = n;
	return 3;
}


// *******************
// * 3.3.11. Returns *
// *******************
uint8_t gamelad::CPU::iRET(uint8_t instr){
	PC = mem.rw(SP);
	SP += 2;
	return 3;
}
uint8_t gamelad::CPU::iRET(uint8_t instr, bool cc){
    if(cc){
		PC = mem.rw(SP);
		SP += 2;
        return 3;
    }
    return 1;
}
uint8_t gamelad::CPU::iRETI(uint8_t instr){
    AF = bAF; BC = bBC; DE = bDE; HL = bHL; // Restore regs
	PC = mem.rw(SP);
	SP += 2;
	ime = true;
	return 3;
}

