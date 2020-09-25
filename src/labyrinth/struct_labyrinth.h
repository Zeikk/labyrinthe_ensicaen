#ifndef STRUCT_LABYRINTH
#define STRUCT_LABYRINTH


typedef struct {
    int value;
    char symbol;
    int containsPlayer;
} cell;

typedef struct {
    int length;
    int width;
} dimension;

typedef struct {
    dimension size;
    dimension start_labyrinth;
    dimension end_labyrinth;
} parameters_labyrinth;

cell** get_labyrinth(dimension size);
void free_labyrinth(cell **labyrinth, dimension size);

#endif