#include <stdlib.h>
#include <stdio.h>
#include "./menu/menu.h"
#include "./player/game_mode.h"
#include "./labyrinth/struct_labyrinth.h"


int main(void) {

	int choice = 0;
	int win = 0;
	cell **labyrinth = NULL;
	parameters_labyrinth parameters;
	char *filename = NULL;
	char input;

	while(!win) {
		choice = display_menu(filename);
		switch(choice) {
			
			case 1:

				filename = create_labyrinth(labyrinth, parameters);
				printf("\nAppuyer pour revenir au menu\n");
				scanf("%c", &input);
				break;

			case 2:
				load_labyrinth(filename, labyrinth, parameters);
				printf("\nAppuyer pour revenir au menu\n");
				scanf("%c", &input);
				break;
				
			case 3:
				play();
				break;

			case 4:
				exit_game(labyrinth, parameters);
				break;

			default: 
				display_menu(filename);
		}
	}
	
	return EXIT_SUCCESS;
}