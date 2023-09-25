CC=gcc
LDFLAGS:=-fPIC
PROGS=task.exe
NAME=task
TYPE=

all: $(PROGS)

build: $(NAME).o libpushkin.so
	$(CC) -o  $(NAME).exe $(NAME).o -L. -lpushkin -Wl,-rpath,'.'
libpushkin.so: pushkin.o
	$(CC) -shared -o libpushkin.so pushkin.o
%.o:%.c
	$(CC) $(LDFLAGS) $(TYPE) -c $< -o $@
noshared: TYPE = -DNO_SHARED
noshared: $(NAME).o
	$(CC) -o $(NAME).exe $(NAME).o $(TYPE)
run: $(NAME).exe
	./$(NAME).exe
clean:
	rm -vf $(NAME).exe *.o *.so
