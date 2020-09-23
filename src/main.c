#include "./labyrinth/generator_labyrinth.h"
#include "./labyrinth/print_labyrinth.h"
#include "./labyrinth/struct_labyrinth.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    
	int length = 97;
	int width = 93;

	dimension size;
	cell  **labyrinth;

	size.length = length;
	size.width = width;

    labyrinth = get_labyrinth(size);

	if(labyrinth == NULL) {
        perror("Error creation labyrinth");
		return EXIT_FAILURE;
	}

	generate_labyrinth(labyrinth, size);
	print_labyrinth(labyrinth, size);

	return EXIT_SUCCESS;
}