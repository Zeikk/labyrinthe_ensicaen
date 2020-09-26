#ifndef GAME_MODE
#define GAME_MODE

#include "../labyrinth/struct_labyrinth.h"

char* create_labyrinth();
void load_labyrinth(char *filename, cell **labyrinth, parameters_labyrinth parameters);
void play();
void exit_game();

#endif