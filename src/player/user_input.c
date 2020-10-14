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
* @author Loïcl LEPRÉVOST <loick.leprevost@ecole.ensicaen.fr>
* @version 2.0.1 2020-10-09
*/

/**
* @file user_input.c
* @brief display message and scan user's response
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "./user_input.h"
#include "../labyrinth/struct_labyrinth.h"
#include "../utils/utils.h"

dimension choose_dimension(void) {

    dimension size;
    
    system("clear");
    printf("######### Choice of dimension #########\n\n");

    do {
        printf("Enter an odd length (5-45): \n");
        scanf("%d", &size.length);
        clean_buffer();
    } while(size.length < 5 || size.length > 45 || size.length % 2 == 0);

    do {
        printf("Enter an odd width (5-45): \n");
        scanf("%d", &size.width);
        clean_buffer();
    } while(size.width < 5 || size.width > 45 || size.width % 2 == 0);

    return size;
}

void display_save_directory(void) {

    struct dirent *dir;
    
    DIR *save_directory = opendir("./saves"); 
    char *extension;
    char *filename;
    int i;
    int length_extension;
    int length_filename;

    if (save_directory) {
        printf("Labyrinths list: \n");

        while ((dir = readdir(save_directory)) != NULL) {

            extension = strrchr(dir->d_name, '.');
            if (strcmp(dir->d_name, "." ) != 0 && strcmp(dir->d_name, "..") != 0 && strcmp(extension, ".score") != 0) {
                
                /* delete extension */
                filename = dir->d_name;
                length_filename = strlen(filename);
                length_extension = strlen(extension);
                for (i = 0; i<= length_extension; i++) {
                    filename[length_filename - i] = 0;
                }
                printf("- %s\n", filename);
            }
        }
        closedir(save_directory);
    }
    printf("\n");
}

void handle_error(char *name) {

    int i;
    int j;
    char wrong_chars[] = {'.', '/'};

    for (i = 0; i<(int)strlen(name); i++) {
        for (j = 0; j<(int)strlen(wrong_chars); j++) {
            if (name[i] == wrong_chars[j]) {
                name[i] = '_';
            }
        }
    }
}

char* choose_labyrinth_name(int mode) {

    char tmp_labyrinth_name[200] = {'\0'};
    char* labyrinth_name;
    int size_name;

    system("clear");
    printf("######### Choice of labyrinth's name #########\n\n");

    if (mode) {
        display_save_directory();
    }

    do {

        printf("Enter a labyrinth's name (without extension): \n");
        scanf("%[^\n]", tmp_labyrinth_name);
        clean_buffer();
    } while(tmp_labyrinth_name[0] == '\0');

    size_name = strlen(tmp_labyrinth_name) + 1;
    labyrinth_name = (char*)malloc(size_name * sizeof(char));

    strcpy(labyrinth_name, tmp_labyrinth_name);
    handle_error(labyrinth_name);

    return labyrinth_name;
}

char* choose_player_name(void) {

    char tmp_player_name[100] = {'\0'};
    char* player_name;
    int size_name;

    system("clear");
    printf("######### Choice of player's name #########\n\n");

    do {
        printf("Enter your player's name: \n");
        scanf("%[^\n]", tmp_player_name);
        clean_buffer();
    } while(tmp_player_name[0] == '\0');


    size_name = strlen(tmp_player_name) + 1;
    player_name = (char*)malloc(size_name * sizeof(char));

    strcpy(player_name, tmp_player_name);
    handle_error(player_name);

    return player_name;
}

char choose_move(void) {

    char move;

    printf("\n######### Choice of movement #########\n\n");

    do {
        printf("Enter a movement (z/q/s/d): \n");
        scanf("%c", &move);
        clean_buffer();
    } while(move != 'z' && move != 'q' && move != 's' && move != 'd');
    
    return move;
}