#ifndef MOVIE_H
#define MOVIE_H

struct movie;

int getYear(struct movie *);
char** getLanguages(struct movie *);
int getNumLanguages(struct movie *);
double getRating(struct movie *);
void printMovie(struct movie *, int);
struct movie* createMovie(char *, int, char*, int, double);
struct movie* loadMovie(char *);
void freeMovie(struct movie *);

#endif