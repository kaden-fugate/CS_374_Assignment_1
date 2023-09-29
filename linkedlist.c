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