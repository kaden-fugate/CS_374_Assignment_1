#ifndef MOVIE_H
#define MOVIE_H

struct movie;

void printMovie(struct movie*);
struct movie* createMovie(char*, int, char*, int, double);
struct movie* loadMovie(char*);

#endif