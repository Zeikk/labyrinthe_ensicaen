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
* @version 1.0.1 - 2020-10-03
*/

/**
* @file file_labyrinth.c
* @brief Save and load labyrinth in a file.
*/

#include "struct_labyrinth.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** init_file opens a file
* @param filename a pointer describing a filename
* @param read_file boolean, 1 if file is opened in reading else it's opened in writing
* @return a pointer on the opened file or NULL
*/
FILE *init_file(char *filename, int read_file) {

    FILE *file;
    char directory[] = {"./saves/"};
    char extension[] = {".cfg"};
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

        file = fopen(save_directory, "wb");
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

/** save_labyrinth_file saves labyrinth with its parameters in file named <filename>.cfg
* @param filename a pointer describing a filename
* @param labyrinth array containing all the cells of the labyrinth
* @param parameters labyrinth's parameters
*/
void save_labyrinth_file(char *filename, cell **labyrinth, parameters_labyrinth parameters) {

    FILE *file;
    int i;
    int j;

    file = init_file(filename, 0);
    if (file == NULL) {
        return;
    }
    
    if (fwrite(&parameters, sizeof(parameters_labyrinth), 1, file) != 1) {
        perror("Cannot write parameters in file");
        fclose(file);
        return;
    }

    for (i = 0; i<parameters.size.length; i++) {
        for (j = 0; j<parameters.size.width; j++) {

            if (fwrite(&labyrinth[i][j], sizeof(cell), 1, file) != 1) {
                perror("Cannot write cell in file");
                fclose(file);
                return;
            }
        }
    }

    printf("Labyrinthe sauvegardé: %s \n", filename);
    fclose(file);
}

/** load_parameters loads labyrinth's parameters in file named <filename>.cfg
* @param filename a pointer describing a filename
* @return loaded parameters_labyrinth or empty  parameters_labyrinth
*/
parameters_labyrinth load_parameters(char *filename) {

    FILE *file;
    parameters_labyrinth parameters;

    file = init_file(filename, 1);
    if (file == NULL) {
        return parameters;
    }

    if (fread(&parameters, sizeof(parameters_labyrinth), 1, file) != 1) {
        perror("Cannot read parameters in file");
        fclose(file);
        return parameters;
    }

    fclose(file);

    return parameters;
}
/** load_array loads labyrinth in file named <filename>.cfg
* @param filename a pointer describing a filename
* @return an array or NULL
*/

cell** load_array(char *filename, parameters_labyrinth parameters) {

    FILE *file;
    cell** labyrinth;
    int i;
    int j;

    file = init_file(filename, 1);
    if (file == NULL) {
        return NULL;
    }
    
    labyrinth = get_labyrinth(parameters.size);

    fseek(file, sizeof(parameters_labyrinth), SEEK_SET);

    for (i = 0; i<parameters.size.length; i++) {
        for (j = 0; j<parameters.size.width; j++) {

            if (fread(&labyrinth[i][j], sizeof(cell), 1, file) != 1) {
                perror("Cannot read cell in file");
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);

    return labyrinth;
}