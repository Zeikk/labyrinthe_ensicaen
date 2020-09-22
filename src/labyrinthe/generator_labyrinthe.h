#ifndef GENERATOR_LABYRINTHE
#define GENERATOR_LABYRINTHE

#include "./struct_labyrinthe.h"

void generate_labyrinthe(cell **labyrinthe, dimension size);
void replace_case(cell **labyrinthe, dimension size, int new_value, int old_value);
int verif_labyrinthe(cell **labyrinthe, dimension size);

#endif
