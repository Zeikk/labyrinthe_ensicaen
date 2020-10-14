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
* @version 1.0.2 - 2020-10-01
*/

/**
* @file struct_labyrinth.h
* @brief Prototypes of struct_labyrinth.c and structures
*/

#ifndef STRUCT_LABYRINTH
#define STRUCT_LABYRINTH

/** 
* dimension represents a number of lines and columns
*/
typedef struct {
    int length;
    int width;
} dimension;

/**
* @struct cell
* @brief Objet chaîne de caractères.
*/
typedef struct {
    dimension coordinates; /**< cell's coordinates */
    int value; /**< -1 if a border wall / 0 if an other wall / or others */
    char symbol; /**< # for wall / X for bonus / Y for traps / space for others */
    int containsPlayer; /**< boolean 1 if cell contains a player else 0 */
    int is_special; /**< 1 if the cell is a bonus or -1 if it's a trap else 0 */

} cell;

/**
* labyrinth's parameters
*/
typedef struct {

    dimension size; /**< labyrinth's size */
    dimension start_labyrinth; /**< entree's coordinates */
    dimension end_labyrinth; /**< end's coordinates */

} parameters_labyrinth;

/** get_labyrinth initialize labyrinth
* @param size labyrinth's dimension
* @return labyrinth intialized or NULL
*/
cell** get_labyrinth(dimension size);

#endif