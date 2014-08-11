# ANDER MARTINEZ 2014

PROJECT = gamelad
BUILD_DIR = ./build
SRC_DIR   = ./src
TEST_DIR  = ./tests

## TOOLS
CC  = clang
CCP = clang++
CFLAGS = -c -Wall
CPPFLAGS = -c -Wall
LDFLAGS =
TESTFLAGS = -lgtest -lgtest_main
RM = rm -rf

## SOURCES
HEADERS := $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/gb/core/*.h)
C_SRC   := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/gb/core/*.c)
CPP_SRC := $(wildcard $(SRC_DIR)/gb/core/*.cpp)
CPP_SRC += $(SRC_DIR)/main.cpp
TEST_SRC:= $(wildcard $(TEST_DIR)/*.cpp)

DESKTOP_SRC := $(wildcard $(SRC_DIR)/gb/desktop/*.cpp)
DESKTOP_FLAGS :=  -Wall -I/usr/include/SDL2/  -I $(SRC_DIR) -ggdb -L/usr/lib -lSDL2 -std=c++11

C_OBJ   := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRC))
CPP_OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRC))

## RULES
all: desktop embedded

desktop: $(BUILD_DIR)/$(PROJECT)
$(BUILD_DIR)/$(PROJECT): $(CPP_SRC) $(HEADERS) $(DESKTOP_SRC) instructions
	mkdir -p $(dir $@)
	$(CCP) $(LDFLAGS) -o $@ $(CPP_SRC) $(DESKTOP_SRC) $(DESKTOP_FLAGS) -DDESKTOP -DDEBUG

embedded: $(BUILD_DIR)/$(PROJECT).bin $(BUILD_DIR)/$(PROJECT).elf
$(BUILD_DIR)/$(PROJECT).bin:
$(BUILD_DIR)/$(PROJECT).elf:

test: $(BUILD_DIR)/test
	$<

$(BUILD_DIR)/test: $(TEST_SRC)
	$(CCP) $(TESTFLAGS) $(TEST_SRC) -o $@

clean:
	$(RM) $(BUILD_DIR)

instructions: src/gb/core/instructions.gen
	./tools/instructions.py src/gb/core/instructions.gen
