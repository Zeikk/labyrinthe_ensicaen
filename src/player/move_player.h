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
* @version 1.0.0 2020-09-28
*/

/**
* @file move_player.h
* @brief prototypes of move_player.c
*/

#ifndef PLAYER_ACTION
#define PLAYER_ACTION

#include "../labyrinth/struct_labyrinth.h"

/** get_player allows to know where the player is
* @param labyrinth labyrinth played
* @param size labyrinth's dimension
* @return cell's ponter where the player is currently or NULL
*/
cell* get_player(cell **labyrinth, dimension size);

/** is_win tests if the player is on the last cell of the labyrinth
* @param player_cell cell where the player is
* @param parameters labyrinth's parameters
* @return 1 if the cell where the player is, is the same that the labyrinth's end cell
*/
int is_win(cell player_cell, parameters_labyrinth parameters);

/** check_is_special scans if the cell is a bonus or malus. Returns the good value and deactives the cell
* @param cell_check pointer on the scaned cell
* @return negative value if the cell is a bonus, positive value if it's a malus or zero
*/
int check_is_special(cell* cell_check);

/** move_player moves the player on the labyritnh
* @param move char describing the move choose (z/q/s/d)
* @param player_cell pointer on the cell where the player is
* @param labyrinth labyrinth played
* @param first_cell first cell of the labyrinth
* @return value of the cell where the player goes
*/
int move_player(char move, cell* player_cell, cell **labyrinth, cell first_cell);

/** move allows to play with a labyrinth
* @param labyrinth labyrinth played
* @param parameters labyrinth's parameters
* @return game's score
*/
int move(cell **labyrinth, parameters_labyrinth parameters);

#endif