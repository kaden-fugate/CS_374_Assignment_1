// libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// header files
#include "movie.h"
#include "linkedlist.h"

struct node * processFile(FILE *file){

    // init vars
    const unsigned int size = 257;
    char *buffer = malloc(size);

    // check file was opened
    if( !file ){ perror("Error opening file"); return NULL; }

    // skip first line while also checking file can be read from
    if( !fgets(buffer, size, file) ){ perror("Error reading file"); fclose(file); return NULL; }

    struct node *head = NULL;

    // add all lines to a linked list
    while( fgets(buffer, size, file) ){

        // load movie struct from buffer str
        struct movie *cur_movie = loadMovie(buffer);

        head = insert(head, (void *) cur_movie);        
    
    }

    // de alloc mem held for buffer
    free(buffer);

    return head;

}

// function clears the input buffer after an invalid user input
void clearInput(){ int c; while ((c = getchar()) != '\n' && c != EOF) {} }

int getUserInput(int lower_bound, int upper_bound, char *prompt){

    // init user_input as -1
    int user_input = lower_bound - 1;

    while(user_input < lower_bound || user_input > upper_bound){

        // prompt to get data from user
        printf(prompt);

        // scanf returns a boolean value as to if valid input was entered or not
        int valid = scanf("%d", &user_input);

        // if user input out of range or invalid, try again
        if( user_input < lower_bound || user_input > upper_bound ){ printf("Invalid choice. Please try again.\n\n"); }
        if( !valid ){ clearInput(); } // clear input buffer if char input

    }

    return user_input;
}

int main(int argc, char *argv[]){

    FILE *file = fopen("movies_sample_1.csv", "r"); 
    struct node *head = processFile(file);
    int user_input = 0;

    printf("\nProcessed file %s and parsed data for %d movies\n\n", argv[1], getLength(head));

    while(user_input != 4){

        user_input = getUserInput(1, 4, "1. Show movies released in the specified year\n2. Show highest rated movie for each year\n3. Show the title and year of release of all movies in a specific language\n4. Exit from the program\n\nEnter a choice from 1 to 4: ");
        struct node *list = NULL;

        // get movies by year
        if(user_input == 1){ 
            
            int user_year = getUserInput(1900, 2021, "Enter the year for which you want to see movies: ");
            list = findByYear(head, user_year);

            if(list){
                printf("\nMovies from %d: \n\n", user_year);
                printList( list, user_input );
            }
            else{ printf("\nNo data found for movies released in %d.\n\n", user_year); }

            
        }

        // get top rated movie each year
        else if(user_input == 2){

            list = topMovieEachYear(head);

            if(list){
                printf("\nTop rated from each year in data: \n\n");
                printList( list, user_input );
            }
            else{ printf("\nNo movie data found.\n\n"); }

        }

        // get movies by language
        else if(user_input == 3){

            // get users desired language
            char *user_language = malloc(sizeof(char) * 100);
            printf("Enter the language for which you want to see movies: ");
            scanf("%s", user_language);

            list = findByLanguage(head, user_language);

            if(list){ 
                printf("\nMovies in %s: \n\n", user_language);
                printList( list, user_input ); 
            }
            else{ printf("\nNo data found for movies released in %s.\n\n", user_language); }

            free(user_language);

        }

        freeList(list);
    }

    freeList(head);

    fclose(file);

    return 0;
}