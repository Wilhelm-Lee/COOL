CC = /bin/x86_64-w64-mingw32-cc
FLAG = -lm -std=c99 -Wall

NAM = COOL_MinGW

OBJECTS = obj/main.o \
		  obj/_var.o \
		  obj/_array.o \
		  obj/_memctl.o \
		  obj/_queue.o \
		  obj/_stack.o \
		  obj/object.o \
		  obj/objects.o

$(NAM).exe : $(OBJECTS)
	$(CC) -c build/Debug/$(NAM).exe $(OBJECTS)

obj/main.o : src/advanced/objects.h
obj/_var.o : src/basic/_exception.h
obj/_array.o : src/basic/_var.h src/basic/_rtn.h
obj/_memctl.o : src/basic/_rtn.h src/basic/_array.h
obj/_queue.o : src/basic/_array.h
obj/_stack.o : src/basic/_array.h
obj/object.o : src/basic/_array.h
obj/objects.o : src/advanced/object.h

.PHONEY : clean
clean:
	-rm -rv $(ALLOBJ)
