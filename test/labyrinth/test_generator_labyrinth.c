#include "./test_generator_labyrinth.h"
#include "../../includes/minunit.h"
#include "../../src/labyrinth/struct_labyrinth.h"
#include "../../src/labyrinth/generator_labyrinth.h"


static cell **labyrinth;
static parameters_labyrinth parameters;

void test_setup_generator(void) {

    int length = 5;
    int width = 5;

	parameters.start_labyrinth.length = 1;
	parameters.start_labyrinth.width = 0;

	parameters.end_labyrinth.length = length-2;
	parameters.end_labyrinth.width = width-1;

    parameters.size.length = length;
    parameters.size.width = width;

    labyrinth = get_labyrinth(parameters.size);
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
    for(i = 0; i<parameters.size.length; i++) {
        for(j = 0; j<parameters.size.width; j++) {
            if(j == 0 || i == 0 || i == parameters.size.length-1 || j == parameters.size.width-1) {
				labyrinth[i][j].value = -1;

			} else if(i % 2 != 0 && j % 2 != 0) {
				
				labyrinth[i][j].value = 1;

			} else {
				
				labyrinth[i][j].value = 0;
			}
        }
    }

    mu_assert(verif_labyrinth(labyrinth, parameters.size), "labyrinth should be completed");
}

MU_TEST(test_verif_labyrinth_should_fail) {

    int i;
    int j;

    /* create 5x5 labyrinth
    * -1 -1 -1 -1 -1
    * -1  1  0  1 -1
    * -1  0  0  0 -1
    * -1  1  0  2 -1
    * -1 -1 -1 -1 -1
    */
    for(i = 0; i<parameters.size.length; i++) {
        for(j = 0; j<parameters.size.width; j++) {
            if(j == 0 || i == 0 || i == parameters.size.length-1 || j == parameters.size.width-1) {
				labyrinth[i][j].value = -1;

			} else if(i == 3 && j == 3) {
                
				labyrinth[i][j].value = 2;

            } else if(i % 2 != 0 && j % 2 != 0) {
				
				labyrinth[i][j].value = 1;

			}  else {
				
				labyrinth[i][j].value = 0;
			}
        }
    }

    mu_assert(!verif_labyrinth(labyrinth, parameters.size), "labyrinth should be incompleted");
}

MU_TEST(test_replace_cell) {

    int i;
    int j;

    /* create 5x5 labyrinth
    * -1 -1 -1 -1 -1
    * -1  1  0  1 -1
    * -1  0  0  0 -1
    * -1  1  0  2 -1
    * -1 -1 -1 -1 -1
    */
    for(i = 0; i<parameters.size.length; i++) {
        for(j = 0; j<parameters.size.width; j++) {
            if(j == 0 || i == 0 || i == parameters.size.length-1 || j == parameters.size.width-1) {
				labyrinth[i][j].value = -1;

			} else if(i == 3 && j == 3) {
                
				labyrinth[i][j].value = 2;

            } else if(i % 2 != 0 && j % 2 != 0) {
				
				labyrinth[i][j].value = 1;

			}  else {
				
				labyrinth[i][j].value = 0;
			}
        }
    }

    replace_cell(labyrinth, parameters.size, labyrinth[1][3].value, labyrinth[3][3].value);

    mu_assert(labyrinth[3][3].value == 1, "labyrinth[3][3].value should be replaced by 1");


}

MU_TEST(test_generate_labyrinth) {

    cell **test_labyrinth;

    test_labyrinth = get_labyrinth(parameters.size);
    generate_labyrinth(test_labyrinth, parameters);

    mu_assert(verif_labyrinth(test_labyrinth, parameters.size), "labyrinth should be completed");
    mu_assert(test_labyrinth[parameters.start_labyrinth.length][parameters.start_labyrinth.width].containsPlayer == 1, "start_labyrinth should contains player");
    mu_assert(test_labyrinth[parameters.start_labyrinth.length][parameters.start_labyrinth.width].value == 1, "start_labyrinth should be equal to 1");
    mu_assert(test_labyrinth[parameters.end_labyrinth.length][parameters.end_labyrinth.width].value == 1, "end_labyrinth should be equal to 1");
}

MU_TEST_SUITE(test_suite) {
    
	MU_SUITE_CONFIGURE(&test_setup_generator, NULL);

    MU_RUN_TEST(test_verif_labyrinth);
    MU_RUN_TEST(test_verif_labyrinth_should_fail);
    MU_RUN_TEST(test_replace_cell);
    MU_RUN_TEST(test_generate_labyrinth);

}

void test_generator_labyrinth_main(void) {

    MU_RUN_SUITE(test_suite);
	MU_REPORT();
}