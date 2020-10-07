#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./generator_labyrinth.h"
#include "./struct_labyrinth.h"

#define VALUE_SPECIAL_CELL 1

int verif_labyrinth(cell **labyrinth, dimension size) {
	
	/* first case */
	int first_number = labyrinth[1][1].value;
	int i;
	int j;

	/* test if labyrinth is only filled with 0 / -1 or first case's number */
	for(i = 0; i<size.length; i++) {

		for(j = 0; j<size.width; j++) {
			
			if(labyrinth[i][j].value != first_number && labyrinth[i][j].value != -1 && labyrinth[i][j].value != 0) {
				return 0;
			}
		}
	}

	return 1;	
}

/* replace cell labyrinth[x][y] by value
 * and search if other case can by replace
 */
void replace_cell(cell **labyrinth, dimension size, int new_value, int old_value) {
	
	int i;
	int j;
	for(i = 0; i<size.length; i++) {
		for(j = 0; j<size.width; j++) {
			if(labyrinth[i][j].value == old_value) {
				labyrinth[i][j].value = new_value;
			}
		}
	}
}

void generate_special_cell(cell **labyrinth, dimension size) {

	int nb_created_cell = 0;
	int nb_cell = size.length * size.width / 10;
	int rand_col;
	int rand_line;
	int is_bonus;

	while(nb_created_cell != nb_cell) {

		is_bonus = rand() % 2;
		rand_line = (rand() % (size.length-2)) +1;
		rand_col = (rand() % (size.width-2)) +1;

		if(labyrinth[rand_line][rand_col].value != 0 && labyrinth[rand_line][rand_col].value != -1
		&& labyrinth[rand_line+1][rand_col].is_special == 0 && labyrinth[rand_line-1][rand_col].is_special == 0
		&& labyrinth[rand_line][rand_col+1].is_special == 0 && labyrinth[rand_line][rand_col-1].is_special == 0) {
			labyrinth[rand_line][rand_col].value = VALUE_SPECIAL_CELL;
			is_bonus ? (labyrinth[rand_line][rand_col].is_special = 1) : (labyrinth[rand_line][rand_col].is_special = -1);
			nb_created_cell++;
		}

	}
}

void generate_labyrinth(cell **labyrinth, parameters_labyrinth parameters) {
	
	int i;
	int j;
	int opening = 1; 
	
	int rand_line;
	int rand_col;
	dimension size = parameters.size;
	
	srand(time(NULL));
	/* fill labyrinth
	 * 0 = wall inside the labyrinth
	 * -1 = border of labyrinth
	 * opening = first way
	 */

	for(i = 0; i<size.length; i++) {

		for(j = 0; j<size.width; j++) {
			if(j == 0 || i == 0 || i == size.length-1 || j == size.width-1) {
				labyrinth[i][j].value = -1;

			} else if(i % 2 != 0 && j % 2 != 0) {
				
				labyrinth[i][j].value = opening;
				opening++;

			} else {
				
				labyrinth[i][j].value = 0;
			}
			labyrinth[i][j].containsPlayer = 0;
			labyrinth[i][j].is_special = 0;
			labyrinth[i][j].coordinates.length = i;
			labyrinth[i][j].coordinates.width = j;

		}
	}
	
	/* create random way */
	
	while(!verif_labyrinth(labyrinth, size)) {
		
		rand_line = (rand() % (size.length-2)) +1;
		rand_col = (rand() % (size.width-2)) +1;

		if(labyrinth[rand_line][rand_col].value == 0) {
			
			/* all cells around the random wall */
			int *top_cell = &labyrinth[rand_line-1][rand_col].value;
			int *bot_cell = &labyrinth[rand_line+1][rand_col].value;
			int *left_cell = &labyrinth[rand_line][rand_col-1].value;
			int *right_cell = &labyrinth[rand_line][rand_col+1].value;

			/* if it's possible to create a vertical way */
			if(*top_cell != *bot_cell && *top_cell > 0 && *bot_cell > 0) {
				labyrinth[rand_line][rand_col].value = *top_cell;
				replace_cell(labyrinth, size, *top_cell, *bot_cell);
			}
			
			/* if it's possible to create an horizontal way */
			if(*left_cell != *right_cell && *left_cell > 0 && *right_cell > 0) {
				labyrinth[rand_line][rand_col].value = *left_cell;
				replace_cell(labyrinth, size, *left_cell, *right_cell);
			}
		}
	}

	generate_special_cell(labyrinth, size);

	/* create start and end*/
	labyrinth[parameters.start_labyrinth.length][parameters.start_labyrinth.width].value = 1;
	labyrinth[parameters.start_labyrinth.length][parameters.start_labyrinth.width].containsPlayer = 1;
	labyrinth[parameters.end_labyrinth.length][parameters.end_labyrinth.width].value = 1;

}