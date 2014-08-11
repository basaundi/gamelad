
PROJECT = gamelad
BUILD_DIR = ./build
SRC_DIR   = .


## TOOLS
CC  = clang
CXX = clang++
CFLAGS = -c -Wall -I/usr/include/SDL2/ -L/usr/lib
CPPFLAGS =  -Wall -I/usr/include/SDL2/  -I../../../ -ggdb
LDFLAGS =  -L/usr/lib -lSDL2

## SOURCES
HEADERS := $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/gb/core/*.h)
C_SRC   := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/gb/core/*.c)
CPP_SRC := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/../*.cpp)
TEST_SRC:= $(filter %_test.cpp, $(CPP_SRC))
CPP_SRC := $(filter-out %_test.cpp, $(CPP_SRC))

C_OBJ   := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRC))
CPP_OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRC))
TEST_OBJ:= $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%, $(TEST_SRC))

## RULES
all: $(TEST_OBJ)
$(TEST_OBJ): $(CPP_SRC) $(HEADERS) $(TEST_SRC)
	mkdir -p $(dir $@)
	$(CXX) $(LDFLAGS) $(CPPFLAGS) -o $@ $(CPP_SRC) -DDEBUG $(filter %/$(@F).cpp, $(TEST_SRC))

clear:
	rm -rf $(BUILD_DIR)
