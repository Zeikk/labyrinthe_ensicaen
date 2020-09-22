#include "./labyrinthe/generator_labyrinthe.h"
#include "./labyrinthe/print_labyrinthe.h"
#include "./labyrinthe/struct_labyrinthe.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    
	dimension size = {9,23};
    cell  **labyrinthe = get_labyrinthe(size);
	if(labyrinthe == NULL) {
        perror("Erreur de création du labyrinthe");
		return EXIT_FAILURE;
	}

	generate_labyrinthe(labyrinthe, size);
	afficher_lab(labyrinthe, size);

	return EXIT_SUCCESS;
}