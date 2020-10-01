#include "./player_action.h"
#include "./user_input.h"
#include "../labyrinth/struct_labyrinth.h"
#include "../labyrinth/print_labyrinth.h"
#include <stdlib.h>
#include <stdio.h>

cell* get_player(cell **labyrinth, dimension size) {

    int i;
    int j;
    for(i = 0; i<size.length; i++) {
        for(j = 0; j<size.width; j++) {
            if(labyrinth[i][j].containsPlayer == 1) {
                return &labyrinth[i][j];
            }
        }
    }

    return NULL;
}

int is_win(cell player_cell, parameters_labyrinth parameters) {

    return player_cell.coordinates.length == parameters.end_labyrinth.length 
    && player_cell.coordinates.width == parameters.end_labyrinth.width;
}

int move_player(char move, cell* player_cell, cell **labyrinth) {

    switch(move) {

        case 'z':
            if(labyrinth[player_cell->coordinates.length - 1][player_cell->coordinates.width].value != -1) {
                labyrinth[player_cell->coordinates.length - 1][player_cell->coordinates.width].containsPlayer = 1;
            } else {
                return 0;
            }
            break;
        case 's':
            if(labyrinth[player_cell->coordinates.length + 1][player_cell->coordinates.width].value != -1) {
                labyrinth[player_cell->coordinates.length + 1][player_cell->coordinates.width].containsPlayer = 1;
            } else {
                return 0;
            }
            break;
        case 'q':
            if(labyrinth[player_cell->coordinates.length][player_cell->coordinates.width - 1].value != -1) {
                labyrinth[player_cell->coordinates.length][player_cell->coordinates.width - 1].containsPlayer = 1;
            } else {
                return 0;
            }
            break;
        case 'd':
            if(labyrinth[player_cell->coordinates.length -1][player_cell->coordinates.width + 1].value != -1) {
                labyrinth[player_cell->coordinates.length -1][player_cell->coordinates.width + 1].containsPlayer = 1;
            } else {
                return 0;
            }
            break;
        default:
            return 0;
    }

    player_cell->containsPlayer = 0;
    return 1;
}

void move(cell **labyrinth, parameters_labyrinth parameters) {

    char move;
    cell* player_cell;

    if(labyrinth == NULL ) {
        perror("Labyrinth empty");
        return;
    }

    player_cell = get_player(labyrinth, parameters.size);
    while(is_win(*player_cell, parameters) == 0) {

        print_labyrinth(labyrinth, parameters.size);
        move = choose_move();
        move_player(move, player_cell, labyrinth);
    }

    printf("C'est gagné");
    
}

