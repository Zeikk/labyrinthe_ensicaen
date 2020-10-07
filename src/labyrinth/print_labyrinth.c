#include <stdio.h>
#include <stdlib.h>
#include "./print_labyrinth.h"
#include "./struct_labyrinth.h"

void format_labyrinth(cell **labyrinth, dimension size) {
	int i;
	int j;

	for(i = 0; i<size.length; i++) {
		for(j = 0; j<size.width; j++) {
			
			if((labyrinth[i][j].value == -1 || labyrinth[i][j].value == 0) && labyrinth[i][j].is_special == 0) {
				labyrinth[i][j].symbol = '#';
			} else if(labyrinth[i][j].containsPlayer) {
				labyrinth[i][j].symbol = 'o';
			} else if (labyrinth[i][j].is_special == 1){
				labyrinth[i][j].symbol = 'X';
			} else if (labyrinth[i][j].is_special == -1){
				labyrinth[i][j].symbol = 'Y';
			} else {
				labyrinth[i][j].symbol = ' ';
			}
		}
	}
}

void print_labyrinth(cell **labyrinth, dimension size) {
	
	int i;
	int j;

	format_labyrinth(labyrinth, size);
	for(i = 0; i<size.length; i++) {
		for(j = 0; j<size.width; j++) {
			printf("%c ", labyrinth[i][j].symbol);
		}
		printf("\n");
	}
}