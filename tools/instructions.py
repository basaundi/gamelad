#!/usr/bin/env python
# ANDER MARTINEZ 2014

from __future__ import print_function # compatibility with python2 and python3
import sys
from os.path import dirname, basename
from os.path import join as pjoin
import re

PAR = r'\(\w\w?\)|\w\w?|\d+'
instr = re.compile(r'([A-Z]+)(\s+(' + PAR + ')(\s*,\s*('+PAR+'))?)?')

def PRINT_USAGE():
	print("USAGE: {0} instructions.gen".format(sys.argv[0]), file=sys.stderr)
	sys.exit(1)

class Generator(object):
	def __init__(self, fname):
		self.out_dir = dirname(fname)
		self.fname = fname
		self.decl_f = pjoin(self.out_dir, 'instructions_decl.h')
		self.switch_f = pjoin(self.out_dir, 'instructions_switch.cc')
		self.switch_map_f = pjoin(self.out_dir, 'instructions_switch_map.cc')
		self.instructions = [None,] * 512

	def read(self):
		count = 0
		with open(self.fname, 'r') as f:
			for line in f:
				line = line.strip()
				if not line: # Empty line
					continue
				if line.startswith('#'): # Comment
					pass #print(line)
				else:
					gs = instr.match(line).groups()
					self.instructions[count] = tuple(filter(None, (gs[0], gs[2], gs[4])))
					count += 1


	def save_declaration(self):
		with open(self.decl_f, 'w') as f:
			p = lambda s: print(s, file=f)
			decl = set()
			for inst in self.instructions:
				dec = list(inst)
				logical = dec[0] in 'RET JP JR CALL'
				for k, par in enumerate(inst[1:]):
					if   par == 'n':  # Immediate value, 8-bit
						dec[k+1] = 'uint8_t'
					elif par == 'd':
						dec[k+1] = 'int8_t'
					elif par == 'nn': # Immediate value, 16-bit
						dec[k+1] = 'uint16_t'
					elif par[0] == '(' and par[1] != 'n' and par[2] == ')': # Address 8-bit
						dec[k+1] = 'uint8_t'
					elif par[0] == '(': # Address
						dec[k+1] = 'uint16_t'
					elif par in 'A B D E H L' or (par == 'C' and not logical):  # 8 bit register
						dec[k+1] = 'uint8_t*'
					elif par in 'AF BC DE HL SP': # 16 bit register
						dec[k+1] = 'uint16_t*'
					elif par in 'Z NZ NC C': # Flag
						dec[k+1] = 'bool'
					else:
						dec[k+1] = 'uint8_t'
				if len(dec) == 1:
					decl.add("uint8_t i{0}(uint8_t instr);".format(dec[0]))
				else:
					decl.add("uint8_t i{0}(uint8_t instr, {1});".format(dec[0], ', '.join(dec[1:])))
			p('\n'.join(sorted(decl)))


	def save_switch(self, cbmap=False):
		if cbmap:
			a, b = 256, 512
			fname = self.switch_map_f
		else:
			a, b = 0, 256
			fname = self.switch_f
		with open(fname, 'w') as f:
			p = lambda s: print(s, file=f)
			p("#define OPn  n  = mem.rb(PC++)")
			p("#define OPnn nn = mem.rw(PC++); PC++")
			p("switch(instr){")
			for n, inst in enumerate(self.instructions[a:b]):
				p("    case {0:#x}: // {1} {2}".format(n, inst[0], ','.join(inst[1:])))
				p("        LOG(\"{1} {2}\");".format(n, inst[0], ','.join(inst[1:])))
				a,b = None,None
				if 'n' in inst or 'd' in inst or '(n)' in inst:
					p("        OPn;")
				if 'nn' in inst or '(nn)' in inst:
					p("        OPnn;")

				para = ['instr',]
				for par in inst[1:]:
					if par in ('n', 'nn'): # Immediate value
						para.append(par)
					elif par == 'd':
						para.append('(int8_t) n')
					elif par[0] == '(' and par[1] != 'n' and par[2] == ')': # Address 8-bit
						para.append('R'+par[1:-1])
					elif par[0] == '(': # Address 16-bit
						para.append(par[1:-1])
					elif par in 'A B C D E H L': # 8 bit register
						para.append('&R'+par)
					elif par in 'AF BC DE HL SP': # 16 bit register
						para.append('&'+par)
					elif par in 'Z': # Flag
						para.append('F'+par)
					elif par in 'NZ NC': # Flag
						para.append('!F'+par[1])
					elif par in ("0", "1", "2", "3", "4", "5", "6", "7", "8", "10", "18", "20", "28", "30", "38"): # Hard-coded value
						para.append('0x'+par)
					else:
						print(par)
				p("        clk = i{0}({1});".format(inst[0], ', '.join(para)))

				p("        break;")
			p("    default: iUNDEF(instr);")
			p("}")
			p("#undef OPn")
			p("#undef OPn")

	def process(self):
		self.read()
		self.save_switch()
		self.save_switch(True)
		self.save_declaration()

if __name__ == "__main__":
	if len(sys.argv) != 2: PRINT_USAGE()
	gen = Generator(sys.argv[1])
	gen.process()
