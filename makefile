CC=gcc --std=c99 -g

all: main

main: main.c movie.o
	$(CC) main.c movie.o -o main

movie.o: movie.c movie.h
	$(CC) -c movie.c

run: main
	./main movies_sample_1.csv

clean:
	rm -f *.o main