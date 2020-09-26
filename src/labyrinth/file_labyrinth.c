#include "struct_labyrinth.h"
#include <stdio.h>
#include <string.h>

FILE *init_file(char *filename, int read_file) {

    FILE *file;
    char save_directory[] = "./saves/";

    strcat(save_directory, filename);
    strcat(save_directory, ".cfg");

    if(read_file) {

        file = fopen(save_directory, "rb");
        if(file == NULL) {
            perror("Error file");
            return NULL;
        }
    } else {

        file = fopen(save_directory, "wb");
        if(file == NULL) {

            file = fopen(save_directory, "ab");
            if(file == NULL) {
                perror("Error file");
                return NULL;
            }
        }
    }
    
    return file;
}

void save_labyrinth_file(char *filename, cell **labyrinth, parameters_labyrinth parameters) {

    FILE *file;
    int i;
    int j;

    file = init_file(filename, 0);
    if(file == NULL) {
        return;
    }
    
    if(fwrite(&parameters, sizeof(parameters_labyrinth), 1, file) != 1) {
        perror("Cannot write parameters in file");
        fclose(file);
        return;
    }

    for(i = 0; i<parameters.size.length; i++) {
        for(j = 0; j<parameters.size.width; j++) {

            if(fwrite(&labyrinth[i][j], sizeof(cell), 1, file) != 1) {
                perror("Cannot write cell in file");
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}

parameters_labyrinth load_parameters(char *filename) {

    FILE *file;
    parameters_labyrinth parameters;

    file = init_file(filename, 1);
    if(file == NULL) {
        return parameters;
    }

    if(fread(&parameters, sizeof(parameters_labyrinth), 1, file) != 1) {
        perror("Cannot read parameters in file");
        fclose(file);
        return parameters;
    }

    fclose(file);

    return parameters;
}

cell** load_array(char *filename, parameters_labyrinth parameters) {

    FILE *file;
    cell** labyrinth;
    int i;
    int j;

    file = init_file(filename, 1);
    if(file == NULL) {
        return NULL;
    }

    labyrinth = get_labyrinth(parameters.size);
    fseek(file, sizeof(parameters_labyrinth), SEEK_SET);

    for(i = 0; i<parameters.size.length; i++) {
        for(j = 0; j<parameters.size.width; j++) {

            if(fread(&labyrinth[i][j], sizeof(cell), 1, file) != 1) {
                perror("Cannot read cell in file");
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);

    return labyrinth;
}