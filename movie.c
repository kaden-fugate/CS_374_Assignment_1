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

void printMovie(struct movie *cur_movie){

    printf("Title: %s\n", cur_movie->title);
    printf("Year: %d\n", cur_movie->year);
    for(int i = 0; i < cur_movie->num_languages; i++){ 
        printf("Language %d: %s\n", i + 1, cur_movie->languages[i]); 
    }
    printf("Rating: %lf\n\n", cur_movie->rating);

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
    char *new_str = malloc(str_len + 1);
    for(int i = 0; i < str_len; i++){ new_str[i] = languages_str_format[i + 1]; }

    // find number of languages
    int num_languages = 1;
    for(int i = 0; i < str_len; i++){ if(new_str[i] == ';'){ num_languages++; } }
    
    return createMovie(title, year, new_str, num_languages, rating);

}