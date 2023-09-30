#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node;

void getMinAndMaxYear(struct node *, int *, int *);
void * getMaxMovieByYear(struct node *, int);
struct node * topMovieEachYear(struct node *);
struct node * findByYear(struct node *, int);
struct node * findByLanguage(struct node *, char *);
struct node * insert(struct node *, void *);
int getLength(struct node *);
void printList(struct node *, int);
void freeList(struct node *);

#endif