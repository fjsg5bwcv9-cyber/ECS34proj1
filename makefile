AR=ar
CC=gcc
CXX=g++

INC_DIR=./include
SRC_DIR=./src
BIN_DIR=./bin
OBJ_DIR=./obj
HTMLCOV_DIR=./htmlcov
LIB_DIR=./lib
TESTBIN_DIR=./testbin
TESTOBJ_DIR=./testobj
TESTSRC_DIR=./testsrc
TESTCOVER_DIR=./testcover

all:directories

.PHONY: directories
directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(HTMLCOV_DIR)
	mkdir -p $(LIB_DIR)
	mkdir -p $(TESTBIN_DIR)
	mkdir -p $(TESTOBJ_DIR)

CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -g
CPPFLAGS=-Iinclude

# objects / exe
STRUTILS_OBJ=$(OBJ_DIR)/StringUtils.o
TEST_OBJ=$(TESTOBJ_DIR)/StringUtilsTest.o
TEST_EXE=$(TESTBIN_DIR)/teststrutils

.PHONY: test clean

$(STRUTILS_OBJ): $(SRC_DIR)/StringUtils.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(TEST_OBJ): $(TESTSRC_DIR)/StringUtilsTest.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(TEST_EXE): directories $(STRUTILS_OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(STRUTILS_OBJ) $(TEST_OBJ) -lgtest -lgtest_main -pthread -o $@

test: $(TEST_EXE)
	./$(TEST_EXE)

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR) $(LIB_DIR) $(TESTBIN_DIR) $(TESTOBJ_DIR) $(HTMLCOV_DIR)