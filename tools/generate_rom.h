#!/bin/sh

./vendor/ugfx/tools/file2c/binaries/linux/file2c -sc -n rom $1 > src/rom.h
