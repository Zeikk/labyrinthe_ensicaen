#include <stdio.h>
#include "./print_labyrinthe.h"
#include "./struct_labyrinthe.h"

void format_labyrinthe(cell **labyrinthe, dimension size) {
	int i;
	int j;

	for(i = 0; i<size.length; i++) {
		for(j = 0; j<size.width; j++) {
			
			if(labyrinthe[i][j].value == -1 || labyrinthe[i][j].value == 0) {
				
				labyrinthe[i][j].symbol = '#';
			} else if(labyrinthe[i][j].containsPlayer) {
				labyrinthe[i][j].symbol = 'o';
			} else {
				//sprintf(&labyrinthe[i][j].symbol, "%d", labyrinthe[i][j].value);
				labyrinthe[i][j].symbol = ' ';
			}
		}
	}
}

void afficher_lab(cell **labyrinthe, dimension size) {
	
	format_labyrinthe(labyrinthe, size);
	for(int i = 0; i<size.length; i++) {

		for(int j = 0; j<size.width; j++) {

			printf("%c ", labyrinthe[i][j].symbol);
		}
		printf("\n");
	}
}