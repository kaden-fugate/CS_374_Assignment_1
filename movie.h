#ifndef MOVIE_H
#define MOVIE_H

// struct to hold movie
struct movie;

// get data functions
int getYear(struct movie *);
char** getLanguages(struct movie *);
int getNumLanguages(struct movie *);
double getRating(struct movie *);

// general funcs - creating, freeing, displaying struct
void printMovie(struct movie *, int);
struct movie* createMovie(char *, int, char*, int, double);
struct movie* loadMovie(char *);

#endif