#include <stdlib.h>
#include <stdio.h>
#include "./game_mode.h"
#include "../labyrinth/generator_labyrinth.h"
#include "../labyrinth/print_labyrinth.h"
#include "../labyrinth/struct_labyrinth.h"
#include "../labyrinth/file_labyrinth.h"
#include "./user_input.h"


char* create_labyrinth() {

	parameters_labyrinth parameters;
	cell  **labyrinth;
	char* filename;

	parameters.size = choose_dimension();
	filename = choose_labyrinth_name();

	
    parameters.start_labyrinth.length = 1;
	parameters.start_labyrinth.width = 0;

	parameters.end_labyrinth.length = parameters.size.length-2;
	parameters.end_labyrinth.width = parameters.size.width-1;

    labyrinth = get_labyrinth(parameters.size);
	if(labyrinth == NULL) {
        perror("Error labyrinth's creation");
		return NULL;
	}

	generate_labyrinth(labyrinth, parameters);
	save_labyrinth_file(filename, labyrinth, parameters);
	/*free_labyrinth(labyrinth, parameters.size);*/

	return filename;
}

void load_labyrinth(char *filename, cell **labyrinth, parameters_labyrinth parameters) {

	if(filename == NULL) {
		filename = choose_labyrinth_name();
	}

	parameters = load_parameters(filename);
	labyrinth = load_array(filename, parameters);

	print_labyrinth(labyrinth, parameters.size);

}

void play() {

}

void exit_game() {
	exit(0);
}