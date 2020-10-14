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

/** create_labyrinth fill the parameters with the user input and create and save a perfect labyrinth
* @param parameters pointer of parameters which contains labyrinth's parameters
* @param filename pointer describing filename
* @return created labyrinth(array of cells) or NULL
*/
cell** create_labyrinth(parameters_labyrinth *parameters, char* filename);

/** load_labyrinth opens a file named <filename.cfg> and loads labyrinth's parameters and labyrinth
* @param filename pointer describing a filename
* @param parameters labyrinth's parameters
* @return loaded labyrinth or NULL
*/
cell**  load_labyrinth(char *filename, parameters_labyrinth *parameters);

/** play allows to play with a loaded labyrinth
* @param filename a pointer describing a filename
* @param labyrinth a labyrinth loaded before. If it's not loaded so it's NULL
* @param parameters labyrinth's parameters
*/
void play(char *filename, cell **labyrinth, parameters_labyrinth parameters);

/** 
* exit_game quits propertly the program
*/
void exit_game(void);

#endif