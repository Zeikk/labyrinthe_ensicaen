#ifndef FILE_LABYRINTH
#define FILE_LABYRINTH

#include "./struct_labyrinth.h"

void save_labyrinth_file(char *filename, cell **labyrinth, parameters_labyrinth parameters);
parameters_labyrinth load_parameters(char *filename);
cell** load_array(char *filename, parameters_labyrinth parameters);

#endif