CC = g++
PROG_NAME = calc

OUT_DIR = bin
INCLUDE_DIR = include
BUILD_DIR = build
SRC = src

OUT = $(OUT_DIR)/$(PROG_NAME).exe
FILES = $(patsubst $(SRC)/%.cpp,%.cpp,$(wildcard $(SRC)/*.cpp))

SRCS = $(foreach file,$(FILES),$(SRC)/$(file))
OBJS = $(foreach file,$(subst .cpp,.o,$(FILES)),$(BUILD_DIR)/$(file))

all: $(OBJS)
	$(CC) -I$(INCLUDE_DIR) -o $(OUT) $(OBJS) main.cpp

$(BUILD_DIR)/%.o: $(SRC)/%.cpp
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

run: all
	$(OUT)

clean:
	-rm -f $(OBJS) $(OUT)
