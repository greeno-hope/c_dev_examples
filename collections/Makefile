# Compiler
CC = gcc

# Delete function
RM = rm -f

# default flags (don't want many)
CFLAGS = -c -ggdb -I.

.phony: all
all: main_d

# build game.exe (release)
main_d: main.o queue.o
	$(CC) main.o queue.o -o main_d 

main_d.exe: main.o queue.o
	$(CC) main.o queue.o -o main_d.exe

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

queue.o: queue.c
	$(CC) $(CFLAGS) queue.c -o queue.o

.phony: clean
clean:
	$(RM) *.o
	$(RM) main_d


