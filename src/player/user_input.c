#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "./user_input.h"
#include "../labyrinth/struct_labyrinth.h"
#include "../utils/utils.h"

dimension choose_dimension() {

    dimension size;
    
    system("clear");
    printf("######### Choix des dimensions #########\n\n");

    do{
        printf("Saisir une longeur impaire: \n");
        scanf("%d", &size.length);
        clean_buffer();
    }while(size.length < 5 || size.length > 99 || size.length % 2 == 0);

    do{
        printf("Saisir une largeur impaire: \n");
        scanf("%d", &size.width);
        clean_buffer();
    }while(size.width < 5 || size.width > 99 || size.width % 2 == 0);

    return size;
}

void display_save_directory() {

    struct dirent *dir;
    
    DIR *save_directory = opendir("./saves"); 
    char *extension;

    if (save_directory) {
        printf("Liste des labyrinthes: \n");

        while ((dir = readdir(save_directory)) != NULL) {

            extension = strrchr(dir->d_name, '.');
            if(strcmp(dir->d_name, "." ) != 0 && strcmp(dir->d_name, "..") != 0 && strcmp(extension, ".score") != 0) {
                printf("- %s\n", dir->d_name);
            }
        }
        closedir(save_directory);
    }
    printf("\n");
}

void handle_error(char *filename) {

    int i;
    int j;
    char wrong_chars[] = {'.', '/'};

    for(i = 0; i<(int)strlen(filename); i++) {
        for(j = 0; j<(int)strlen(wrong_chars); j++) {
            if(filename[i] == wrong_chars[j]) {
                filename[i] = '_';
            }
        }
    }
}

char* choose_labyrinth_name(int mode) {

    char tmp_labyrinth_name[200];
    char* labyrinth_name;
    int size_name;

    system("clear");
    printf("######### Choix du nom du labyrinthe #########\n\n");

    if(mode) {
        display_save_directory();
    }

    printf("Saisir le nom du labyrinth (sans extension): \n");
    scanf("%[^\n]", tmp_labyrinth_name);
    clean_buffer();

    size_name = strlen(tmp_labyrinth_name) + 1;
    labyrinth_name = (char*)malloc(size_name * sizeof(char));

    strcpy(labyrinth_name, tmp_labyrinth_name);
    handle_error(labyrinth_name);

    return labyrinth_name;
}

char* choose_player_name() {

    char tmp_player_name[100];
    char* player_name;
    int size_name;

    system("clear");
    printf("######### Choix du nom de joueur #########\n\n");

    printf("Saisir votre nom de joueur: \n");
    scanf("%[^\n]", tmp_player_name);
    clean_buffer();

    size_name = strlen(tmp_player_name) + 1;
    player_name = (char*)malloc(size_name * sizeof(char));

    strcpy(player_name, tmp_player_name);
    handle_error(player_name);

    return player_name;
}

char choose_move() {

    char move;

    printf("\n######### Choix du mouvement #########\n\n");

    do{
        printf("Saisir le déplacement (z/q/s/d): \n");
        scanf("%c", &move);
        clean_buffer();
    }while(move != 'z' && move != 'q' && move != 's' && move != 'd');
    
    return move;
}