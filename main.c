// libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// header files
#include "movie.h"

int main(int argc, char *argv[]){

    // init vars
    FILE *file = fopen("movies_sample_1.csv", "r"); 
    const unsigned int size = 257;
    char *buffer = malloc(size);

    // check file was opened
    if( !file ){ perror("Error opening file"); return 1; }

    // skip first line while also checking file can be read from
    if( !fgets(buffer, size, file) ){ perror("Error reading file"); fclose(file); return 1; }

    // add all lines to a linked list
    while( fgets(buffer, size, file) ){

        // load movie struct from buffer str
        struct movie *cur_movie = loadMovie(buffer);

        printMovie(cur_movie);
    
    }

    free(buffer);
    fclose(file);

    return 0;
}