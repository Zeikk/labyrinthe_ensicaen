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
* @version 1.0.0 2020-10-02
*/

/**
* @file file_score.h
* @brief prototypes of file_score.c
*/

#ifndef FILE_SCORE
#define FILE_SCORE

/**
* struct saves in <file.score>
*/
typedef struct {
    /**
    * @{
    */
    char player_name[100]; /**!< player name */
    int score; /**!< player score */
    /**
    * @}
    */
}struct_score;

#include <stdio.h>

/** init_file_score opens a file
* @param filename a pointer describing a filename
* @param read_file boolean, 1 if file is opened in reading else it's opened in writing
* @return a pointer on the opened file or NULL
*/
FILE *init_file_score(char *filename, int read_file);

/** save_score saves a player's score in file named <filename>.score
* @param filename a pointer describing a filename
* @param player_name a pointer describing a player name
* @param score player' score
* @param position position where the score will be inserted
*/
void save_score(char *filename, char *player_name, int score, int length);

/** check_best_score tests if the score can be inserted
* @param filename a pointer describing a filename
* @param score player's score
* @return index where the score can be inserted or -1 if the score can't be inserted
*/
int check_best_score(char *filename, int score);

/** get_score displays all the scores in <filename>.score
* @param filename a pointer describing a filename
*/
void get_score(char *filename);

#endif