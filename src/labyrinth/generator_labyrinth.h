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
* @file generator_labyrinth.h
* @brief All prototypes of generator_labyrinth.c
*/

#ifndef GENERATOR_labyrinth
#define GENERATOR_labyrinth

#include "./struct_labyrinth.h"

/** verif_labyrinth tests if labyrinth is only filled with 0 / -1 or first case's number
* @param labyrinth array containing all the cells of the labyrinth
* @param size labyrinth's dimension
* @return 1 if the labyritnh is fill else 0
*/
int verif_labyrinth(cell **labyrinth, dimension size);

/** replace_cell replaces cell labyrinth[x][y] by value and search if other case can by replace
* @param labyrinth array containing all the cells of the labyrinth
* @param size labyrinth's dimension
* @param new_value value that will replace old value
* @param old_value value that will be replaced
*/
void replace_cell(cell **labyrinth, dimension size, int new_value, int old_value);

/** generate_special_cell creates randomly bonus or traps
* @param labyrinth array containing all the cells of the labyrinth
* @param size labyrinth's dimension
*/
void generate_special_cell(cell **labyrinth, dimension size);

/** fill_labyrinth inserts 0 / for wall inside the labyrinth / -1 for border of labyrinth / opening for first way
* @param labyrinth array containing all the cells of the labyrinth
* @param size labyrinth's dimension
*/
void fill_labyrinth(cell **labyrinth, dimension size);

/** generate_labyrinth creates a perfect labyrinth using Randomized Kruskal's algorithm
* @param labyrinth array containing all the cells of the labyrinth
* @param parameters_labyrinth labyrinth's parameters
*/
void generate_labyrinth(cell **labyrinth, parameters_labyrinth parameters);

#endif
