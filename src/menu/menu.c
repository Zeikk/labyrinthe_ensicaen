#include <stdio.h>
#include "./menu.h"
#include "../utils/utils.h"

int scan_menu(void) {

    int choice = -1;

    do {

        if(choice != -1) {
            printf("\nErreur: veuillez saisir un nombre entre 1 et 4:\n");
        } else {
            printf("\nSaisir un nombre (1-4): \n");
        }
        scanf("%1d", &choice);
        clean_buffer();

    }while(choice <= 0 || choice >=5);

    return choice;

}

int display_menu(void){

    printf("\n######### Menu de démarrage #########\n\n");

    printf("1. Créer labyrinthe \n");
    printf("2. Charger labyrinthe \n");
    printf("3. Jouer \n");
    printf("4. Quitter \n");

    return scan_menu();

}

