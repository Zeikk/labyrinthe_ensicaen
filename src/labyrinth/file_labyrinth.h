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
#include <stdio.h>

/** init_file opens a file
* @param filename a pointer describing a filename
* @param read_file boolean, 1 if file is opened in reading else it's opened in writing
* @return a pointer on the opened file or NULL
*/
FILE *init_file(char *filename, int read_file);

/** save_labyrinth_file saves labyrinth with its parameters in file named <filename>.cfg
* @param filename a pointer describing a filename
* @param labyrinth array containing all the cells of the labyrinth
* @param parameters labyrinth's parameters
*/
void save_labyrinth_file(char *filename, cell **labyrinth, parameters_labyrinth parameters);

/** load_parameters loads labyrinth's parameters in file named <filename>.cfg
* @param filename a pointer describing a filename
* @return loaded parameters_labyrinth or empty  parameters_labyrinth
*/
parameters_labyrinth load_parameters(char *filename);

/** load_array loads labyrinth in file named <filename>.cfg
* @param filename a pointer describing a filename
* @return an array or NULL
*/
cell** load_array(char *filename, parameters_labyrinth parameters);

#endif