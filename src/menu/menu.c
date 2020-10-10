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
            printf("\nErreur: veuillez saisir un nombre entre 1 et 4:\n");
        } else {
            printf("\nSaisir un nombre (1-4): \n");
        }
        scanf("%1d", &choice);
        clean_buffer();

    } while(choice <= 0 || choice >=5);

    return choice;

}

int display_menu(char *filename){

    system("clear");
    printf("\n######### Menu de démarrage #########\n\n");

    if (filename != NULL) {
        printf("\nLabyrinthe chargé: %s \n\n", filename);
    }

    printf("1. Créer labyrinthe \n");
    printf("2. Charger labyrinthe \n");
    printf("3. Jouer \n");
    printf("4. Quitter \n");

    return scan_menu();

}

