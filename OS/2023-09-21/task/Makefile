CC=gcc
CFLAGS:=-fPIC
PROGS = task.exe

all: $(PROGS)

build: task.o libpushkin.so
	$(CC) -o  task.exe task.o -L. -lpushkin -Wl,-rpath,'.'
libpushkin.so: pushkin.o
	$(CC) -shared -o libpushkin.so pushkin.o
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -vf task.exe *.o
