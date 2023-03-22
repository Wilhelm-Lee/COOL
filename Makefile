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

DBIN = build/Debug/$(NAM).exe
RBIN = build/Release/$(NAM).exe

all : $(DBIN)

$(DBIN) : $(OBJECTS)
	$(CC) $(FLAG) -O $(OBJECTS) -o $(DBIN)

obj/main.o : src/main.c
	$(CC) $(FLAG) -c src/main.c -o obj/main.o

obj/_var.o : src/basic/_var.c
	$(CC) $(FLAG) -c src/basic/_var.c -o obj/_var.o

obj/_array.o : src/basic/_array.c
	$(CC) $(FLAG) -c src/basic/_array.c -o obj/_array.o

obj/_memctl.o : src/basic/_memctl.c
	$(CC) $(FLAG) -c src/basic/_memctl.c -o obj/_memctl.o

obj/_queue.o : src/basic/_queue.c
	$(CC) $(FLAG) -c src/basic/_queue.c -o obj/_queue.o

obj/_stack.o : src/basic/_stack.c
	$(CC) $(FLAG) -c src/basic/_stack.c -o obj/_stack.o

obj/object.o : src/advanced/object.c
	$(CC) $(FLAG) -c src/advanced/object.c -o obj/object.o

obj/objects.o : src/advanced/objects.c
	$(CC) $(FLAG) -c src/advanced/objects.c -o obj/objects.o

.PHONY : clean
clean:
	rm -fv $(OBJECTS)
	rm -fv $(DBIN)
	rm -fv $(RBIN)
