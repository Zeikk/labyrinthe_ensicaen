#include <stdlib.h>
#include <stdio.h>
#include "./game_mode.h"
#include "../labyrinth/generator_labyrinth.h"
#include "../labyrinth/print_labyrinth.h"
#include "../labyrinth/struct_labyrinth.h"
#include "../labyrinth/file_labyrinth.h"
#include "./file_score.h"
#include "./user_input.h"
#include "./player_action.h"


cell** create_labyrinth(parameters_labyrinth *parameters, char* filename) {

	cell **labyrinth;

	parameters->size = choose_dimension();
    labyrinth = get_labyrinth(parameters->size);
	
    parameters->start_labyrinth.length = 1;
	parameters->start_labyrinth.width = 0;

	parameters->end_labyrinth.length = parameters->size.length-2;
	parameters->end_labyrinth.width = parameters->size.width-1;

	if(labyrinth == NULL) {
        perror("Error labyrinth's creation");
		return NULL;
	}

	generate_labyrinth(labyrinth, *parameters);
	save_labyrinth_file(filename, labyrinth, *parameters);
	print_labyrinth(labyrinth, parameters->size);

	return labyrinth;
}

cell** load_labyrinth(char *filename, parameters_labyrinth *parameters) {

	cell **labyrinth;

	*parameters = load_parameters(filename);
	labyrinth = load_array(filename, *parameters);
	if(labyrinth == NULL) {
		printf("Le labyrinthe n'existe pas \n");
		return NULL;
	}

	print_labyrinth(labyrinth, parameters->size);
	return labyrinth;
}

void play(char *filename, cell **labyrinth, parameters_labyrinth parameters) {

	char *player_name;
	int score;
	int length = 0;
	char input;

	score = move(labyrinth, parameters);

	length = check_best_score(filename, score);
	printf("Len check: %d \n", length);
	if(length > -1) {
		get_score(filename);
		printf("\nAppuyer pour revenir au menu\n");
		scanf("%c", &input);
		player_name = choose_player_name();
		save_score(filename, player_name, score, length);
	}
}

void exit_game() {

	exit(0);
}