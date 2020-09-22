#ifndef STRUCT_LABYRINTHE
#define STRUCT_LABYRINTHE


typedef struct {
    int value;
    char symbol;
    int containsPlayer;
} cell;

typedef struct {
    int length;
    int width;
} dimension;

cell** get_labyrinthe(dimension size);


#endif