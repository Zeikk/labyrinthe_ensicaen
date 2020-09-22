#include <stdio.h>
#include <stdlib.h>
#include "./struct_labyrinthe.h"

cell** get_labyrinthe(dimension size) {

    int i;

    cell **labyrinthe;

    labyrinthe = (cell**)calloc(size.length, sizeof(cell*));
    if(labyrinthe == NULL) {
        return NULL;
    }

    for(i = 0; i<size.length; i++) {
        
        labyrinthe[i] = (cell*)calloc(size.width, sizeof(cell));
        if(labyrinthe[i] == NULL) {
            return NULL;
        }
    }

    return labyrinthe;
}

