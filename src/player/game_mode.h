#ifndef GAME_MODE
#define GAME_MODE

#include "../labyrinth/struct_labyrinth.h"

cell** create_labyrinth(parameters_labyrinth parameters, char* filename);
cell**  load_labyrinth(char *filename, parameters_labyrinth parameters);
void play(cell **labyrinth, parameters_labyrinth parameters);
void exit_game();

#endif