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

cell** get_labyrinth(dimension size);


#endif