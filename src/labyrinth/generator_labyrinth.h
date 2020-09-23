#ifndef GENERATOR_labyrinth
#define GENERATOR_labyrinth

#include "./struct_labyrinth.h"

void generate_labyrinth(cell **labyrinth, dimension size);
void replace_case(cell **labyrinth, dimension size, int new_value, int old_value);
int verif_labyrinth(cell **labyrinth, dimension size);

#endif
