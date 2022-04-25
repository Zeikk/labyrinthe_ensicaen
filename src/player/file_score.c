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
* @version 1.0.2 2020-10-10
*/

/**
* @file file_score.c
* @brief save and load score in a file
*/

#include "file_score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** init_file_score opens a file
* @param filename a pointer describing a filename
* @param read_file boolean, 1 if file is opened in reading else it's opened in writing
* @return a pointer on the opened file or NULL
*/
FILE *init_file_score(char *filename, int read_file) {

    FILE *file;
    char directory[] = {"./saves/"};
    char extension[] = {".score"};
    char* save_directory = (char*)malloc(strlen(filename) + 1 + strlen(directory) + 1 + strlen(extension) + 1) ;
    if (save_directory == NULL) {
        perror("Error allocation");
        return NULL;

    }
    strcpy(save_directory, directory);
    strcat(save_directory, filename);
    strcat(save_directory, extension);

    if (read_file) {

        file = fopen(save_directory, "rb");
        if (file == NULL) {
            free(save_directory);
            return NULL;
        }
    } else {

        file = fopen(save_directory, "r+b");
        if (file == NULL) {

            file = fopen(save_directory, "ab");
            if (file == NULL) {
                free(save_directory);
                return NULL;
            }
        }
    }

    free(save_directory);
    
    return file;
}

/** save_score saves a player's score in file named <filename>.score
* @param filename a pointer describing a filename
* @param player_name a pointer describing a player name
* @param score player' score
* @param position position where the score will be inserted
*/
void save_score(char *filename, char *player_name, int score, int position) {

    FILE *file;
    struct_score file_score;
    struct_score* all_files;
    int i;
    int length;

    strcpy(file_score.player_name, player_name);
    file_score.score = score;

    file = init_file_score(filename, 0);
    if (file == NULL) {
        return;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file) / sizeof(struct_score);

    all_files = (struct_score*)malloc(sizeof(struct_score) * (length-position));

    /* read old scores */
    fseek(file, sizeof(struct_score) * position, SEEK_SET);

    for (i = 0; i<length-position; i++) {

         if (fread(&all_files[i], sizeof(struct_score), 1, file) != 1) {
            perror("Cannot read struct_score in file");
            fclose(file);
            return;
        }
    }
    
    fseek(file, sizeof(struct_score) * position, SEEK_SET);
    if (fwrite(&file_score, sizeof(struct_score), 1, file) != 1) {
        perror("Cannot write struct_score in file");
        fclose(file);
        return;
    }

    /* write old scores except the last */
    for (i = 0; i<length-position && position+i+1<10; i++) {

        if (fwrite(&all_files[i], sizeof(struct_score), 1, file) != 1) {
            perror("Cannot write struct_score in file");
            fclose(file);
            return;
        }
    }

    printf("Score saved \n\n");
    fclose(file);
}

/** check_best_score tests if the score can be inserted
* @param filename a pointer describing a filename
* @param score player's score
* @return index where the score can be inserted or -1 if the score can't be inserted
*/
int check_best_score(char *filename, int score) {

    FILE *file;
    struct_score file_score;
    int length;
    int i;

    file = init_file_score(filename, 1);
    if (file == NULL) {
        return 0;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file) / sizeof(struct_score);

    fseek(file, 0, SEEK_SET);

    for (i = 0; i<length; i++) {
        if (fread(&file_score, sizeof(struct_score), 1, file) != 1) {
            perror("Cannot read struct_score in file");
            fclose(file);
            return -1;
        }

        if (file_score.score > score) {
            fclose(file);
            return i;
        }
    }
    
    if (length < 10) {
        fclose(file);
        return length;
    }

    return -1;
    fclose(file);
}

/** get_score displays all the scores in <filename>.score
* @param filename a pointer describing a filename
*/
void get_score(char *filename) {

    FILE *file;
    struct_score file_score;
    int length;
    int i;

    file = init_file_score(filename, 1);
    if (file == NULL) {
        return;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file) / sizeof(struct_score);

    fseek(file, 0, SEEK_SET);

    printf("Scores list: \n\n");

    for (i = 0; i<length; i++) {
        if (fread(&file_score, sizeof(struct_score), 1, file) != 1) {
            perror("Cannot read struct_score in file");
            fclose(file);
            return;
        }

        printf("%d - Player: %s Score: %d\n", i+1, file_score.player_name, file_score.score);

    }
    fclose(file);
}