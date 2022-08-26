# Makefile for Cluster Merger project

# Usage:
# make		# compile all binary
# make clean	# remove ALL binaries and objects

.PHONY: all clean

# paths
HERE := /Users/zackashm/Documents/Programming/cluster-mergers
BIN := $(HERE)/bin
SRC := $(HERE)/src
INC := $(HERE)/include

# flags
FLAGS = -O3 -W -g -I$(INC)
CC = g++

SRCS := $(wildcard $(SRC)/*.cpp)
BINS := $(SRCS:$(SRC)/%.cpp=$(BIN)/%.o)
DEPS := $(wildcard $(INC)/*.h)


# --- main commands ---
all: simulate

# --- dependencies ---
simulate: $(DEPS)
	$(CC) $(FLAGS) $(SRC)/simulate.cpp -o $(BIN)/simulate



# --- test commands ---
#test:
	#@echo "Hello"
	#${CC} test.c -o test.o


clean:
	rm $(BIN)/*
