#include <stdlib.h>
#include <stdio.h>
#include "./menu/menu.h"
#include "./player/game_mode.h"
#include "./labyrinth/struct_labyrinth.h"


int main(void) {

	int choice = 0;
	int win = 0;
	cell **labyrinth;
	parameters_labyrinth parameters;
	char *filename = NULL;

	while(!win) {
		choice = display_menu(filename);
		switch(choice) {
			
			case 1:

				filename = create_labyrinth();
				printf("\nAppuyer pour revenir au menu\n");
				scanf("");
				break;

			case 2:

				load_labyrinth(filename, labyrinth, parameters);
				choice = display_menu(filename);
				break;
				
			case 3:
				play();
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