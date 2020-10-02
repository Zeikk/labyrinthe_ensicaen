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

int move_player(char move, cell* player_cell, cell **labyrinth, cell first_cell) {

    cell* left_cell = &labyrinth[player_cell->coordinates.length][player_cell->coordinates.width - 1];
    cell* right_cell = &labyrinth[player_cell->coordinates.length][player_cell->coordinates.width + 1];
    cell* top_cell = &labyrinth[player_cell->coordinates.length - 1][player_cell->coordinates.width];
    cell* bot_cell = &labyrinth[player_cell->coordinates.length + 1][player_cell->coordinates.width];

    switch(move) {

        case 'z':
            if(top_cell->value != -1 && top_cell->value != 0) {
                top_cell->containsPlayer = 1;
            } else {
                return 0;
            }
            break;
        case 's':
            if(bot_cell->value != -1 && bot_cell->value != 0) {
                bot_cell->containsPlayer = 1;
            } else {
                return 0;
            }
            break;
        case 'q':
            if(left_cell->value != -1 && left_cell->value != 0
            && (player_cell->coordinates.length != first_cell.coordinates.length
            || player_cell->coordinates.width != first_cell.coordinates.width)) {
                left_cell->containsPlayer = 1;
            } else {
                return 0;
            }
            break;
        case 'd':
            if(right_cell->value != -1 && right_cell->value != 0) {
                right_cell->containsPlayer = 1;
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

       /* system("clear");*/
        print_labyrinth(labyrinth, parameters.size);
        move = choose_move();
        move_player(move, player_cell, labyrinth, labyrinth[parameters.start_labyrinth.length][parameters.start_labyrinth.width]);
        player_cell = get_player(labyrinth, parameters.size);

    }

    system("clear");
    print_labyrinth(labyrinth, parameters.size);
    printf("It's win \n");
    
}

