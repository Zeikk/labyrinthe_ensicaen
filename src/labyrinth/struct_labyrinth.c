#include <stdio.h>
#include <stdlib.h>
#include "./struct_labyrinth.h"

cell** get_labyrinth(dimension size) {

    int i;

    cell **labyrinth;

    labyrinth = (cell**)calloc(size.length, sizeof(cell*));
    if(labyrinth == NULL) {
        return NULL;
    }

    for(i = 0; i<size.length; i++) {
        
        labyrinth[i] = (cell*)calloc(size.width, sizeof(cell));
        if(labyrinth[i] == NULL) {
            return NULL;
        }
    }

    return labyrinth;
}

