#define OPn  n  = mem.rb(PC++)
#define OPnn nn = mem.rw(PC++); PC++
switch(instr){
    case 0x0: // RLC B
        LOG("RLC B");
        clk = iRLC(instr, &RB);
        break;
    case 0x1: // RLC C
        LOG("RLC C");
        clk = iRLC(instr, &RC);
        break;
    case 0x2: // RLC D
        LOG("RLC D");
        clk = iRLC(instr, &RD);
        break;
    case 0x3: // RLC E
        LOG("RLC E");
        clk = iRLC(instr, &RE);
        break;
    case 0x4: // RLC H
        LOG("RLC H");
        clk = iRLC(instr, &RH);
        break;
    case 0x5: // RLC L
        LOG("RLC L");
        clk = iRLC(instr, &RL);
        break;
    case 0x6: // RLC (HL)
        LOG("RLC (HL)");
        clk = iRLC(instr, HL);
        break;
    case 0x7: // RLC A
        LOG("RLC A");
        clk = iRLC(instr, &RA);
        break;
    case 0x8: // RRC B
        LOG("RRC B");
        clk = iRRC(instr, &RB);
        break;
    case 0x9: // RRC C
        LOG("RRC C");
        clk = iRRC(instr, &RC);
        break;
    case 0xa: // RRC D
        LOG("RRC D");
        clk = iRRC(instr, &RD);
        break;
    case 0xb: // RRC E
        LOG("RRC E");
        clk = iRRC(instr, &RE);
        break;
    case 0xc: // RRC H
        LOG("RRC H");
        clk = iRRC(instr, &RH);
        break;
    case 0xd: // RRC L
        LOG("RRC L");
        clk = iRRC(instr, &RL);
        break;
    case 0xe: // RRC (HL)
        LOG("RRC (HL)");
        clk = iRRC(instr, HL);
        break;
    case 0xf: // RRC A
        LOG("RRC A");
        clk = iRRC(instr, &RA);
        break;
    case 0x10: // RLE B
        LOG("RLE B");
        clk = iRLE(instr, &RB);
        break;
    case 0x11: // RLE C
        LOG("RLE C");
        clk = iRLE(instr, &RC);
        break;
    case 0x12: // RLE D
        LOG("RLE D");
        clk = iRLE(instr, &RD);
        break;
    case 0x13: // RLE E
        LOG("RLE E");
        clk = iRLE(instr, &RE);
        break;
    case 0x14: // RLE H
        LOG("RLE H");
        clk = iRLE(instr, &RH);
        break;
    case 0x15: // RLE L
        LOG("RLE L");
        clk = iRLE(instr, &RL);
        break;
    case 0x16: // RLE (HL)
        LOG("RLE (HL)");
        clk = iRLE(instr, HL);
        break;
    case 0x17: // RLE A
        LOG("RLE A");
        clk = iRLE(instr, &RA);
        break;
    case 0x18: // RR B
        LOG("RR B");
        clk = iRR(instr, &RB);
        break;
    case 0x19: // RR C
        LOG("RR C");
        clk = iRR(instr, &RC);
        break;
    case 0x1a: // RR D
        LOG("RR D");
        clk = iRR(instr, &RD);
        break;
    case 0x1b: // RR E
        LOG("RR E");
        clk = iRR(instr, &RE);
        break;
    case 0x1c: // RR H
        LOG("RR H");
        clk = iRR(instr, &RH);
        break;
    case 0x1d: // RR L
        LOG("RR L");
        clk = iRR(instr, &RL);
        break;
    case 0x1e: // RR (HL)
        LOG("RR (HL)");
        clk = iRR(instr, HL);
        break;
    case 0x1f: // RR A
        LOG("RR A");
        clk = iRR(instr, &RA);
        break;
    case 0x20: // SLA B
        LOG("SLA B");
        clk = iSLA(instr, &RB);
        break;
    case 0x21: // SLA C
        LOG("SLA C");
        clk = iSLA(instr, &RC);
        break;
    case 0x22: // SLA D
        LOG("SLA D");
        clk = iSLA(instr, &RD);
        break;
    case 0x23: // SLA E
        LOG("SLA E");
        clk = iSLA(instr, &RE);
        break;
    case 0x24: // SLA H
        LOG("SLA H");
        clk = iSLA(instr, &RH);
        break;
    case 0x25: // SLA L
        LOG("SLA L");
        clk = iSLA(instr, &RL);
        break;
    case 0x26: // SLA (HL)
        LOG("SLA (HL)");
        clk = iSLA(instr, HL);
        break;
    case 0x27: // SLA A
        LOG("SLA A");
        clk = iSLA(instr, &RA);
        break;
    case 0x28: // SRA B
        LOG("SRA B");
        clk = iSRA(instr, &RB);
        break;
    case 0x29: // SRA C
        LOG("SRA C");
        clk = iSRA(instr, &RC);
        break;
    case 0x2a: // SRA D
        LOG("SRA D");
        clk = iSRA(instr, &RD);
        break;
    case 0x2b: // SRA E
        LOG("SRA E");
        clk = iSRA(instr, &RE);
        break;
    case 0x2c: // SRA H
        LOG("SRA H");
        clk = iSRA(instr, &RH);
        break;
    case 0x2d: // SRA L
        LOG("SRA L");
        clk = iSRA(instr, &RL);
        break;
    case 0x2e: // SRA (HL)
        LOG("SRA (HL)");
        clk = iSRA(instr, HL);
        break;
    case 0x2f: // SRA A
        LOG("SRA A");
        clk = iSRA(instr, &RA);
        break;
    case 0x30: // SWAP B
        LOG("SWAP B");
        clk = iSWAP(instr, &RB);
        break;
    case 0x31: // SWAP C
        LOG("SWAP C");
        clk = iSWAP(instr, &RC);
        break;
    case 0x32: // SWAP D
        LOG("SWAP D");
        clk = iSWAP(instr, &RD);
        break;
    case 0x33: // SWAP E
        LOG("SWAP E");
        clk = iSWAP(instr, &RE);
        break;
    case 0x34: // SWAP H
        LOG("SWAP H");
        clk = iSWAP(instr, &RH);
        break;
    case 0x35: // SWAP L
        LOG("SWAP L");
        clk = iSWAP(instr, &RL);
        break;
    case 0x36: // SWAP (HL)
        LOG("SWAP (HL)");
        clk = iSWAP(instr, HL);
        break;
    case 0x37: // SWAP A
        LOG("SWAP A");
        clk = iSWAP(instr, &RA);
        break;
    case 0x38: // SRL B
        LOG("SRL B");
        clk = iSRL(instr, &RB);
        break;
    case 0x39: // SRL C
        LOG("SRL C");
        clk = iSRL(instr, &RC);
        break;
    case 0x3a: // SRL D
        LOG("SRL D");
        clk = iSRL(instr, &RD);
        break;
    case 0x3b: // SRL E
        LOG("SRL E");
        clk = iSRL(instr, &RE);
        break;
    case 0x3c: // SRL H
        LOG("SRL H");
        clk = iSRL(instr, &RH);
        break;
    case 0x3d: // SRL L
        LOG("SRL L");
        clk = iSRL(instr, &RL);
        break;
    case 0x3e: // SRL (HL)
        LOG("SRL (HL)");
        clk = iSRL(instr, HL);
        break;
    case 0x3f: // SRL A
        LOG("SRL A");
        clk = iSRL(instr, &RA);
        break;
    case 0x40: // BIT 0,B
        LOG("BIT 0,B");
        clk = iBIT(instr, 0x0, &RB);
        break;
    case 0x41: // BIT 0,C
        LOG("BIT 0,C");
        clk = iBIT(instr, 0x0, &RC);
        break;
    case 0x42: // BIT 0,D
        LOG("BIT 0,D");
        clk = iBIT(instr, 0x0, &RD);
        break;
    case 0x43: // BIT 0,E
        LOG("BIT 0,E");
        clk = iBIT(instr, 0x0, &RE);
        break;
    case 0x44: // BIT 0,H
        LOG("BIT 0,H");
        clk = iBIT(instr, 0x0, &RH);
        break;
    case 0x45: // BIT 0,L
        LOG("BIT 0,L");
        clk = iBIT(instr, 0x0, &RL);
        break;
    case 0x46: // BIT 0,(HL)
        LOG("BIT 0,(HL)");
        clk = iBIT(instr, 0x0, HL);
        break;
    case 0x47: // BIT 0,A
        LOG("BIT 0,A");
        clk = iBIT(instr, 0x0, &RA);
        break;
    case 0x48: // BIT 1,B
        LOG("BIT 1,B");
        clk = iBIT(instr, 0x1, &RB);
        break;
    case 0x49: // BIT 1,C
        LOG("BIT 1,C");
        clk = iBIT(instr, 0x1, &RC);
        break;
    case 0x4a: // BIT 1,D
        LOG("BIT 1,D");
        clk = iBIT(instr, 0x1, &RD);
        break;
    case 0x4b: // BIT 1,E
        LOG("BIT 1,E");
        clk = iBIT(instr, 0x1, &RE);
        break;
    case 0x4c: // BIT 1,H
        LOG("BIT 1,H");
        clk = iBIT(instr, 0x1, &RH);
        break;
    case 0x4d: // BIT 1,L
        LOG("BIT 1,L");
        clk = iBIT(instr, 0x1, &RL);
        break;
    case 0x4e: // BIT 1,(HL)
        LOG("BIT 1,(HL)");
        clk = iBIT(instr, 0x1, HL);
        break;
    case 0x4f: // BIT 1,A
        LOG("BIT 1,A");
        clk = iBIT(instr, 0x1, &RA);
        break;
    case 0x50: // BIT 2,B
        LOG("BIT 2,B");
        clk = iBIT(instr, 0x2, &RB);
        break;
    case 0x51: // BIT 2,C
        LOG("BIT 2,C");
        clk = iBIT(instr, 0x2, &RC);
        break;
    case 0x52: // BIT 2,D
        LOG("BIT 2,D");
        clk = iBIT(instr, 0x2, &RD);
        break;
    case 0x53: // BIT 2,E
        LOG("BIT 2,E");
        clk = iBIT(instr, 0x2, &RE);
        break;
    case 0x54: // BIT 2,H
        LOG("BIT 2,H");
        clk = iBIT(instr, 0x2, &RH);
        break;
    case 0x55: // BIT 2,L
        LOG("BIT 2,L");
        clk = iBIT(instr, 0x2, &RL);
        break;
    case 0x56: // BIT 2,(HL)
        LOG("BIT 2,(HL)");
        clk = iBIT(instr, 0x2, HL);
        break;
    case 0x57: // BIT 2,A
        LOG("BIT 2,A");
        clk = iBIT(instr, 0x2, &RA);
        break;
    case 0x58: // BIT 3,B
        LOG("BIT 3,B");
        clk = iBIT(instr, 0x3, &RB);
        break;
    case 0x59: // BIT 3,C
        LOG("BIT 3,C");
        clk = iBIT(instr, 0x3, &RC);
        break;
    case 0x5a: // BIT 3,D
        LOG("BIT 3,D");
        clk = iBIT(instr, 0x3, &RD);
        break;
    case 0x5b: // BIT 3,E
        LOG("BIT 3,E");
        clk = iBIT(instr, 0x3, &RE);
        break;
    case 0x5c: // BIT 3,H
        LOG("BIT 3,H");
        clk = iBIT(instr, 0x3, &RH);
        break;
    case 0x5d: // BIT 3,L
        LOG("BIT 3,L");
        clk = iBIT(instr, 0x3, &RL);
        break;
    case 0x5e: // BIT 3,(HL)
        LOG("BIT 3,(HL)");
        clk = iBIT(instr, 0x3, HL);
        break;
    case 0x5f: // BIT 3,A
        LOG("BIT 3,A");
        clk = iBIT(instr, 0x3, &RA);
        break;
    case 0x60: // BIT 4,B
        LOG("BIT 4,B");
        clk = iBIT(instr, 0x4, &RB);
        break;
    case 0x61: // BIT 4,C
        LOG("BIT 4,C");
        clk = iBIT(instr, 0x4, &RC);
        break;
    case 0x62: // BIT 4,D
        LOG("BIT 4,D");
        clk = iBIT(instr, 0x4, &RD);
        break;
    case 0x63: // BIT 4,E
        LOG("BIT 4,E");
        clk = iBIT(instr, 0x4, &RE);
        break;
    case 0x64: // BIT 4,H
        LOG("BIT 4,H");
        clk = iBIT(instr, 0x4, &RH);
        break;
    case 0x65: // BIT 4,L
        LOG("BIT 4,L");
        clk = iBIT(instr, 0x4, &RL);
        break;
    case 0x66: // BIT 4,(HL)
        LOG("BIT 4,(HL)");
        clk = iBIT(instr, 0x4, HL);
        break;
    case 0x67: // BIT 4,A
        LOG("BIT 4,A");
        clk = iBIT(instr, 0x4, &RA);
        break;
    case 0x68: // BIT 5,B
        LOG("BIT 5,B");
        clk = iBIT(instr, 0x5, &RB);
        break;
    case 0x69: // BIT 5,C
        LOG("BIT 5,C");
        clk = iBIT(instr, 0x5, &RC);
        break;
    case 0x6a: // BIT 5,D
        LOG("BIT 5,D");
        clk = iBIT(instr, 0x5, &RD);
        break;
    case 0x6b: // BIT 5,E
        LOG("BIT 5,E");
        clk = iBIT(instr, 0x5, &RE);
        break;
    case 0x6c: // BIT 5,H
        LOG("BIT 5,H");
        clk = iBIT(instr, 0x5, &RH);
        break;
    case 0x6d: // BIT 5,L
        LOG("BIT 5,L");
        clk = iBIT(instr, 0x5, &RL);
        break;
    case 0x6e: // BIT 5,(HL)
        LOG("BIT 5,(HL)");
        clk = iBIT(instr, 0x5, HL);
        break;
    case 0x6f: // BIT 5,A
        LOG("BIT 5,A");
        clk = iBIT(instr, 0x5, &RA);
        break;
    case 0x70: // BIT 6,B
        LOG("BIT 6,B");
        clk = iBIT(instr, 0x6, &RB);
        break;
    case 0x71: // BIT 6,C
        LOG("BIT 6,C");
        clk = iBIT(instr, 0x6, &RC);
        break;
    case 0x72: // BIT 6,D
        LOG("BIT 6,D");
        clk = iBIT(instr, 0x6, &RD);
        break;
    case 0x73: // BIT 6,E
        LOG("BIT 6,E");
        clk = iBIT(instr, 0x6, &RE);
        break;
    case 0x74: // BIT 6,H
        LOG("BIT 6,H");
        clk = iBIT(instr, 0x6, &RH);
        break;
    case 0x75: // BIT 6,L
        LOG("BIT 6,L");
        clk = iBIT(instr, 0x6, &RL);
        break;
    case 0x76: // BIT 6,(HL)
        LOG("BIT 6,(HL)");
        clk = iBIT(instr, 0x6, HL);
        break;
    case 0x77: // BIT 6,A
        LOG("BIT 6,A");
        clk = iBIT(instr, 0x6, &RA);
        break;
    case 0x78: // BIT 7,B
        LOG("BIT 7,B");
        clk = iBIT(instr, 0x7, &RB);
        break;
    case 0x79: // BIT 7,C
        LOG("BIT 7,C");
        clk = iBIT(instr, 0x7, &RC);
        break;
    case 0x7a: // BIT 7,D
        LOG("BIT 7,D");
        clk = iBIT(instr, 0x7, &RD);
        break;
    case 0x7b: // BIT 7,E
        LOG("BIT 7,E");
        clk = iBIT(instr, 0x7, &RE);
        break;
    case 0x7c: // BIT 7,H
        LOG("BIT 7,H");
        clk = iBIT(instr, 0x7, &RH);
        break;
    case 0x7d: // BIT 7,L
        LOG("BIT 7,L");
        clk = iBIT(instr, 0x7, &RL);
        break;
    case 0x7e: // BIT 7,(HL)
        LOG("BIT 7,(HL)");
        clk = iBIT(instr, 0x7, HL);
        break;
    case 0x7f: // BIT 7,A
        LOG("BIT 7,A");
        clk = iBIT(instr, 0x7, &RA);
        break;
    case 0x80: // RES 0,B
        LOG("RES 0,B");
        clk = iRES(instr, 0x0, &RB);
        break;
    case 0x81: // RES 0,C
        LOG("RES 0,C");
        clk = iRES(instr, 0x0, &RC);
        break;
    case 0x82: // RES 0,D
        LOG("RES 0,D");
        clk = iRES(instr, 0x0, &RD);
        break;
    case 0x83: // RES 0,E
        LOG("RES 0,E");
        clk = iRES(instr, 0x0, &RE);
        break;
    case 0x84: // RES 0,H
        LOG("RES 0,H");
        clk = iRES(instr, 0x0, &RH);
        break;
    case 0x85: // RES 0,L
        LOG("RES 0,L");
        clk = iRES(instr, 0x0, &RL);
        break;
    case 0x86: // RES 0,(HL)
        LOG("RES 0,(HL)");
        clk = iRES(instr, 0x0, HL);
        break;
    case 0x87: // RES 0,A
        LOG("RES 0,A");
        clk = iRES(instr, 0x0, &RA);
        break;
    case 0x88: // RES 1,B
        LOG("RES 1,B");
        clk = iRES(instr, 0x1, &RB);
        break;
    case 0x89: // RES 1,C
        LOG("RES 1,C");
        clk = iRES(instr, 0x1, &RC);
        break;
    case 0x8a: // RES 1,D
        LOG("RES 1,D");
        clk = iRES(instr, 0x1, &RD);
        break;
    case 0x8b: // RES 1,E
        LOG("RES 1,E");
        clk = iRES(instr, 0x1, &RE);
        break;
    case 0x8c: // RES 1,H
        LOG("RES 1,H");
        clk = iRES(instr, 0x1, &RH);
        break;
    case 0x8d: // RES 1,L
        LOG("RES 1,L");
        clk = iRES(instr, 0x1, &RL);
        break;
    case 0x8e: // RES 1,(HL)
        LOG("RES 1,(HL)");
        clk = iRES(instr, 0x1, HL);
        break;
    case 0x8f: // RES 1,A
        LOG("RES 1,A");
        clk = iRES(instr, 0x1, &RA);
        break;
    case 0x90: // RES 2,B
        LOG("RES 2,B");
        clk = iRES(instr, 0x2, &RB);
        break;
    case 0x91: // RES 2,C
        LOG("RES 2,C");
        clk = iRES(instr, 0x2, &RC);
        break;
    case 0x92: // RES 2,D
        LOG("RES 2,D");
        clk = iRES(instr, 0x2, &RD);
        break;
    case 0x93: // RES 2,E
        LOG("RES 2,E");
        clk = iRES(instr, 0x2, &RE);
        break;
    case 0x94: // RES 2,H
        LOG("RES 2,H");
        clk = iRES(instr, 0x2, &RH);
        break;
    case 0x95: // RES 2,L
        LOG("RES 2,L");
        clk = iRES(instr, 0x2, &RL);
        break;
    case 0x96: // RES 2,(HL)
        LOG("RES 2,(HL)");
        clk = iRES(instr, 0x2, HL);
        break;
    case 0x97: // RES 2,A
        LOG("RES 2,A");
        clk = iRES(instr, 0x2, &RA);
        break;
    case 0x98: // RES 3,B
        LOG("RES 3,B");
        clk = iRES(instr, 0x3, &RB);
        break;
    case 0x99: // RES 3,C
        LOG("RES 3,C");
        clk = iRES(instr, 0x3, &RC);
        break;
    case 0x9a: // RES 3,D
        LOG("RES 3,D");
        clk = iRES(instr, 0x3, &RD);
        break;
    case 0x9b: // RES 3,E
        LOG("RES 3,E");
        clk = iRES(instr, 0x3, &RE);
        break;
    case 0x9c: // RES 3,H
        LOG("RES 3,H");
        clk = iRES(instr, 0x3, &RH);
        break;
    case 0x9d: // RES 3,L
        LOG("RES 3,L");
        clk = iRES(instr, 0x3, &RL);
        break;
    case 0x9e: // RES 3,(HL)
        LOG("RES 3,(HL)");
        clk = iRES(instr, 0x3, HL);
        break;
    case 0x9f: // RES 3,A
        LOG("RES 3,A");
        clk = iRES(instr, 0x3, &RA);
        break;
    case 0xa0: // RES 4,B
        LOG("RES 4,B");
        clk = iRES(instr, 0x4, &RB);
        break;
    case 0xa1: // RES 4,C
        LOG("RES 4,C");
        clk = iRES(instr, 0x4, &RC);
        break;
    case 0xa2: // RES 4,D
        LOG("RES 4,D");
        clk = iRES(instr, 0x4, &RD);
        break;
    case 0xa3: // RES 4,E
        LOG("RES 4,E");
        clk = iRES(instr, 0x4, &RE);
        break;
    case 0xa4: // RES 4,H
        LOG("RES 4,H");
        clk = iRES(instr, 0x4, &RH);
        break;
    case 0xa5: // RES 4,L
        LOG("RES 4,L");
        clk = iRES(instr, 0x4, &RL);
        break;
    case 0xa6: // RES 4,(HL)
        LOG("RES 4,(HL)");
        clk = iRES(instr, 0x4, HL);
        break;
    case 0xa7: // RES 4,A
        LOG("RES 4,A");
        clk = iRES(instr, 0x4, &RA);
        break;
    case 0xa8: // RES 5,B
        LOG("RES 5,B");
        clk = iRES(instr, 0x5, &RB);
        break;
    case 0xa9: // RES 5,C
        LOG("RES 5,C");
        clk = iRES(instr, 0x5, &RC);
        break;
    case 0xaa: // RES 5,D
        LOG("RES 5,D");
        clk = iRES(instr, 0x5, &RD);
        break;
    case 0xab: // RES 5,E
        LOG("RES 5,E");
        clk = iRES(instr, 0x5, &RE);
        break;
    case 0xac: // RES 5,H
        LOG("RES 5,H");
        clk = iRES(instr, 0x5, &RH);
        break;
    case 0xad: // RES 5,L
        LOG("RES 5,L");
        clk = iRES(instr, 0x5, &RL);
        break;
    case 0xae: // RES 5,(HL)
        LOG("RES 5,(HL)");
        clk = iRES(instr, 0x5, HL);
        break;
    case 0xaf: // RES 5,A
        LOG("RES 5,A");
        clk = iRES(instr, 0x5, &RA);
        break;
    case 0xb0: // RES 6,B
        LOG("RES 6,B");
        clk = iRES(instr, 0x6, &RB);
        break;
    case 0xb1: // RES 6,C
        LOG("RES 6,C");
        clk = iRES(instr, 0x6, &RC);
        break;
    case 0xb2: // RES 6,D
        LOG("RES 6,D");
        clk = iRES(instr, 0x6, &RD);
        break;
    case 0xb3: // RES 6,E
        LOG("RES 6,E");
        clk = iRES(instr, 0x6, &RE);
        break;
    case 0xb4: // RES 6,H
        LOG("RES 6,H");
        clk = iRES(instr, 0x6, &RH);
        break;
    case 0xb5: // RES 6,L
        LOG("RES 6,L");
        clk = iRES(instr, 0x6, &RL);
        break;
    case 0xb6: // RES 6,(HL)
        LOG("RES 6,(HL)");
        clk = iRES(instr, 0x6, HL);
        break;
    case 0xb7: // RES 6,A
        LOG("RES 6,A");
        clk = iRES(instr, 0x6, &RA);
        break;
    case 0xb8: // RES 7,B
        LOG("RES 7,B");
        clk = iRES(instr, 0x7, &RB);
        break;
    case 0xb9: // RES 7,C
        LOG("RES 7,C");
        clk = iRES(instr, 0x7, &RC);
        break;
    case 0xba: // RES 7,D
        LOG("RES 7,D");
        clk = iRES(instr, 0x7, &RD);
        break;
    case 0xbb: // RES 7,E
        LOG("RES 7,E");
        clk = iRES(instr, 0x7, &RE);
        break;
    case 0xbc: // RES 7,H
        LOG("RES 7,H");
        clk = iRES(instr, 0x7, &RH);
        break;
    case 0xbd: // RES 7,L
        LOG("RES 7,L");
        clk = iRES(instr, 0x7, &RL);
        break;
    case 0xbe: // RES 7,(HL)
        LOG("RES 7,(HL)");
        clk = iRES(instr, 0x7, HL);
        break;
    case 0xbf: // RES 7,A
        LOG("RES 7,A");
        clk = iRES(instr, 0x7, &RA);
        break;
    case 0xc0: // SET 0,B
        LOG("SET 0,B");
        clk = iSET(instr, 0x0, &RB);
        break;
    case 0xc1: // SET 0,C
        LOG("SET 0,C");
        clk = iSET(instr, 0x0, &RC);
        break;
    case 0xc2: // SET 0,D
        LOG("SET 0,D");
        clk = iSET(instr, 0x0, &RD);
        break;
    case 0xc3: // SET 0,E
        LOG("SET 0,E");
        clk = iSET(instr, 0x0, &RE);
        break;
    case 0xc4: // SET 0,H
        LOG("SET 0,H");
        clk = iSET(instr, 0x0, &RH);
        break;
    case 0xc5: // SET 0,L
        LOG("SET 0,L");
        clk = iSET(instr, 0x0, &RL);
        break;
    case 0xc6: // SET 0,(HL)
        LOG("SET 0,(HL)");
        clk = iSET(instr, 0x0, HL);
        break;
    case 0xc7: // SET 0,A
        LOG("SET 0,A");
        clk = iSET(instr, 0x0, &RA);
        break;
    case 0xc8: // SET 1,B
        LOG("SET 1,B");
        clk = iSET(instr, 0x1, &RB);
        break;
    case 0xc9: // SET 1,C
        LOG("SET 1,C");
        clk = iSET(instr, 0x1, &RC);
        break;
    case 0xca: // SET 1,D
        LOG("SET 1,D");
        clk = iSET(instr, 0x1, &RD);
        break;
    case 0xcb: // SET 1,E
        LOG("SET 1,E");
        clk = iSET(instr, 0x1, &RE);
        break;
    case 0xcc: // SET 1,H
        LOG("SET 1,H");
        clk = iSET(instr, 0x1, &RH);
        break;
    case 0xcd: // SET 1,L
        LOG("SET 1,L");
        clk = iSET(instr, 0x1, &RL);
        break;
    case 0xce: // SET 1,(HL)
        LOG("SET 1,(HL)");
        clk = iSET(instr, 0x1, HL);
        break;
    case 0xcf: // SET 1,A
        LOG("SET 1,A");
        clk = iSET(instr, 0x1, &RA);
        break;
    case 0xd0: // SET 2,B
        LOG("SET 2,B");
        clk = iSET(instr, 0x2, &RB);
        break;
    case 0xd1: // SET 2,C
        LOG("SET 2,C");
        clk = iSET(instr, 0x2, &RC);
        break;
    case 0xd2: // SET 2,D
        LOG("SET 2,D");
        clk = iSET(instr, 0x2, &RD);
        break;
    case 0xd3: // SET 2,E
        LOG("SET 2,E");
        clk = iSET(instr, 0x2, &RE);
        break;
    case 0xd4: // SET 2,H
        LOG("SET 2,H");
        clk = iSET(instr, 0x2, &RH);
        break;
    case 0xd5: // SET 2,L
        LOG("SET 2,L");
        clk = iSET(instr, 0x2, &RL);
        break;
    case 0xd6: // SET 2,(HL)
        LOG("SET 2,(HL)");
        clk = iSET(instr, 0x2, HL);
        break;
    case 0xd7: // SET 2,A
        LOG("SET 2,A");
        clk = iSET(instr, 0x2, &RA);
        break;
    case 0xd8: // SET 3,B
        LOG("SET 3,B");
        clk = iSET(instr, 0x3, &RB);
        break;
    case 0xd9: // SET 3,C
        LOG("SET 3,C");
        clk = iSET(instr, 0x3, &RC);
        break;
    case 0xda: // SET 3,D
        LOG("SET 3,D");
        clk = iSET(instr, 0x3, &RD);
        break;
    case 0xdb: // SET 3,E
        LOG("SET 3,E");
        clk = iSET(instr, 0x3, &RE);
        break;
    case 0xdc: // SET 3,H
        LOG("SET 3,H");
        clk = iSET(instr, 0x3, &RH);
        break;
    case 0xdd: // SET 3,L
        LOG("SET 3,L");
        clk = iSET(instr, 0x3, &RL);
        break;
    case 0xde: // SET 3,(HL)
        LOG("SET 3,(HL)");
        clk = iSET(instr, 0x3, HL);
        break;
    case 0xdf: // SET 3,A
        LOG("SET 3,A");
        clk = iSET(instr, 0x3, &RA);
        break;
    case 0xe0: // SET 4,B
        LOG("SET 4,B");
        clk = iSET(instr, 0x4, &RB);
        break;
    case 0xe1: // SET 4,C
        LOG("SET 4,C");
        clk = iSET(instr, 0x4, &RC);
        break;
    case 0xe2: // SET 4,D
        LOG("SET 4,D");
        clk = iSET(instr, 0x4, &RD);
        break;
    case 0xe3: // SET 4,E
        LOG("SET 4,E");
        clk = iSET(instr, 0x4, &RE);
        break;
    case 0xe4: // SET 4,H
        LOG("SET 4,H");
        clk = iSET(instr, 0x4, &RH);
        break;
    case 0xe5: // SET 4,L
        LOG("SET 4,L");
        clk = iSET(instr, 0x4, &RL);
        break;
    case 0xe6: // SET 4,(HL)
        LOG("SET 4,(HL)");
        clk = iSET(instr, 0x4, HL);
        break;
    case 0xe7: // SET 4,A
        LOG("SET 4,A");
        clk = iSET(instr, 0x4, &RA);
        break;
    case 0xe8: // SET 5,B
        LOG("SET 5,B");
        clk = iSET(instr, 0x5, &RB);
        break;
    case 0xe9: // SET 5,C
        LOG("SET 5,C");
        clk = iSET(instr, 0x5, &RC);
        break;
    case 0xea: // SET 5,D
        LOG("SET 5,D");
        clk = iSET(instr, 0x5, &RD);
        break;
    case 0xeb: // SET 5,E
        LOG("SET 5,E");
        clk = iSET(instr, 0x5, &RE);
        break;
    case 0xec: // SET 5,H
        LOG("SET 5,H");
        clk = iSET(instr, 0x5, &RH);
        break;
    case 0xed: // SET 5,L
        LOG("SET 5,L");
        clk = iSET(instr, 0x5, &RL);
        break;
    case 0xee: // SET 5,(HL)
        LOG("SET 5,(HL)");
        clk = iSET(instr, 0x5, HL);
        break;
    case 0xef: // SET 5,A
        LOG("SET 5,A");
        clk = iSET(instr, 0x5, &RA);
        break;
    case 0xf0: // SET 6,B
        LOG("SET 6,B");
        clk = iSET(instr, 0x6, &RB);
        break;
    case 0xf1: // SET 6,C
        LOG("SET 6,C");
        clk = iSET(instr, 0x6, &RC);
        break;
    case 0xf2: // SET 6,D
        LOG("SET 6,D");
        clk = iSET(instr, 0x6, &RD);
        break;
    case 0xf3: // SET 6,E
        LOG("SET 6,E");
        clk = iSET(instr, 0x6, &RE);
        break;
    case 0xf4: // SET 6,H
        LOG("SET 6,H");
        clk = iSET(instr, 0x6, &RH);
        break;
    case 0xf5: // SET 6,L
        LOG("SET 6,L");
        clk = iSET(instr, 0x6, &RL);
        break;
    case 0xf6: // SET 6,(HL)
        LOG("SET 6,(HL)");
        clk = iSET(instr, 0x6, HL);
        break;
    case 0xf7: // SET 6,A
        LOG("SET 6,A");
        clk = iSET(instr, 0x6, &RA);
        break;
    case 0xf8: // SET 7,B
        LOG("SET 7,B");
        clk = iSET(instr, 0x7, &RB);
        break;
    case 0xf9: // SET 7,C
        LOG("SET 7,C");
        clk = iSET(instr, 0x7, &RC);
        break;
    case 0xfa: // SET 7,D
        LOG("SET 7,D");
        clk = iSET(instr, 0x7, &RD);
        break;
    case 0xfb: // SET 7,E
        LOG("SET 7,E");
        clk = iSET(instr, 0x7, &RE);
        break;
    case 0xfc: // SET 7,H
        LOG("SET 7,H");
        clk = iSET(instr, 0x7, &RH);
        break;
    case 0xfd: // SET 7,L
        LOG("SET 7,L");
        clk = iSET(instr, 0x7, &RL);
        break;
    case 0xfe: // SET 7,(HL)
        LOG("SET 7,(HL)");
        clk = iSET(instr, 0x7, HL);
        break;
    case 0xff: // SET 7,A
        LOG("SET 7,A");
        clk = iSET(instr, 0x7, &RA);
        break;
    default: iUNDEF(instr);
}
#undef OPn
#undef OPn
