CC = g++
PROG_NAME = calc

OUT_DIR = bin
INCLUDE_DIR = include
BUILD_DIR = build
SRC = src

OUT = $(OUT_DIR)/$(PROG_NAME).exe

FILES = $(patsubst $(SRC)/%.cpp,%.cpp,$(wildcard $(SRC)/*.cpp))
OBJS = $(foreach file,$(subst .cpp,.o,$(FILES)),$(BUILD_DIR)/$(file))

TESTS = $(patsubst tests/%.cpp,%.cpp,$(wildcard tests/*.cpp))
TEST_OBJS = $(foreach file,$(subst .cpp,.o,$(TESTS)),$(BUILD_DIR)/$(file))

all: $(OBJS)
	$(CC) -I$(INCLUDE_DIR) -o $(OUT) $(OBJS) main.cpp

tests: $(OBJS) $(TEST_OBJS)
	$(CC) -I$(INCLUDE_DIR) -Itests -o $(OUT) $(TEST_OBJS) $(OBJS) testmain.cpp
	$(OUT)

$(BUILD_DIR)/%.o: $(SRC)/%.cpp
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: tests/%.cpp
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

run: all
	$(OUT)

clean:
	-rm -f $(OBJS) $(OUT)
