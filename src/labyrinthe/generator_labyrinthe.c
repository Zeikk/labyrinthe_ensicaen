#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./generator_labyrinthe.h"
#include "./struct_labyrinthe.h"

int verif_labyrinthe(cell **labyrinthe, dimension size) {
	
	// first case
	int first_number = labyrinthe[1][1].value;
	int i;
	int j;

	/* test if labyrinthe is only filled with 0 / -1 or first case's number */
	for(i = 0; i<size.length; i++) {

		for(j = 0; j<size.width; j++) {
			
			if(labyrinthe[i][j].value != first_number && labyrinthe[i][j].value != -1 && labyrinthe[i][j].value != 0) {
				return 0;
			}
		}
	}

	return 1;	
}

/* replace case labyrinthe[x][y] by value
 * and search if other case can by replace
 */
void replace_case(cell **labyrinthe, dimension size, int new_value, int old_value) {
	
	int i;
	int j;
	for(i = 0; i<size.length; i++) {
		for(j = 0; j<size.width; j++) {
			if(labyrinthe[i][j].value == old_value) {
				labyrinthe[i][j].value = new_value;
			}
		}
	}
		
}

void generate_labyrinthe(cell **labyrinthe, dimension size) {
	
	srand(time(NULL));
	int i;
	int j;
	int opening = 1; 
	
	int rand_line;
	int rand_col;

	/* fill labyrinthe
	 * 0 = wall inside the labyrinthe
	 * -1 = border of labyrinthe
	 * opening = first way
	 */

	for(i = 0; i<size.length; i++) {

		for(j = 0; j<size.width; j++) {
			if(j == 0 || i == 0 || i == size.length-1 || j == size.width-1) {
				labyrinthe[i][j].value = -1;

			} else if(i % 2 != 0 && j % 2 != 0) {
				
				labyrinthe[i][j].value = opening;
				opening++;

			} else {
				
				labyrinthe[i][j].value = 0;
			}
			labyrinthe[i][j].containsPlayer = 0;
		}
	}
	
	/* create random way */
	
	while(!verif_labyrinthe(labyrinthe, size)) {
		
		rand_line = (rand() % (size.length-2)) +1;
		rand_col = (rand() % (size.width-2)) +1;

		if(labyrinthe[rand_line][rand_col].value == 0) {
			
			int *top_wall = &labyrinthe[rand_line-1][rand_col].value;
			int *bot_wall = &labyrinthe[rand_line+1][rand_col].value;
			int *left_wall = &labyrinthe[rand_line][rand_col-1].value;
			int *right_wall = &labyrinthe[rand_line][rand_col+1].value;

			/* if it's possible to create a vertical way */
			if(*top_wall != *bot_wall && *top_wall > 0 && *bot_wall > 0) {
				labyrinthe[rand_line][rand_col].value = *top_wall;
				replace_case(labyrinthe, size, *top_wall, *bot_wall);
			}
			
			/* if it's possible to create an horizontal way */
			if(*left_wall != *right_wall && *left_wall > 0 && *right_wall > 0) {
				labyrinthe[rand_line][rand_col].value = *left_wall;
				replace_case(labyrinthe, size, *left_wall, *right_wall);
			}
		}
	}

	/* create start and end*/
	labyrinthe[1][0].value = 1;
	labyrinthe[1][0].containsPlayer = 1;
	labyrinthe[size.length-2][size.width-1].value = 1;

}