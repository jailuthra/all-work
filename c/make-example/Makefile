# Defining C Compiler as gcc
CC=gcc
# Defining the gcc flags to compile to object file
CFLAGS=-Wall -c

all: hello

hello: hello_fn.o main.o
	$(CC) hello_fn.o main.o -o hello

hello_fn.o: hello_fn.c hello.h
	$(CC) $(CFLAGS) hello_fn.c

main.o: main.c hello.h
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o hello
