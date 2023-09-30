#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movie.h"

struct movie{
    
    char *title;
    int year;
    char **languages;
    int num_languages;
    double rating;

};

int getYear(struct movie *cur_movie){ return cur_movie->year; }

int getNumLanguages(struct movie *cur_movie){ return cur_movie->num_languages; }

char** getLanguages(struct movie *cur_movie){ return cur_movie->languages; }

double getRating(struct movie *cur_movie){ return cur_movie->rating; }

void printMovie(struct movie *cur_movie, int user_option){

    // print statement for movie by year
    if(user_option == 1){ printf("%s\n", cur_movie->title); }

    // print statment for top movies
    if(user_option == 2){ printf("%d %.1f %s\n", cur_movie->year, cur_movie->rating, cur_movie->title); }

    if(user_option == 3){ printf("%d %s\n", cur_movie->year, cur_movie->title); }

}

struct movie* createMovie(char* title, int year, char* languages, int num_languages, double rating){

    // allocate mem for movie
    struct movie *new_movie = malloc( sizeof(struct movie) );

    // assign all non dynamic vars
    new_movie->year = year;
    new_movie->num_languages = num_languages;
    new_movie->rating = rating;
    
    // allocate mem for title and copy string to mem
    new_movie->title = malloc(strlen(title) + 1);
    strcpy(new_movie->title, title);

    // mem for languages data member
    new_movie->languages = malloc(sizeof(char *) * num_languages);
    
    char* token = strtok(languages, ";");
    for(int i = 0; token && i < num_languages; i++){ 
        // allocate mem for language, copy string into mem
        new_movie->languages[i] = malloc( (int) strlen(token) + 1 ); 
        strcpy(new_movie->languages[i], token);

        // get next token
        token = strtok(NULL, ";"); 
    }

    return new_movie;

}

struct movie* loadMovie(char *line){

    // get movie data from line of text- need to extract languages from list
    char *title = strtok(line, ",");
    int year = atoi( strtok(NULL, ",") );
    char *languages_str_format = strtok(NULL, ",");
    double rating = atof( strtok(NULL, ",") );

    int str_len = strlen(languages_str_format) - 2;

    // make new string without square brackets 
    char *new_str = malloc(sizeof(char) * (str_len + 1) );
    for(int i = 0; i < str_len; i++){ new_str[i] = languages_str_format[i + 1]; }

    // find number of languages
    int num_languages = 1;
    for(int i = 0; i < str_len; i++){ if(new_str[i] == ';'){ num_languages++; } }

    struct movie *new_movie = createMovie(title, year, new_str, num_languages, rating);

    free(new_str);
    
    return new_movie;

}

void freeMovie(struct movie *cur_movie){

    free(cur_movie->title);

    for(int i = 0; i < cur_movie->num_languages; i++){ free(cur_movie->languages[i]); }
    free(cur_movie->languages);

    free(cur_movie);
}