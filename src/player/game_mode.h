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
* @version 1.0.0 2020-09-18
*/

/**
* @file game_mode.h
* @brief prototypes of game_mode.c
*/

#ifndef GAME_MODE
#define GAME_MODE

#include "../labyrinth/struct_labyrinth.h"

cell** create_labyrinth(parameters_labyrinth *parameters, char* filename);
cell**  load_labyrinth(char *filename, parameters_labyrinth *parameters);
void play(char *filename, cell **labyrinth, parameters_labyrinth parameters);
void exit_game();

#endif