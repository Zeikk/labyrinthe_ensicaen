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
* @version 1.0.0 2020-09-26
*/

/**
* @file menu.c
* @brief Display menu
*/

#include <stdio.h>
#include <stdlib.h>
#include "./menu.h"
#include "../utils/utils.h"

int scan_menu(void) {

    int choice = -1;

    do {

        if (choice != -1) {
            printf("\nError: please enter a number between 1 and 4:\n");
        } else {
            printf("\nEnter a number (1-4): \n");
        }
        scanf("%d", &choice);
        clean_buffer();

    } while(choice <= 0 || choice >=5);

    return choice;

}

int display_menu(char *filename){

    system("clear");
    printf("\n######### Main Menu #########\n\n");

    if (filename != NULL) {
        printf("\nLoaded Labyrinth: %s \n\n", filename);
    }

    printf("1. Create labyrinth \n");
    printf("2. Load labyrinth \n");
    printf("3. Play \n");
    printf("4. Exit \n");

    return scan_menu();

}

