CC = /bin/x86_64-w64-mingw32-cc
FLAG = -lm -std=c99 -Wall

# PHD: Project Home Directory
PHD = .
STRUCTURE := $(PHD)/basic $(PHD)/advanced
BUILD = $(PHD)/build
OBJ = $(PHD)/obj
SRC = $(PHD)/src
ICO = $(PHD)/icon
NAM = COOL_MinGW
DBG = $(BUILD)/Debug
RLS = $(BUILD)/Release

OBJECTS = $(SRC)/main.o $(OBJ)/_var.o $(OBJ)/_array.o $(OBJ)/_memctl.o         \
		  $(OBJ)/_queue.o $(OBJ)/_stack.o $(OBJ)/object.o $(OBJ)/objects.o

$(NAM).exe : $(OBJECTS)
	$(CC) -o $(DBG)/$(NAM).exe $(SRC)/$(OBJECTS)

main.o : $(SRC)/advanced/objects.h
_var.o : $(SRC)/basic/_exception.h
_array.o : $(SRC)/basic/_var.h $(SRC)/basic/_rtn.h
_memctl.o : $(SRC)/basic/_rtn.h $(SRC)/basic/_array.h
_queue.o : $(SRC)/basic/_array.h
_stack.o : $(SRC)/basic/_array.h
object.o : $(SRC)/basic/_array.h
objects.o : $(SRC)/advanced/object.h

.PHONEY : clean
clean:
	-rm -r $(SRC)/*.o
