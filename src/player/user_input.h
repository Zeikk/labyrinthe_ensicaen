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
* @version 1.2.0 2020-10-01
*/

/**
* @file user_input.h
* @brief prototypes of user_input.c
*/

#ifndef USER_INPUT
#define USER_INPUT

#include "../labyrinth/struct_labyrinth.h"


/** choose_dimension returns the dimension chose by the user 
* @return labyrinth's dimension including width and length odd between 5 and 45
*/
dimension choose_dimension(void);

/** 
* display_save_directory displays all the labyrinths.cfg without extension present in the directory /saves
*/
void display_save_directory(void);

/** choose_labyrinth_name allows to enter a labyrinth's name and fix incorrects chars
* @param mode 1 if user wants to load a labyrinth and so display all existing labyrinths else 0
* @return pointer to labyrinth's name
*/
char* choose_labyrinth_name(int mode);

/** handle_error fixs the incorrect char (., /) by underscore (_)
* @param name pointer to the checked string
*/
void handle_error(char *name);

/** choose_player_name allows to enter a player's name and fix incorrects chars
* @return pointer to player's name
*/
char* choose_player_name(void);

/** choose_move allows to enter a movement
* @return movement chose (z/s/q/d)
*/
char choose_move(void);

#endif