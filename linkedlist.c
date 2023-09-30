#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "movie.h"

struct node{

    void *data;
    struct node *next;

};

void getMinAndMaxYear(struct node *head, int *min, int *max){

    struct node *temp = head;

    while(temp){

        int cur_year = getYear( (struct movie *) temp->data );

        if( cur_year < *min ){ *min = cur_year; }
        if( cur_year > *max ){ *max = cur_year; }

        temp = temp->next;
    }

}

void * getMaxMovieByYear(struct node *head, int year){

    double max_rating = 0;
    struct node *temp = head;
    void *data = NULL;

    while(temp){

        int cur_year = getYear( (struct movie *) temp->data );
        double cur_rating = getRating( (struct movie *) temp->data );

        // if current rating is greater than max rating and year matches, set new max
        if(cur_rating > max_rating && cur_year == year){ max_rating = cur_rating; data = temp->data; }

        temp = temp->next;

    }

    return data;

}

struct node * topMovieEachYear(struct node *head){

    // init list of max rated movies
    struct node *movies = NULL;

    // get range of min to max year
    int min_year = 2021;
    int max_year = 1900;
    getMinAndMaxYear(head, &min_year, &max_year);

    for(int i = max_year; i >= min_year; i--){

        // get max rated movie for year
        void *max_movie = getMaxMovieByYear(head, i);

        // if a movie was found for that year, insert in list
        if(max_movie){ movies = insert(movies, max_movie); }

    }

    return movies;

}

// return linked list of movies gathered by year, O(n)
struct node * findByYear(struct node *head, int year){

    // init vars
    struct node *new_list = NULL;
    struct node *temp = head;

    // iterate through given linked list
    while(temp){

        // if movies year matches user input year, add to new list
        if(getYear( (struct movie *) temp->data ) == year ){
            new_list = insert(new_list, temp->data);
        }

        temp = temp->next;
    }

    return new_list;

}

struct node * findByLanguage(struct node *head, char *language){

    // init vars
    struct node *new_list = NULL;
    struct node *temp = head;

    // iterate through given linked list
    while(temp){

        // init vars for current movie
        struct movie *cur_movie = temp->data;
        char **languages = getLanguages( cur_movie );

        // check if movie contains language
        for(int i = 0; i < getNumLanguages(cur_movie); i++){

            // if movie found, add to list, break loop
            if( strcmp(languages[i], language) == 0 ){ new_list = insert(new_list, temp->data); break; }
            
        }

        // move to next movie
        temp = temp->next;

    }

    return new_list;

}

// insert at beginning of LL, O(1)
struct node * insert(struct node *head, void *data){

    // create new head for linked list
    struct node *new_head = malloc( sizeof(struct node) );
    new_head->data = data;
    new_head->next = head;

    // return new_head and assign it to old head for updated LL
    return new_head;
}

// get lenth of a given linked list, O(n)
int getLength(struct node *head){
    int length = 0;
    struct node *temp = head;
    while(temp){ length++; temp = temp->next; }
    return length;
}

void printList(struct node *head, int user_option){ 

    struct node *temp = head; 

    while(temp){ 
        printMovie( (struct movie *) temp->data, user_option ); 
        temp = temp->next;  
    } 

    printf("\n");
}

void freeList(struct node *head){

    struct node *temp = NULL;

    while(head){

        temp = head;

        freeMovie( (struct movie *) head->data );
        head = head->next;
        free(temp);

    }

}