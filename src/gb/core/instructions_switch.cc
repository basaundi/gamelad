#define OPn  n  = mem.rb(PC++)
#define OPnn nn = mem.rw(PC++); PC++
switch(instr){
    case 0x0: // NOP 
        LOG("NOP ");
        clk = iNOP(instr);
        break;
    case 0x1: // LD BC,nn
        LOG("LD BC,nn");
        OPnn;
        clk = iLD(instr, &BC, nn);
        break;
    case 0x2: // LD (BC),A
        LOG("LD (BC),A");
        clk = iLD(instr, BC, &RA);
        break;
    case 0x3: // INC BC
        LOG("INC BC");
        clk = iINC(instr, &BC);
        break;
    case 0x4: // INC B
        LOG("INC B");
        clk = iINC(instr, &RB);
        break;
    case 0x5: // DEC B
        LOG("DEC B");
        clk = iDEC(instr, &RB);
        break;
    case 0x6: // LD B,n
        LOG("LD B,n");
        OPn;
        clk = iLD(instr, &RB, n);
        break;
    case 0x7: // RLC A
        LOG("RLC A");
        clk = iRLC(instr, &RA);
        break;
    case 0x8: // LD (nn),SP
        LOG("LD (nn),SP");
        OPnn;
        clk = iLD(instr, nn, &SP);
        break;
    case 0x9: // ADD HL,BC
        LOG("ADD HL,BC");
        clk = iADD(instr, &HL, &BC);
        break;
    case 0xa: // LD A,(BC)
        LOG("LD A,(BC)");
        clk = iLD(instr, &RA, BC);
        break;
    case 0xb: // DEC BC
        LOG("DEC BC");
        clk = iDEC(instr, &BC);
        break;
    case 0xc: // INC C
        LOG("INC C");
        clk = iINC(instr, &RC);
        break;
    case 0xd: // DEC C
        LOG("DEC C");
        clk = iDEC(instr, &RC);
        break;
    case 0xe: // LD C,n
        LOG("LD C,n");
        OPn;
        clk = iLD(instr, &RC, n);
        break;
    case 0xf: // RRC A
        LOG("RRC A");
        clk = iRRC(instr, &RA);
        break;
    case 0x10: // STOP 
        LOG("STOP ");
        clk = iSTOP(instr);
        break;
    case 0x11: // LD DE,nn
        LOG("LD DE,nn");
        OPnn;
        clk = iLD(instr, &DE, nn);
        break;
    case 0x12: // LD (DE),A
        LOG("LD (DE),A");
        clk = iLD(instr, DE, &RA);
        break;
    case 0x13: // INC DE
        LOG("INC DE");
        clk = iINC(instr, &DE);
        break;
    case 0x14: // INC D
        LOG("INC D");
        clk = iINC(instr, &RD);
        break;
    case 0x15: // DEC D
        LOG("DEC D");
        clk = iDEC(instr, &RD);
        break;
    case 0x16: // LD D,n
        LOG("LD D,n");
        OPn;
        clk = iLD(instr, &RD, n);
        break;
    case 0x17: // RLE A
        LOG("RLE A");
        clk = iRLE(instr, &RA);
        break;
    case 0x18: // JR n
        LOG("JR n");
        OPn;
        clk = iJR(instr, n);
        break;
    case 0x19: // ADD HL,DE
        LOG("ADD HL,DE");
        clk = iADD(instr, &HL, &DE);
        break;
    case 0x1a: // LD A,(DE)
        LOG("LD A,(DE)");
        clk = iLD(instr, &RA, DE);
        break;
    case 0x1b: // DEC DE
        LOG("DEC DE");
        clk = iDEC(instr, &DE);
        break;
    case 0x1c: // INC E
        LOG("INC E");
        clk = iINC(instr, &RE);
        break;
    case 0x1d: // DEC E
        LOG("DEC E");
        clk = iDEC(instr, &RE);
        break;
    case 0x1e: // LD E,n
        LOG("LD E,n");
        OPn;
        clk = iLD(instr, &RE, n);
        break;
    case 0x1f: // RR A
        LOG("RR A");
        clk = iRR(instr, &RA);
        break;
    case 0x20: // JR NZ,n
        LOG("JR NZ,n");
        OPn;
        clk = iJR(instr, !FZ, n);
        break;
    case 0x21: // LD HL,nn
        LOG("LD HL,nn");
        OPnn;
        clk = iLD(instr, &HL, nn);
        break;
    case 0x22: // LDI (HL),A
        LOG("LDI (HL),A");
        clk = iLDI(instr, HL, &RA);
        break;
    case 0x23: // INC HL
        LOG("INC HL");
        clk = iINC(instr, &HL);
        break;
    case 0x24: // INC H
        LOG("INC H");
        clk = iINC(instr, &RH);
        break;
    case 0x25: // DEC H
        LOG("DEC H");
        clk = iDEC(instr, &RH);
        break;
    case 0x26: // LD H,n
        LOG("LD H,n");
        OPn;
        clk = iLD(instr, &RH, n);
        break;
    case 0x27: // DAA 
        LOG("DAA ");
        clk = iDAA(instr);
        break;
    case 0x28: // JR Z,n
        LOG("JR Z,n");
        OPn;
        clk = iJR(instr, FZ, n);
        break;
    case 0x29: // ADD HL,HL
        LOG("ADD HL,HL");
        clk = iADD(instr, &HL, &HL);
        break;
    case 0x2a: // LDI A,(HL)
        LOG("LDI A,(HL)");
        clk = iLDI(instr, &RA, HL);
        break;
    case 0x2b: // DEC HL
        LOG("DEC HL");
        clk = iDEC(instr, &HL);
        break;
    case 0x2c: // INC L
        LOG("INC L");
        clk = iINC(instr, &RL);
        break;
    case 0x2d: // DEC L
        LOG("DEC L");
        clk = iDEC(instr, &RL);
        break;
    case 0x2e: // LD L,n
        LOG("LD L,n");
        OPn;
        clk = iLD(instr, &RL, n);
        break;
    case 0x2f: // CPL 
        LOG("CPL ");
        clk = iCPL(instr);
        break;
    case 0x30: // JR NC,n
        LOG("JR NC,n");
        OPn;
        clk = iJR(instr, !FC, n);
        break;
    case 0x31: // LD SP,nn
        LOG("LD SP,nn");
        OPnn;
        clk = iLD(instr, &SP, nn);
        break;
    case 0x32: // LDD (HL),A
        LOG("LDD (HL),A");
        clk = iLDD(instr, HL, &RA);
        break;
    case 0x33: // INC SP
        LOG("INC SP");
        clk = iINC(instr, &SP);
        break;
    case 0x34: // INC (HL)
        LOG("INC (HL)");
        clk = iINC(instr, HL);
        break;
    case 0x35: // DEC (HL)
        LOG("DEC (HL)");
        clk = iDEC(instr, HL);
        break;
    case 0x36: // LD (HL),n
        LOG("LD (HL),n");
        OPn;
        clk = iLD(instr, HL, n);
        break;
    case 0x37: // SCF 
        LOG("SCF ");
        clk = iSCF(instr);
        break;
    case 0x38: // JR C,n
        LOG("JR C,n");
        OPn;
        clk = iJR(instr, &RC, n);
        break;
    case 0x39: // ADD HL,SP
        LOG("ADD HL,SP");
        clk = iADD(instr, &HL, &SP);
        break;
    case 0x3a: // LDD A,(HL)
        LOG("LDD A,(HL)");
        clk = iLDD(instr, &RA, HL);
        break;
    case 0x3b: // DEC SP
        LOG("DEC SP");
        clk = iDEC(instr, &SP);
        break;
    case 0x3c: // INC A
        LOG("INC A");
        clk = iINC(instr, &RA);
        break;
    case 0x3d: // DEC A
        LOG("DEC A");
        clk = iDEC(instr, &RA);
        break;
    case 0x3e: // LD A,n
        LOG("LD A,n");
        OPn;
        clk = iLD(instr, &RA, n);
        break;
    case 0x3f: // CCF 
        LOG("CCF ");
        clk = iCCF(instr);
        break;
    case 0x40: // LD B,B
        LOG("LD B,B");
        clk = iLD(instr, &RB, &RB);
        break;
    case 0x41: // LD B,C
        LOG("LD B,C");
        clk = iLD(instr, &RB, &RC);
        break;
    case 0x42: // LD B,D
        LOG("LD B,D");
        clk = iLD(instr, &RB, &RD);
        break;
    case 0x43: // LD B,E
        LOG("LD B,E");
        clk = iLD(instr, &RB, &RE);
        break;
    case 0x44: // LD B,H
        LOG("LD B,H");
        clk = iLD(instr, &RB, &RH);
        break;
    case 0x45: // LD B,L
        LOG("LD B,L");
        clk = iLD(instr, &RB, &RL);
        break;
    case 0x46: // LD B,(HL)
        LOG("LD B,(HL)");
        clk = iLD(instr, &RB, HL);
        break;
    case 0x47: // LD B,A
        LOG("LD B,A");
        clk = iLD(instr, &RB, &RA);
        break;
    case 0x48: // LD C,B
        LOG("LD C,B");
        clk = iLD(instr, &RC, &RB);
        break;
    case 0x49: // LD C,C
        LOG("LD C,C");
        clk = iLD(instr, &RC, &RC);
        break;
    case 0x4a: // LD C,D
        LOG("LD C,D");
        clk = iLD(instr, &RC, &RD);
        break;
    case 0x4b: // LD C,E
        LOG("LD C,E");
        clk = iLD(instr, &RC, &RE);
        break;
    case 0x4c: // LD C,H
        LOG("LD C,H");
        clk = iLD(instr, &RC, &RH);
        break;
    case 0x4d: // LD C,L
        LOG("LD C,L");
        clk = iLD(instr, &RC, &RL);
        break;
    case 0x4e: // LD C,(HL)
        LOG("LD C,(HL)");
        clk = iLD(instr, &RC, HL);
        break;
    case 0x4f: // LD C,A
        LOG("LD C,A");
        clk = iLD(instr, &RC, &RA);
        break;
    case 0x50: // LD D,B
        LOG("LD D,B");
        clk = iLD(instr, &RD, &RB);
        break;
    case 0x51: // LD D,C
        LOG("LD D,C");
        clk = iLD(instr, &RD, &RC);
        break;
    case 0x52: // LD D,D
        LOG("LD D,D");
        clk = iLD(instr, &RD, &RD);
        break;
    case 0x53: // LD D,E
        LOG("LD D,E");
        clk = iLD(instr, &RD, &RE);
        break;
    case 0x54: // LD D,H
        LOG("LD D,H");
        clk = iLD(instr, &RD, &RH);
        break;
    case 0x55: // LD D,L
        LOG("LD D,L");
        clk = iLD(instr, &RD, &RL);
        break;
    case 0x56: // LD D,(HL)
        LOG("LD D,(HL)");
        clk = iLD(instr, &RD, HL);
        break;
    case 0x57: // LD D,A
        LOG("LD D,A");
        clk = iLD(instr, &RD, &RA);
        break;
    case 0x58: // LD E,B
        LOG("LD E,B");
        clk = iLD(instr, &RE, &RB);
        break;
    case 0x59: // LD E,C
        LOG("LD E,C");
        clk = iLD(instr, &RE, &RC);
        break;
    case 0x5a: // LD E,D
        LOG("LD E,D");
        clk = iLD(instr, &RE, &RD);
        break;
    case 0x5b: // LD E,E
        LOG("LD E,E");
        clk = iLD(instr, &RE, &RE);
        break;
    case 0x5c: // LD E,H
        LOG("LD E,H");
        clk = iLD(instr, &RE, &RH);
        break;
    case 0x5d: // LD E,L
        LOG("LD E,L");
        clk = iLD(instr, &RE, &RL);
        break;
    case 0x5e: // LD E,(HL)
        LOG("LD E,(HL)");
        clk = iLD(instr, &RE, HL);
        break;
    case 0x5f: // LD E,A
        LOG("LD E,A");
        clk = iLD(instr, &RE, &RA);
        break;
    case 0x60: // LD H,B
        LOG("LD H,B");
        clk = iLD(instr, &RH, &RB);
        break;
    case 0x61: // LD H,C
        LOG("LD H,C");
        clk = iLD(instr, &RH, &RC);
        break;
    case 0x62: // LD H,D
        LOG("LD H,D");
        clk = iLD(instr, &RH, &RD);
        break;
    case 0x63: // LD H,E
        LOG("LD H,E");
        clk = iLD(instr, &RH, &RE);
        break;
    case 0x64: // LD H,H
        LOG("LD H,H");
        clk = iLD(instr, &RH, &RH);
        break;
    case 0x65: // LD H,L
        LOG("LD H,L");
        clk = iLD(instr, &RH, &RL);
        break;
    case 0x66: // LD H,(HL)
        LOG("LD H,(HL)");
        clk = iLD(instr, &RH, HL);
        break;
    case 0x67: // LD H,A
        LOG("LD H,A");
        clk = iLD(instr, &RH, &RA);
        break;
    case 0x68: // LD L,B
        LOG("LD L,B");
        clk = iLD(instr, &RL, &RB);
        break;
    case 0x69: // LD L,C
        LOG("LD L,C");
        clk = iLD(instr, &RL, &RC);
        break;
    case 0x6a: // LD L,D
        LOG("LD L,D");
        clk = iLD(instr, &RL, &RD);
        break;
    case 0x6b: // LD L,E
        LOG("LD L,E");
        clk = iLD(instr, &RL, &RE);
        break;
    case 0x6c: // LD L,H
        LOG("LD L,H");
        clk = iLD(instr, &RL, &RH);
        break;
    case 0x6d: // LD L,L
        LOG("LD L,L");
        clk = iLD(instr, &RL, &RL);
        break;
    case 0x6e: // LD L,(HL)
        LOG("LD L,(HL)");
        clk = iLD(instr, &RL, HL);
        break;
    case 0x6f: // LD L,A
        LOG("LD L,A");
        clk = iLD(instr, &RL, &RA);
        break;
    case 0x70: // LD (HL),B
        LOG("LD (HL),B");
        clk = iLD(instr, HL, &RB);
        break;
    case 0x71: // LD (HL),C
        LOG("LD (HL),C");
        clk = iLD(instr, HL, &RC);
        break;
    case 0x72: // LD (HL),D
        LOG("LD (HL),D");
        clk = iLD(instr, HL, &RD);
        break;
    case 0x73: // LD (HL),E
        LOG("LD (HL),E");
        clk = iLD(instr, HL, &RE);
        break;
    case 0x74: // LD (HL),H
        LOG("LD (HL),H");
        clk = iLD(instr, HL, &RH);
        break;
    case 0x75: // LD (HL),L
        LOG("LD (HL),L");
        clk = iLD(instr, HL, &RL);
        break;
    case 0x76: // HALT 
        LOG("HALT ");
        clk = iHALT(instr);
        break;
    case 0x77: // LD (HL),A
        LOG("LD (HL),A");
        clk = iLD(instr, HL, &RA);
        break;
    case 0x78: // LD A,B
        LOG("LD A,B");
        clk = iLD(instr, &RA, &RB);
        break;
    case 0x79: // LD A,C
        LOG("LD A,C");
        clk = iLD(instr, &RA, &RC);
        break;
    case 0x7a: // LD A,D
        LOG("LD A,D");
        clk = iLD(instr, &RA, &RD);
        break;
    case 0x7b: // LD A,E
        LOG("LD A,E");
        clk = iLD(instr, &RA, &RE);
        break;
    case 0x7c: // LD A,H
        LOG("LD A,H");
        clk = iLD(instr, &RA, &RH);
        break;
    case 0x7d: // LD A,L
        LOG("LD A,L");
        clk = iLD(instr, &RA, &RL);
        break;
    case 0x7e: // LD A,(HL)
        LOG("LD A,(HL)");
        clk = iLD(instr, &RA, HL);
        break;
    case 0x7f: // LD A,A
        LOG("LD A,A");
        clk = iLD(instr, &RA, &RA);
        break;
    case 0x80: // ADD A,B
        LOG("ADD A,B");
        clk = iADD(instr, &RA, &RB);
        break;
    case 0x81: // ADD A,C
        LOG("ADD A,C");
        clk = iADD(instr, &RA, &RC);
        break;
    case 0x82: // ADD A,D
        LOG("ADD A,D");
        clk = iADD(instr, &RA, &RD);
        break;
    case 0x83: // ADD A,E
        LOG("ADD A,E");
        clk = iADD(instr, &RA, &RE);
        break;
    case 0x84: // ADD A,H
        LOG("ADD A,H");
        clk = iADD(instr, &RA, &RH);
        break;
    case 0x85: // ADD A,L
        LOG("ADD A,L");
        clk = iADD(instr, &RA, &RL);
        break;
    case 0x86: // ADD A,(HL)
        LOG("ADD A,(HL)");
        clk = iADD(instr, &RA, HL);
        break;
    case 0x87: // ADD A,A
        LOG("ADD A,A");
        clk = iADD(instr, &RA, &RA);
        break;
    case 0x88: // ADC A,B
        LOG("ADC A,B");
        clk = iADC(instr, &RA, &RB);
        break;
    case 0x89: // ADC A,C
        LOG("ADC A,C");
        clk = iADC(instr, &RA, &RC);
        break;
    case 0x8a: // ADC A,D
        LOG("ADC A,D");
        clk = iADC(instr, &RA, &RD);
        break;
    case 0x8b: // ADC A,E
        LOG("ADC A,E");
        clk = iADC(instr, &RA, &RE);
        break;
    case 0x8c: // ADC A,H
        LOG("ADC A,H");
        clk = iADC(instr, &RA, &RH);
        break;
    case 0x8d: // ADC A,L
        LOG("ADC A,L");
        clk = iADC(instr, &RA, &RL);
        break;
    case 0x8e: // ADC A,(HL)
        LOG("ADC A,(HL)");
        clk = iADC(instr, &RA, HL);
        break;
    case 0x8f: // ADC A,A
        LOG("ADC A,A");
        clk = iADC(instr, &RA, &RA);
        break;
    case 0x90: // SUB A,B
        LOG("SUB A,B");
        clk = iSUB(instr, &RA, &RB);
        break;
    case 0x91: // SUB A,C
        LOG("SUB A,C");
        clk = iSUB(instr, &RA, &RC);
        break;
    case 0x92: // SUB A,D
        LOG("SUB A,D");
        clk = iSUB(instr, &RA, &RD);
        break;
    case 0x93: // SUB A,E
        LOG("SUB A,E");
        clk = iSUB(instr, &RA, &RE);
        break;
    case 0x94: // SUB A,H
        LOG("SUB A,H");
        clk = iSUB(instr, &RA, &RH);
        break;
    case 0x95: // SUB A,L
        LOG("SUB A,L");
        clk = iSUB(instr, &RA, &RL);
        break;
    case 0x96: // SUB A,(HL)
        LOG("SUB A,(HL)");
        clk = iSUB(instr, &RA, HL);
        break;
    case 0x97: // SUB A,A
        LOG("SUB A,A");
        clk = iSUB(instr, &RA, &RA);
        break;
    case 0x98: // SBC A,B
        LOG("SBC A,B");
        clk = iSBC(instr, &RA, &RB);
        break;
    case 0x99: // SBC A,C
        LOG("SBC A,C");
        clk = iSBC(instr, &RA, &RC);
        break;
    case 0x9a: // SBC A,D
        LOG("SBC A,D");
        clk = iSBC(instr, &RA, &RD);
        break;
    case 0x9b: // SBC A,E
        LOG("SBC A,E");
        clk = iSBC(instr, &RA, &RE);
        break;
    case 0x9c: // SBC A,H
        LOG("SBC A,H");
        clk = iSBC(instr, &RA, &RH);
        break;
    case 0x9d: // SBC A,L
        LOG("SBC A,L");
        clk = iSBC(instr, &RA, &RL);
        break;
    case 0x9e: // SBC A,(HL)
        LOG("SBC A,(HL)");
        clk = iSBC(instr, &RA, HL);
        break;
    case 0x9f: // SBC A,A
        LOG("SBC A,A");
        clk = iSBC(instr, &RA, &RA);
        break;
    case 0xa0: // AND B
        LOG("AND B");
        clk = iAND(instr, &RB);
        break;
    case 0xa1: // AND C
        LOG("AND C");
        clk = iAND(instr, &RC);
        break;
    case 0xa2: // AND D
        LOG("AND D");
        clk = iAND(instr, &RD);
        break;
    case 0xa3: // AND E
        LOG("AND E");
        clk = iAND(instr, &RE);
        break;
    case 0xa4: // AND H
        LOG("AND H");
        clk = iAND(instr, &RH);
        break;
    case 0xa5: // AND L
        LOG("AND L");
        clk = iAND(instr, &RL);
        break;
    case 0xa6: // AND (HL)
        LOG("AND (HL)");
        clk = iAND(instr, HL);
        break;
    case 0xa7: // AND A
        LOG("AND A");
        clk = iAND(instr, &RA);
        break;
    case 0xa8: // XOR B
        LOG("XOR B");
        clk = iXOR(instr, &RB);
        break;
    case 0xa9: // XOR C
        LOG("XOR C");
        clk = iXOR(instr, &RC);
        break;
    case 0xaa: // XOR D
        LOG("XOR D");
        clk = iXOR(instr, &RD);
        break;
    case 0xab: // XOR E
        LOG("XOR E");
        clk = iXOR(instr, &RE);
        break;
    case 0xac: // XOR H
        LOG("XOR H");
        clk = iXOR(instr, &RH);
        break;
    case 0xad: // XOR L
        LOG("XOR L");
        clk = iXOR(instr, &RL);
        break;
    case 0xae: // XOR (HL)
        LOG("XOR (HL)");
        clk = iXOR(instr, HL);
        break;
    case 0xaf: // XOR A
        LOG("XOR A");
        clk = iXOR(instr, &RA);
        break;
    case 0xb0: // OR B
        LOG("OR B");
        clk = iOR(instr, &RB);
        break;
    case 0xb1: // OR C
        LOG("OR C");
        clk = iOR(instr, &RC);
        break;
    case 0xb2: // OR D
        LOG("OR D");
        clk = iOR(instr, &RD);
        break;
    case 0xb3: // OR E
        LOG("OR E");
        clk = iOR(instr, &RE);
        break;
    case 0xb4: // OR H
        LOG("OR H");
        clk = iOR(instr, &RH);
        break;
    case 0xb5: // OR L
        LOG("OR L");
        clk = iOR(instr, &RL);
        break;
    case 0xb6: // OR (HL)
        LOG("OR (HL)");
        clk = iOR(instr, HL);
        break;
    case 0xb7: // OR A
        LOG("OR A");
        clk = iOR(instr, &RA);
        break;
    case 0xb8: // CP B
        LOG("CP B");
        clk = iCP(instr, &RB);
        break;
    case 0xb9: // CP C
        LOG("CP C");
        clk = iCP(instr, &RC);
        break;
    case 0xba: // CP D
        LOG("CP D");
        clk = iCP(instr, &RD);
        break;
    case 0xbb: // CP E
        LOG("CP E");
        clk = iCP(instr, &RE);
        break;
    case 0xbc: // CP H
        LOG("CP H");
        clk = iCP(instr, &RH);
        break;
    case 0xbd: // CP L
        LOG("CP L");
        clk = iCP(instr, &RL);
        break;
    case 0xbe: // CP (HL)
        LOG("CP (HL)");
        clk = iCP(instr, HL);
        break;
    case 0xbf: // CP A
        LOG("CP A");
        clk = iCP(instr, &RA);
        break;
    case 0xc0: // RET NZ
        LOG("RET NZ");
        clk = iRET(instr, !FZ);
        break;
    case 0xc1: // POP BC
        LOG("POP BC");
        clk = iPOP(instr, &BC);
        break;
    case 0xc2: // JP NZ,nn
        LOG("JP NZ,nn");
        OPnn;
        clk = iJP(instr, !FZ, nn);
        break;
    case 0xc3: // JP nn
        LOG("JP nn");
        OPnn;
        clk = iJP(instr, nn);
        break;
    case 0xc4: // CALL NZ,nn
        LOG("CALL NZ,nn");
        OPnn;
        clk = iCALL(instr, !FZ, nn);
        break;
    case 0xc5: // PUSH BC
        LOG("PUSH BC");
        clk = iPUSH(instr, &BC);
        break;
    case 0xc6: // ADD A,n
        LOG("ADD A,n");
        OPn;
        clk = iADD(instr, &RA, n);
        break;
    case 0xc7: // RST 0
        LOG("RST 0");
        clk = iRST(instr, 0x0);
        break;
    case 0xc8: // RET Z
        LOG("RET Z");
        clk = iRET(instr, FZ);
        break;
    case 0xc9: // RET 
        LOG("RET ");
        clk = iRET(instr);
        break;
    case 0xca: // JP Z,nn
        LOG("JP Z,nn");
        OPnn;
        clk = iJP(instr, FZ, nn);
        break;
    case 0xcb: // MAP n
        LOG("MAP n");
        OPn;
        clk = iMAP(instr, n);
        break;
    case 0xcc: // CALL Z,nn
        LOG("CALL Z,nn");
        OPnn;
        clk = iCALL(instr, FZ, nn);
        break;
    case 0xcd: // CALL nn
        LOG("CALL nn");
        OPnn;
        clk = iCALL(instr, nn);
        break;
    case 0xce: // ADC A,n
        LOG("ADC A,n");
        OPn;
        clk = iADC(instr, &RA, n);
        break;
    case 0xcf: // RST 8
        LOG("RST 8");
        clk = iRST(instr, 0x8);
        break;
    case 0xd0: // RET NC
        LOG("RET NC");
        clk = iRET(instr, !FC);
        break;
    case 0xd1: // POP DE
        LOG("POP DE");
        clk = iPOP(instr, &DE);
        break;
    case 0xd2: // JP NC,nn
        LOG("JP NC,nn");
        OPnn;
        clk = iJP(instr, !FC, nn);
        break;
    case 0xd3: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xd4: // CALL NC,nn
        LOG("CALL NC,nn");
        OPnn;
        clk = iCALL(instr, !FC, nn);
        break;
    case 0xd5: // PUSH DE
        LOG("PUSH DE");
        clk = iPUSH(instr, &DE);
        break;
    case 0xd6: // SUB A,n
        LOG("SUB A,n");
        OPn;
        clk = iSUB(instr, &RA, n);
        break;
    case 0xd7: // RST 10
        LOG("RST 10");
        clk = iRST(instr, 0x10);
        break;
    case 0xd8: // RET C
        LOG("RET C");
        clk = iRET(instr, &RC);
        break;
    case 0xd9: // RETI 
        LOG("RETI ");
        clk = iRETI(instr);
        break;
    case 0xda: // JP C,nn
        LOG("JP C,nn");
        OPnn;
        clk = iJP(instr, &RC, nn);
        break;
    case 0xdb: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xdc: // CALL C,nn
        LOG("CALL C,nn");
        OPnn;
        clk = iCALL(instr, &RC, nn);
        break;
    case 0xdd: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xde: // SBC A,n
        LOG("SBC A,n");
        OPn;
        clk = iSBC(instr, &RA, n);
        break;
    case 0xdf: // RST 18
        LOG("RST 18");
        clk = iRST(instr, 0x18);
        break;
    case 0xe0: // LDH (n),A
        LOG("LDH (n),A");
        OPn;
        clk = iLDH(instr, n, &RA);
        break;
    case 0xe1: // POP HL
        LOG("POP HL");
        clk = iPOP(instr, &HL);
        break;
    case 0xe2: // LDH (C),A
        LOG("LDH (C),A");
        clk = iLDH(instr, RC, &RA);
        break;
    case 0xe3: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xe4: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xe5: // PUSH HL
        LOG("PUSH HL");
        clk = iPUSH(instr, &HL);
        break;
    case 0xe6: // AND n
        LOG("AND n");
        OPn;
        clk = iAND(instr, n);
        break;
    case 0xe7: // RST 20
        LOG("RST 20");
        clk = iRST(instr, 0x20);
        break;
    case 0xe8: // ADD SP,d
        LOG("ADD SP,d");
        OPn;
        clk = iADD(instr, &SP, (int8_t) n);
        break;
    case 0xe9: // JP (HL)
        LOG("JP (HL)");
        clk = iJP(instr, HL);
        break;
    case 0xea: // LD (nn),A
        LOG("LD (nn),A");
        OPnn;
        clk = iLD(instr, nn, &RA);
        break;
    case 0xeb: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xec: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xed: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xee: // XOR n
        LOG("XOR n");
        OPn;
        clk = iXOR(instr, n);
        break;
    case 0xef: // RST 28
        LOG("RST 28");
        clk = iRST(instr, 0x28);
        break;
    case 0xf0: // LDH A,(n)
        LOG("LDH A,(n)");
        OPn;
        clk = iLDH(instr, &RA, n);
        break;
    case 0xf1: // POP AF
        LOG("POP AF");
        clk = iPOP(instr, &AF);
        break;
    case 0xf2: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xf3: // DI 
        LOG("DI ");
        clk = iDI(instr);
        break;
    case 0xf4: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xf5: // PUSH AF
        LOG("PUSH AF");
        clk = iPUSH(instr, &AF);
        break;
    case 0xf6: // OR n
        LOG("OR n");
        OPn;
        clk = iOR(instr, n);
        break;
    case 0xf7: // RST 30
        LOG("RST 30");
        clk = iRST(instr, 0x30);
        break;
    case 0xf8: // LDHL SP,d
        LOG("LDHL SP,d");
        OPn;
        clk = iLDHL(instr, &SP, (int8_t) n);
        break;
    case 0xf9: // LD SP,HL
        LOG("LD SP,HL");
        clk = iLD(instr, &SP, &HL);
        break;
    case 0xfa: // LD A,(nn)
        LOG("LD A,(nn)");
        OPnn;
        clk = iLD(instr, &RA, nn);
        break;
    case 0xfb: // EI 
        LOG("EI ");
        clk = iEI(instr);
        break;
    case 0xfc: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xfd: // UNDEF 
        LOG("UNDEF ");
        clk = iUNDEF(instr);
        break;
    case 0xfe: // CP n
        LOG("CP n");
        OPn;
        clk = iCP(instr, n);
        break;
    case 0xff: // RST 38
        LOG("RST 38");
        clk = iRST(instr, 0x38);
        break;
    default: iUNDEF(instr);
}
#undef OPn
#undef OPn
