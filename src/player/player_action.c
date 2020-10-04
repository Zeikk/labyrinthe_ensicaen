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

int check_is_special(cell* cell_check) {

    if(cell_check->is_special == 1) {
        cell_check->is_special = 0;
        return cell_check->value;

    } else if(cell_check->is_special == -1) {
        cell_check->is_special = 0;
        return cell_check->value * -1;
    }

    return 0;
}

int move_player(char move, cell* player_cell, cell **labyrinth, cell first_cell) {

    cell* left_cell = &labyrinth[player_cell->coordinates.length][player_cell->coordinates.width - 1];
    cell* right_cell = &labyrinth[player_cell->coordinates.length][player_cell->coordinates.width + 1];
    cell* top_cell = &labyrinth[player_cell->coordinates.length - 1][player_cell->coordinates.width];
    cell* bot_cell = &labyrinth[player_cell->coordinates.length + 1][player_cell->coordinates.width];
    int cell_value = 0;

    switch(move) {

        case 'z':
            if(top_cell->value != -1 && top_cell->value != 0) {

                top_cell->containsPlayer = 1;
                cell_value = check_is_special(top_cell);

            } else {
                return 0;
            }
            break;
        case 's':
            if(bot_cell->value != -1 && bot_cell->value != 0) {

                bot_cell->containsPlayer = 1;
                cell_value = check_is_special(bot_cell);

            } else {
                return 0;
            }
            break;
        case 'q':
            if(left_cell->value != -1 && left_cell->value != 0
            && (player_cell->coordinates.length != first_cell.coordinates.length
            || player_cell->coordinates.width != first_cell.coordinates.width)) {

                left_cell->containsPlayer = 1;
                cell_value = check_is_special(left_cell);

            } else {
                return 0;
            }
            break;
        case 'd':
            if(right_cell->value != -1 && right_cell->value != 0) {

                right_cell->containsPlayer = 1;
                cell_value = check_is_special(right_cell);

            } else {
                return 0;
            }
            break;
        default:
            return 0;
    }

    player_cell->containsPlayer = 0;
    return cell_value;
}

int move(cell **labyrinth, parameters_labyrinth parameters) {

    char move;
    cell* player_cell;
    int score = 0;

    if(labyrinth == NULL ) {
        perror("Labyrinth empty");
        return 0;
    }

    player_cell = get_player(labyrinth, parameters.size);
    while(is_win(*player_cell, parameters) == 0) {

        system("clear");
        print_labyrinth(labyrinth, parameters.size);
        printf("Score: %d \n", score);
        move = choose_move();

        score += move_player(move, player_cell, labyrinth, labyrinth[parameters.start_labyrinth.length][parameters.start_labyrinth.width]);
        score--;
        player_cell = get_player(labyrinth, parameters.size);

    }

    system("clear");
    print_labyrinth(labyrinth, parameters.size);
    printf("It's win. Score: %d\n", score);
    return score;
}

