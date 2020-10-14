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
* @version 2.0.0 2020-10-10
*/

/**
* @file game_mode.c
* @brief function to launch game modes
*/

#include <stdlib.h>
#include <stdio.h>
#include "./game_mode.h"
#include "../labyrinth/generator_labyrinth.h"
#include "../labyrinth/print_labyrinth.h"
#include "../labyrinth/struct_labyrinth.h"
#include "../labyrinth/file_labyrinth.h"
#include "./file_score.h"
#include "./user_input.h"
#include "./move_player.h"

cell** create_labyrinth(parameters_labyrinth *parameters, char* filename) {

	cell **labyrinth;

	parameters->size = choose_dimension();
    labyrinth = get_labyrinth(parameters->size);
	
    parameters->start_labyrinth.length = 1;
	parameters->start_labyrinth.width = 0;

	parameters->end_labyrinth.length = parameters->size.length-2;
	parameters->end_labyrinth.width = parameters->size.width-1;

	if (labyrinth == NULL) {
        perror("Error during labyrinth's creation");
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
	if (labyrinth == NULL) {
		printf("Labyrinth doesn't exist \n");
		return NULL;
	}

	print_labyrinth(labyrinth, parameters->size);
	return labyrinth;
}

void play(char *filename, cell **labyrinth, parameters_labyrinth parameters) {

	char *player_name;
	int score;
	int pos = 0;

	score = move(labyrinth, parameters);

	pos = check_best_score(filename, score);
	if (pos > -1) {
		player_name = choose_player_name();
		save_score(filename, player_name, score, pos);
	}

	get_score(filename);
}

void exit_game(void) {

	exit(0);
}