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
* @file print_labyrinth.h
* @brief All prototypes of print_labyrinth.c
*/

#ifndef PRINT_labyrinth
#define PRINT_labyrinth
#include "./struct_labyrinth.h"

/** format_labyrinth assigns a symbol to each cell
* @param labyrinth array containing all the cells of the labyrinth
* @param size labyrinth's dimension
*/
void format_labyrinth(cell **labyrinth, dimension size);

/** print_labyrinth displays all symbol's cells
* @param labyrinth array containing all the cells of the labyrinth
* @param size labyrinth's dimension
*/
void print_labyrinth(cell **labyrinth, dimension size);

#endif
