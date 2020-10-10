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

typedef struct {

    char player_name[100];
    int score;

}struct_score;

void save_score(char *filename, char *player_name, int score, int length);
int check_best_score(char *filename, int score);
void get_score(char *filename);

#endif