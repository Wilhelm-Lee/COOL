CC = /bin/x86_64-w64-mingw32-cc
FLAG = -lm -std=c99 -Wall

NAM = COOL_MinGW_Debug

OBJECTS = obj/main.o \
		  obj/_var.o \
		  obj/_array.o \
		  obj/_memctl.o \
		  obj/_queue.o \
		  obj/_stack.o \
		  obj/object.o \
		  obj/objects.o

$(NAM).exe : $(OBJECTS)
	$(CC) $(FLAG) -O $(OBJECTS) -o build/Debug/$(NAM).exe

obj/main.o : obj/objects.o
	$(CC) -O obj/objects.o -o obj/main.o

obj/_var.o : src/basic/_exception.h
	$(CC) -O src/basic/_exception.h -o obj/_var.o

obj/_array.o : obj/_var.o src/basic/_rtn.h
	$(CC) -O obj/_var.o src/basic/_rtn.h -o obj/_array.o

obj/_memctl.o : src/basic/_rtn.h obj/_array.o
	$(CC) -O src/basic/_rtn.h obj/_array.o -o obj/_memctl.o

obj/_queue.o : obj/_array.o
	$(CC) -O obj/_array.o -o obj/_queue.o

obj/_stack.o : obj/_array.o
	$(CC) -O obj/_array.o -o obj/_stack.o

obj/object.o : obj/_array.o
	$(CC) -O obj/_array.o -o obj/object.o

obj/objects.o : obj/_array.o
	$(CC) -O src/advanced/object.h -o obj/objects.o

## :-(

.PHONEY : clean
clean:
	-rm -rv $(OBJECTS)
