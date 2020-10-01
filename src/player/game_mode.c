#include <stdlib.h>
#include <stdio.h>
#include "./game_mode.h"
#include "../labyrinth/generator_labyrinth.h"
#include "../labyrinth/print_labyrinth.h"
#include "../labyrinth/struct_labyrinth.h"
#include "../labyrinth/file_labyrinth.h"
#include "./user_input.h"
#include "./player_action.h"


cell** create_labyrinth(parameters_labyrinth parameters, char* filename) {

	cell **labyrinth;

	parameters.size = choose_dimension();
    labyrinth = get_labyrinth(parameters.size);
	
    parameters.start_labyrinth.length = 1;
	parameters.start_labyrinth.width = 0;

	parameters.end_labyrinth.length = parameters.size.length-2;
	parameters.end_labyrinth.width = parameters.size.width-1;

	if(labyrinth == NULL) {
        perror("Error labyrinth's creation");
		return NULL;
	}

	generate_labyrinth(labyrinth, parameters);
	save_labyrinth_file(filename, labyrinth, parameters);
	print_labyrinth(labyrinth, parameters.size);

	return labyrinth;
}

cell** load_labyrinth(char *filename, parameters_labyrinth parameters) {

	cell **labyrinth;
	do {

		parameters = load_parameters(filename);
		labyrinth = load_array(filename, parameters);

	}while(labyrinth == NULL);

	print_labyrinth(labyrinth, parameters.size);
	return labyrinth;
}

void play(cell **labyrinth, parameters_labyrinth parameters) {

	move(labyrinth, parameters);
}

void exit_game() {

	exit(0);
}