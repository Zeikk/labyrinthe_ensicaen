#include "file_score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *init_file_score(char *filename, int read_file) {

    FILE *file;
    char directory[] = {"./saves/"};
    char extension[] = {".score"};
    char* save_directory = (char*)malloc(strlen(filename) + 1 + strlen(directory) + 1 + strlen(extension) + 1) ;
    if(save_directory == NULL) {
        perror("Error allocation");
        return NULL;

    }
    strcpy(save_directory, directory);
    strcat(save_directory, filename);
    strcat(save_directory, extension);

    if(read_file) {

        file = fopen(save_directory, "rb");
        if(file == NULL) {
            free(save_directory);
            return NULL;
        }
    } else {

        file = fopen(save_directory, "r+b");
        if(file == NULL) {

            file = fopen(save_directory, "ab");
            if(file == NULL) {
                free(save_directory);
                return NULL;
            }
        }
    }

    free(save_directory);
    
    return file;
}

void save_score(char *filename, char *player_name, int score, int position) {

    FILE *file;
    struct_score file_score;
    struct_score* all_files;
    int i;
    int length;

    strcpy(file_score.player_name, player_name);
    file_score.score = score;

    file = init_file_score(filename, 0);
    if(file == NULL) {
        return;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file) / sizeof(struct_score);

    all_files = (struct_score*)malloc(sizeof(struct_score) * (length-position));

    /* read old scores */
    fseek(file, sizeof(struct_score) * position, SEEK_SET);

    for(i = 0; i<length-position; i++) {

         if(fread(&all_files[i], sizeof(struct_score), 1, file) != 1) {
            perror("Cannot read struct_score in file");
            fclose(file);
            return;
        }
    }
    
    fseek(file, sizeof(struct_score) * position, SEEK_SET);
    if(fwrite(&file_score, sizeof(struct_score), 1, file) != 1) {
        perror("Cannot write struct_score in file");
        fclose(file);
        return;
    }

    /* write old scores */
    for(i = 0; i<length-position && position+i+1<10; i++) {

        if(fwrite(&all_files[i], sizeof(struct_score), 1, file) != 1) {
            perror("Cannot write struct_score in file");
            fclose(file);
            return;
        }
    }

    printf("Score sauvegardé \n\n");
    fclose(file);
}

int check_best_score(char *filename, int score) {

    FILE *file;
    struct_score file_score;
    int length;
    int i;

    file = init_file_score(filename, 1);
    if(file == NULL) {
        return 0;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file) / sizeof(struct_score);

    fseek(file, 0, SEEK_SET);

    for(i = 0; i<length; i++) {
        if(fread(&file_score, sizeof(struct_score), 1, file) != 1) {
            perror("Cannot read struct_score in file");
            fclose(file);
            return -1;
        }

        if(file_score.score > score) {
            fclose(file);
            return i;
        }
    }
    
    if(length < 10) {
        fclose(file);
        return length;
    }

    return -1;
    fclose(file);
}

void get_score(char *filename) {

    FILE *file;
    struct_score file_score;
    int length;
    int i;

    file = init_file_score(filename, 1);
    if(file == NULL) {
        return;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file) / sizeof(struct_score);

    fseek(file, 0, SEEK_SET);

    printf("Listes des scores: \n");

    for(i = 0; i<length; i++) {
        if(fread(&file_score, sizeof(struct_score), 1, file) != 1) {
            perror("Cannot read struct_score in file");
            fclose(file);
            return;
        }

        printf("%d - Score: %d Player: %s\n", i+1, file_score.score, file_score.player_name);

    }
    fclose(file);
}