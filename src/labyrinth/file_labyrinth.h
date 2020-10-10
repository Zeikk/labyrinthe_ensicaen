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
* @author Loïck LEPRÉVOST <loick.leprevost@ecole.ensicaen.fr>
* @version 1.0.1 - 2020-10-01
*/

/**
* @file file_labyrinth.h
* @brief All prototypes of file_labyrinth.c.
*/

#ifndef FILE_LABYRINTH
#define FILE_LABYRINTH

#include "./struct_labyrinth.h"

void save_labyrinth_file(char *filename, cell **labyrinth, parameters_labyrinth parameters);
parameters_labyrinth load_parameters(char *filename);
cell** load_array(char *filename, parameters_labyrinth parameters);

#endif