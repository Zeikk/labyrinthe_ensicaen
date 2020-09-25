#include "./labyrinth/generator_labyrinth.h"
#include "./labyrinth/print_labyrinth.h"
#include "./labyrinth/struct_labyrinth.h"
#include "./menu/menu.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    
	int length = 9;
	int width = 27;
	int choice = 0;

	parameters_labyrinth parameters;
	cell  **labyrinth;

	parameters.start_labyrinth.length = 1;
	parameters.start_labyrinth.width = 0;

	parameters.end_labyrinth.length = length-2;
	parameters.end_labyrinth.width = width-1;

	parameters.size.length = length;
	parameters.size.width = width;

    labyrinth = get_labyrinth(parameters.size);

	if(labyrinth == NULL) {
        perror("Error labyrinth's creation");
		return EXIT_FAILURE;
	}


	choice = display_menu();
	switch(choice) {
		case 1: 
			generate_labyrinth(labyrinth, parameters);
			print_labyrinth(labyrinth, parameters.size);
			free_labyrinth(labyrinth, parameters.size);
			break;

		case 2:
			break;
			
		case 3:
			break;

		case 4:
			break;

		default: 
			display_menu();
	}
	
	return EXIT_SUCCESS;
}