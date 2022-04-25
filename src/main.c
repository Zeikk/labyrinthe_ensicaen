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
* @version 3.0.1 2020-10-10
*/

/**
* @file main.c
* @brief launch the program
*/

#include <stdlib.h>
#include <stdio.h>
#include "./menu/menu.h"
#include "./player/game_mode.h"
#include "./player/user_input.h"
#include "./labyrinth/struct_labyrinth.h"
#include "./utils/utils.h"


int main(void) {

	int choice = 0;
	int win = 0;
	cell **labyrinth = NULL;
	parameters_labyrinth parameters;
	char *filename = NULL;

	while (!win) {
		choice = display_menu(filename);
		switch (choice) {
			
			case 1:
				filename = choose_labyrinth_name(0);
				labyrinth = create_labyrinth(&parameters, filename);
				printf("\nPress to back to menu\n");
				clean_buffer();

				break;

			case 2:
				filename = choose_labyrinth_name(1);
				labyrinth = load_labyrinth(filename, &parameters);
				if (labyrinth == NULL) {
					filename = NULL;
				}
				
				printf("\nPress to back to menu\n");
				clean_buffer();

				break;
				
			case 3:
				if (labyrinth != NULL) {
					play(filename, labyrinth, parameters);
				} else {
					printf("Labyrinth empty \n");
				}
				
				printf("\nPress to back to menu\n");
				clean_buffer();

				if (labyrinth != NULL) {
					labyrinth = load_labyrinth(filename, &parameters);
				}
				break;

			case 4:
				exit_game();
				break;

			default: 
				display_menu(filename);
		}
	}
	
	return EXIT_SUCCESS;
}