MAKEFLAGS += -s -j

DIST_DIR = ./dist
SRC_DIR = ./src

SRC_DIRS = $(SRC_DIR) $(wildcard $(SRC_DIR)/*/)

C_SRC = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
CPP_SRC = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)

C_OBJ = $(addprefix $(DIST_DIR)/, $(notdir $(C_SRC:.c=.o)))
CPP_OBJ = $(addprefix $(DIST_DIR)/, $(notdir $(CPP_SRC:.cpp=.o)))

CXX_HEADER = $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/*/*.h)

VERSION_SCRIPT = $(SRC_DIR)/exports.txt

TARGET = steam-pipe.dll
BIN_TARGET = $(DIST_DIR)/$(TARGET)

# Compiler paths.
CC = gcc
CXX = g++

# Params.
CFLAGS = -Wall -Wformat -O3 -ffunction-sections -fdata-sections -static -flto=auto -s -Wno-unused-function -Wno-unused-variable
CFLAGS += -I./src
# Include HTML.
CFLAGS += -I../libraries/htmodloader/includes/htmodloader
CFLAGS += -I../libraries/htmodloader/includes/imgui-1.92.2b
# Include SteamAPI.
CFLAGS += -I../libraries/steam/includes

LFLAGS = -Wl,--gc-sections,-O3,--as-needed,--version-script=$(VERSION_SCRIPT)
LFLAGS += -L../libraries/htmodloader/lib -lhtmodloader
LFLAGS += -L../libraries/steam/lib -lsteam_api64

vpath %.c $(SRC_DIRS)
vpath %.cpp $(SRC_DIRS)

.PHONY: all clean

all: $(DIST_DIR) $(BIN_TARGET)

$(BIN_TARGET): $(C_OBJ) $(CPP_OBJ)
	@echo Linking ...
	@$(CXX) $(CFLAGS) $^ -shared -o $@ $(LFLAGS)
	@echo Done.

$(DIST_DIR)/%.o: %.c $(CXX_HEADER)
	@echo Compiling file "$<" ...
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIST_DIR)/%.o: %.cpp $(CXX_HEADER)
	@echo Compiling file "$<" ...
	@$(CXX) $(CFLAGS) -c $< -o $@

$(DIST_DIR):
	mkdir dist

clean:
	-@del .\dist\*.o
	-@del .\dist\*.dll

all:
	-@$(MAKE) $(BIN_TARGET)

