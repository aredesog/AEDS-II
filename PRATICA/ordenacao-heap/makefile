CC = gcc
CFLAGS = -Wall -Wextra -g

OBJ = main.o heap.o

all: programa

programa: $(OBJ)
	$(CC) $(CFLAGS) -o programa $(OBJ)

main.o: main.c heap.h
	$(CC) $(CFLAGS) -c main.c

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

run: programa
	./programa

clean:
	rm -f *.o programa
