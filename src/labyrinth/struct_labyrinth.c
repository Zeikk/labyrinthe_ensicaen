/**
* ENSICAEN
* 6 Boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* document may be reproduced, copied or revised without written
* permission of the authors.
*/

/**
* @author Loïck LEPRÉVOST<loick.leprevost@ecole.ensicaen.fr>
* @version 1.0.1 - 2020-10-01
*/

/**
* @file struct_labyrinth.c
* @brief Init a labyrinth
*/

#include <stdio.h>
#include <stdlib.h>
#include "./struct_labyrinth.h"

/** get_labyrinth initialize labyrinth
* @param size labyrinth's dimension
* @return labyrinth intialized or NULL
*/
cell** get_labyrinth(dimension size) {

    int i;

    cell **labyrinth;

    labyrinth = (cell**)calloc(size.length, sizeof(cell*));
    if (labyrinth == NULL) {
        return NULL;
    }

    for (i = 0; i<size.length; i++) {
        
        labyrinth[i] = (cell*)calloc(size.width, sizeof(cell));
        if (labyrinth[i] == NULL) {
            return NULL;
        }
    }

    return labyrinth;
}