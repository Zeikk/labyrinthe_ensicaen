#include <stdlib.h>
#include <stdio.h>
#include "./game_mode.h"
#include "../labyrinth/generator_labyrinth.h"
#include "../labyrinth/print_labyrinth.h"
#include "../labyrinth/struct_labyrinth.h"
#include "../labyrinth/file_labyrinth.h"
#include "./user_input.h"


char* create_labyrinth(cell **labyrinth, parameters_labyrinth parameters) {

	char* filename;

	parameters.size = choose_dimension();
	filename = choose_labyrinth_name(0);

    if(labyrinth == NULL ) {
    	labyrinth = get_labyrinth(parameters.size);
	}

    parameters.start_labyrinth.length = 1;
	parameters.start_labyrinth.width = 0;

	parameters.end_labyrinth.length = parameters.size.length-2;
	parameters.end_labyrinth.width = parameters.size.width-1;

	if(labyrinth == NULL) {
        perror("Error labyrinth's creation");
		return NULL;
	}

	generate_labyrinth(labyrinth, parameters);
	print_labyrinth(labyrinth, parameters.size);
	save_labyrinth_file(filename, labyrinth, parameters);

	return filename;
}

void load_labyrinth(char *filename, cell **labyrinth, parameters_labyrinth parameters) {


	do {

		filename = choose_labyrinth_name(1);
		parameters = load_parameters(filename);
		labyrinth = load_array(filename, parameters);

	}while(labyrinth == NULL);

	print_labyrinth(labyrinth, parameters.size);
}

void play() {

}

void exit_game(cell **labyrinth, parameters_labyrinth parameters) {

	if(labyrinth != NULL ) {
		free_labyrinth(labyrinth, parameters.size);
	}
	exit(0);
}