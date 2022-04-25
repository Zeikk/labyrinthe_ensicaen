/**
* ENSICAEN
* 6 Boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* document may be reproduced, copied or revised without written
* permission of the authors.
*/

#include "./test_user_input.h"
#include "../../includes/minunit.h"
#include "../../src/labyrinth/struct_labyrinth.h"
#include "../../src/player/user_input.h"
#include "../../src/utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename_dimension[] = {"./test/player/datas/user_input_dimension.txt"};
char filename_labyrinth[] = {"./test/player/datas/user_input_labyrinth.txt"};


void test_setup_user_input(void) {

}

MU_TEST(test_choose_dimension) {

    dimension size;
    FILE* file;
    
    file = freopen(filename_dimension, "r", stdin);
    size = choose_dimension();
    fclose(file);

    mu_assert((size.length == 15 && size.width == 5), "dimension or width incorrect");
}

MU_TEST(test_choose_labyrinth_name) {

    char* filename;
    FILE* file;
    char *filename_test;
    char *all_files[3];
    int i = 0;
    int k;


    file = fopen(filename_labyrinth, "r");
    if (file == NULL) {
        mu_fail("File error");
    }
    
    filename_test = (char*)calloc(100, sizeof(char));
    while (fscanf(file, "%s", filename_test) > 0) {
        all_files[i] = (char*)calloc(strlen(filename_test)+1, sizeof(char));
        handle_error(filename_test);
        for (k = 0; k<(int)(strlen(filename_test)+1); k++) {
            all_files[i][k] = filename_test[k];
        }
        i++;

    }
    fclose(file);

    file = freopen(filename_labyrinth, "r", stdin);
    fseek(file, 0, SEEK_SET);
    for (k = 0; k<i; k++) {
        filename = choose_labyrinth_name(0);
        mu_assert(strcmp(filename, all_files[k])  == 0, "different names");
    }
    
    fclose(file);
}

MU_TEST_SUITE(test_suite) {
    

    MU_RUN_TEST(test_choose_dimension);
    MU_RUN_TEST(test_choose_labyrinth_name);


}

void test_user_input_main(void) {

    MU_RUN_SUITE(test_suite);
	MU_REPORT();
}