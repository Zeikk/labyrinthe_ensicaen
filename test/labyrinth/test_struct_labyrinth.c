/**
* ENSICAEN
* 6 Boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* document may be reproduced, copied or revised without written
* permission of the authors.
*/

#include "./test_struct_labyrinth.h"
#include "../../includes/minunit.h"
#include "../../src/labyrinth/struct_labyrinth.h"

static dimension size_labyrinth;
static cell **test_labyrinth;

void test_setup_struct(void) {

    int length = 3;
    int width = 3;
    size_labyrinth.length = length;
    size_labyrinth.width = width;

    test_labyrinth = get_labyrinth(size_labyrinth);
}

MU_TEST(test_struct_size) {

    dimension size;
    int length;
    int width;

    length = 3;
    width = 3;
    size.length = length;
    size.width = width;


    mu_assert(size.length == length, "size.length is not equal to length");
    mu_assert(size.width == width, "size.width is not equal to width");
}

MU_TEST(test_get_labyrinth) {
    
    cell **labyrinth;
    labyrinth = get_labyrinth(size_labyrinth);
    
    mu_assert(labyrinth != NULL, "labyrinth was not correctly created");
}

MU_TEST(test_get_labyrinth_should_fail) {
    
    cell **labyrinth_fail;
    dimension size_fail;

    size_fail.length = -1;
    labyrinth_fail = get_labyrinth(size_fail);
    
    mu_assert(labyrinth_fail == NULL, "labyrinth should not be correctly created");
}

MU_TEST_SUITE(test_suite) {
    
	MU_SUITE_CONFIGURE(&test_setup_struct, NULL);

	MU_RUN_TEST(test_struct_size);
	MU_RUN_TEST(test_get_labyrinth);
	MU_RUN_TEST(test_get_labyrinth_should_fail);

}

void test_struct_labyrinth_main(void) {

    MU_RUN_SUITE(test_suite);
	MU_REPORT();
}