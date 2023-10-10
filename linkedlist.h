#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// only struct needed for linked list is a signle node
struct node;

// get functions
void getMinAndMaxYear(struct node *, int *, int *);
void * getMaxMovieByYear(struct node *, int);
struct node * topMovieEachYear(struct node *);
struct node * findByYear(struct node *, int);
struct node * findByLanguage(struct node *, char *);
int getLength(struct node *);

// general functions
struct node * insert(struct node *, void *);
void printList(struct node *, int);

#endif