PROGS = simple.exe static.exe shared.exe

help:
	@echo "usage"
all: $(PROGS)

simple.exe: main.o pprint.o
	gcc -o simple.exe main.o pprint.o

%.o:%.c
	gcc -c $< -o $@
clean:
	rm -f *.o *.so *.a *.exe *~
static.exe: main.o libpprint.a
	gcc -o static.exe main.o -static -L. -lpprint

libpprint.a: pprint.o
	ar cr libpprint.a pprint.o

shared.exe: main.o libpprint.so
	gcc -o shared.exe main.o -L. -lpprint -Wl, -rpath, '.'
ifeq ($(HACK), 1)
libpprint.so: pprint.o badcode.o
	gcc -shared -fPIC -o libpprint.so pprint.o
	gcc -shared -fPIC -o libpprint.bad.so badcode.o
else
libpprint.so: pprint.o
	gcc -shared -fPIC -o libpprint.so pprint.o
load.exe: load.o
	gcc -o load.exe load.o -ldl
