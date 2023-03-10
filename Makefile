CC = /bin/x86_64-w64-mingw32-cc
FLAG = -lm -std=c99 -Wall

# PHD: Project Home Directory
PHD = .
BUILD = $(PHD)/build
DBG = $(BUILD)/Debug
RLS = $(BUILD)/Release
OBJ = $(PHD)/obj
SRC = $(PHD)/src
ICO = $(PHD)/icon
NAM = COOL_MinGW

clean: $(OBJ)/*
	rm -v $(OBJ)/*

# Build DeBuG
bdbg: $(SRC)/main.c
	$(CC) $(FLAG) $(SRC)/main.c -o $(DBG)/$(NAM)

# Build ReLeaSe
brls: $(SRC)/main.c
	$(CC) $(FLAG) $(SRC)/main.c -o $(RLS)/$(NAM)
