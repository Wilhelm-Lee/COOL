CC = /bin/x86_64-w64-mingw32-cc
FLAG = -lm -std=c99 -Wall

# PHD: Project Home Directory
PHD = .
BUILD = $(PHD)/build
OBJ = $(PHD)/obj
SRC = $(PHD)/src
SRC_BASE = $(SRC)/base
SRC_OO = $(SRC)/advanced
ICO = $(PHD)/icon
NAM = COOL_MinGW
DBG = $(BUILD)/Debug
RLS = $(BUILD)/Release

COMPI_C   = $(SRC_BASE)
COMPI_OOL = $(PHD)

clean: $(OBJ)/*
	rm -v $(OBJ)/*

# Simply compile files into obj files, without binary complations.
compile_base: $(SRC)/base
	$(CC) -c $(FLAG) -o $(OBJ)/

# Simply compile files into obj files, without binary complations.
complie_advanced: $(SRC)/advanced
	$(CC) -c $(FLAG) -o $(OBJ)/

# Build DeBuG
bdbg: $(SRC)/main.c $(OBJ)/*
	$(CC) -D__DEBUG__ $(FLAG) $(SRC)/main.c -o $(DBG)/$(NAM)

# Build ReLeaSe
brls: $(SRC)/main.c $(OBJ)/*
	$(CC) -D__RELEASE__ $(FLAG) $(SRC)/main.c -o $(RLS)/$(NAM)
