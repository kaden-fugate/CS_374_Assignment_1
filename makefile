CC=gcc --std=c99 -g

all: movies

movies: main.c movie.o linkedlist.o
	$(CC) main.c movie.o linkedlist.o -o movies

movie.o: movie.c movie.h
	$(CC) -c movie.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) -c linkedlist.c

clean:
	rm -f *.o movies