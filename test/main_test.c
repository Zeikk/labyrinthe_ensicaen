#include "./labyrinth/test_struct_labyrinth.h"
#include "./labyrinth/test_generator_labyrinth.h"
#include "./player/test_user_input.h"

int main(void) {
    
    /* need to be first because inputs contained system("clear") */
    test_user_input_main();
    test_struct_labyrinth_main();
    test_generator_labyrinth_main();

}