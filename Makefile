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
ALLFLAGS = -std=c++17
LIBS = -lm
CC = g++

SRCS := $(wildcard $(SRC)/*.cpp)
BINS := $(SRCS:$(SRC)/%.cpp=$(BIN)/%.o)
DEPS := $(wildcard $(INC)/*.h)


# --- main commands ---
all: simulate vector3d body gravity FRK4

simulate: $(DEPS) vector3d body gravity FRK4
	$(CC) $(FLAGS) $(ALLFLAGS) vector3d.o body.o gravity.o FRK4.o $(SRC)/simulate.cpp -o $(BIN)/simulate $(LIBS)

# --- dependencies ---
vector3d: $(SRC)/vector3d.cpp $(INC)/vector3d.h
	$(CC) -I$(INC) $(ALLFLAGS) -c $(SRC)/vector3d.cpp

body: $(SRC)/body.cpp $(INC)/body.h
	$(CC) -I$(INC) $(ALLFLAGS) -c $(SRC)/body.cpp

gravity: $(SRC)/gravity.cpp $(INC)/gravity.h $(INC)/constants.h
	$(CC) -I$(INC) $(ALLFLAGS) -c $(SRC)/gravity.cpp

FRK4: $(SRC)/FRK4.cpp $(INC)/FRK4.h vector3d
	$(CC) -I$(INC) $(ALLFLAGS) -c $(SRC)/FRK4.cpp


clean:
	rm -rf $(BIN)/*
