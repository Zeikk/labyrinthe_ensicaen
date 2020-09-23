#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./generator_labyrinth.h"
#include "./struct_labyrinth.h"

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

/* replace case labyrinth[x][y] by value
 * and search if other case can by replace
 */
void replace_case(cell **labyrinth, dimension size, int new_value, int old_value) {
	
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

void generate_labyrinth(cell **labyrinth, dimension size) {
	
	
	int i;
	int j;
	int opening = 1; 
	
	int rand_line;
	int rand_col;
	
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
		}
	}
	
	/* create random way */
	
	while(!verif_labyrinth(labyrinth, size)) {
		
		rand_line = (rand() % (size.length-2)) +1;
		rand_col = (rand() % (size.width-2)) +1;

		if(labyrinth[rand_line][rand_col].value == 0) {
			
			int *top_wall = &labyrinth[rand_line-1][rand_col].value;
			int *bot_wall = &labyrinth[rand_line+1][rand_col].value;
			int *left_wall = &labyrinth[rand_line][rand_col-1].value;
			int *right_wall = &labyrinth[rand_line][rand_col+1].value;

			/* if it's possible to create a vertical way */
			if(*top_wall != *bot_wall && *top_wall > 0 && *bot_wall > 0) {
				labyrinth[rand_line][rand_col].value = *top_wall;
				replace_case(labyrinth, size, *top_wall, *bot_wall);
			}
			
			/* if it's possible to create an horizontal way */
			if(*left_wall != *right_wall && *left_wall > 0 && *right_wall > 0) {
				labyrinth[rand_line][rand_col].value = *left_wall;
				replace_case(labyrinth, size, *left_wall, *right_wall);
			}
		}
	}

	/* create start and end*/
	labyrinth[1][0].value = 1;
	labyrinth[1][0].containsPlayer = 1;
	labyrinth[size.length-2][size.width-1].value = 1;

}