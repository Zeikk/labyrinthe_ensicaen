#include "./test_generator_labyrinth.h"
#include "../../includes/minunit.h"
#include "../../src/labyrinth/struct_labyrinth.h"
#include "../../src/labyrinth/generator_labyrinth.h"


static cell **labyrinth;
static dimension size;

void test_setup(void) {

    int length = 5;
    int width = 5;
    size.length = length;
    size.width = width;

    labyrinth = get_labyrinth(size);
}

MU_TEST(test_verif_labyrinth) {

    int i;
    int j;

    /* create 5x5 labyrinth
    * -1 -1 -1 -1 -1
    * -1  1  0  1 -1
    * -1  0  0  0 -1
    * -1  1  0  1 -1
    * -1 -1 -1 -1 -1
    */
    for(i = 0; i<size.length; i++) {
        for(j = 0; j<size.width; j++) {
            if(j == 0 || i == 0 || i == size.length-1 || j == size.width-1) {
				labyrinth[i][j].value = -1;

			} else if(i % 2 != 0 && j % 2 != 0) {
				
				labyrinth[i][j].value = 1;

			} else {
				
				labyrinth[i][j].value = 0;
			}
        }
    }

    mu_assert(verif_labyrinth(labyrinth, size), "labyrinth should be completed");
}