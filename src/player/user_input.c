#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

char* choose_labyrinth_name() {

    char tmp_labyrinth_name[100];
    char* labyrinth_name;
    int size_name;

    system("clear");
    printf("######### Choix du nom #########\n\n");

    printf("Saisir le nom du labyrinth: \n");
    scanf("%s", tmp_labyrinth_name);
    clean_buffer();

    size_name = strlen(tmp_labyrinth_name) + 1;
    labyrinth_name = (char*)malloc(size_name * sizeof(char));

    strcpy(labyrinth_name, tmp_labyrinth_name);

    return labyrinth_name;
}