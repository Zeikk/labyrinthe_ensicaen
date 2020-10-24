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
* @version 1.0.1 - 2020-10-01
*/

/**
* @file print_labyrinth.c
* @brief Display a labyrinth
*/

#include <stdio.h>
#include <stdlib.h>
#include "./print_labyrinth.h"
#include "./struct_labyrinth.h"


void format_labyrinth(cell **labyrinth, dimension size) {
	int i;
	int j;

	for (i = 0; i<size.length; i++) {
		for (j = 0; j<size.width; j++) {
			
			if ((labyrinth[i][j].value == -1 || labyrinth[i][j].value == 0) && labyrinth[i][j].is_special == 0) {
				labyrinth[i][j].symbol = '#';
			} else if (labyrinth[i][j].contains_player) {
				labyrinth[i][j].symbol = 'o';
			} else if (labyrinth[i][j].is_special == 1) {
				labyrinth[i][j].symbol = 'X';
			} else if (labyrinth[i][j].is_special == -1) {
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
	for (i = 0; i<size.length; i++) {
		for (j = 0; j<size.width; j++) {
			printf("%c ", labyrinth[i][j].symbol);
		}
		printf("\n");
	}
}