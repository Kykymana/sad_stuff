CC=gcc

all:
	@echo "Usage:"
	@echo "main - just a program"
	@echo "myname - program with key"
main:
	$(CC) main.c

myname: main.c
	$(CC) -DMY_NAME="\"Student\"" main.c
clean:
	rm -vf *.o
debug:
	$(CC) -DDEBUG_MODE debug.c
nodebug: debug.c
	$(CC) debug.c
