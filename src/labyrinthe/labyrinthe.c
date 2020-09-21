#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verif_labyrinthe(int ligne, int colonne, int labyrinthe[][colonne]) {
	
	// first case
	int first_number = labyrinthe[ligne+1][colonne+1];
	int i;
	int j;
	
	/* test if labyrinthe is only filled with 0 / -1 or first case's number */
	for(i = 0; i<ligne; i++) {

		for(j = 0; j<colonne; j++) {
			
			if(labyrinthe[i][j] != first_number || labyrinthe[i][j] != -1 || labyrinthe[i][j] != 0) {
			return 0;
			}
		}
	}

	return 1;	
}

/* replace case labyrinthe[x][y] by value
 * and search if other case can by replace
 */
void replace_case(int **labyrinthe, int x, int y, int value, int old_value) {
	
	if(old_value == labyrinthe[x][y]) {
		
		labyrinthe[x][y] = value;
		replace_case(labyrinthe, x+1, y, value, old_value);	
		replace_case(labyrinthe, x-1, y, value, old_value);	
		replace_case(labyrinthe, x, y+1, value, old_value);	
		replace_case(labyrinthe, x, y-1, value, old_value);
	}
		
}

void generate_labyrinthe(char **labyrinthe, int ligne, int colonne) {
	
	int i;
	int j;
	int random_lab[ligne][colonne];
	int opening = 1; 
	
	int rand_line;
	int rand_col;

	/* fill labyrinthe
	 * 0 = wall inside the labyrinthe
	 * -1 = border of labyrinthe
	 * opening = first way
	 */

	for(i = 0; i<ligne; i++) {

		for(j = 0; j<colonne; j++) {
			
			if(j == 0 || i == 0 || i == ligne-1 || j == colonne-1) {
				
				random_lab[i][j] = -1;

			} else if(i % 2 != 0 && j % 2 != 0) {
				
				random_lab[i][j] = opening;
				opening++;

			} else {
				
				random_lab[i][j] = 0;
			}
		}
	}
	
	/* create random way */
	
	while(!verif_labyrinthe(ligne, colonne, random_lab)) {
		
		rand_line = rand() % ligne;
		rand_col = rand() % colonne;
		
		if(random_lab[rand_line][rand_col] == 0) {
			
			/* if it's possible to create a vertical way */
			 if(random_lab[rand_line-1][rand_col] != random_lab[rand_line+1][rand_col]) {
							
			}
			
			 /* if it's possible to create an horizontal way */
			 if(random_lab[rand_line][rand_col-1] != random_lab[rand_line][rand_col+1]) {

			}
		}
	}

	/* transform lab */

	for(i = 0; i<ligne; i++) {

		for(j = 0; j<colonne; j++) {
			
			if(random_lab[i][j] == -1 || random_lab[i][j] == 0) {
				
				labyrinthe[i][j] = '#';
			} else {
				sprintf(&labyrinthe[i][j], "%d", random_lab[i][j]); 
		
			}
		}
	}	
}

void afficher_lab(char **labyrinthe, int ligne, int colonne) {
	
	for(int i = 0; i<ligne; i++) {

		for(int j = 0; j<colonne; j++) {

			printf("%c ", labyrinthe[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	
	char **labyrinthe;
	int ligne = 9;
	int colonne = 23;
	int i;
	int j;

	labyrinthe = (char **)calloc(ligne, sizeof(char *));
	for(i = 0; i<ligne; i++) {
	
		labyrinthe[i] = (char *)calloc(colonne, sizeof(char));
	}
	generate_labyrinthe(labyrinthe, ligne, colonne);
	afficher_lab(labyrinthe, ligne, colonne);


	return 0;
}
