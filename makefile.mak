CC = gcc
CFLAGS = -Wall -g

all: program

program: main.o queue.o
	$(CC) $(CFLAGS) -o program main.o queue.o

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f *.o program

.PHONY: all clean
