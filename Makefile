CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
EXEC = main

SRC_MENU = ./src/menu
OBJ_MENU = $(OBJ_DIR)/menu.o $(SRC_MENU)/menu.h

SRC_UTILS = ./src/utils
OBJ_UTILS = $(OBJ_DIR)/utils.o $(SRC_UTILS)/utils.h

SRC_PLAYER = ./src/player
OBJ_PLAYER = $(OBJ_DIR)/game_mode.o $(SRC_PLAYER)/game_mode.h \
$(OBJ_DIR)/user_input.o $(SRC_PLAYER)/user_input.h \
$(OBJ_DIR)/move_player.o $(SRC_PLAYER)/move_player.h \
$(OBJ_DIR)/file_score.o $(SRC_PLAYER)/file_score.h

SRC_LABYRINTH = ./src/labyrinth
OBJ_LABYRINTH = $(OBJ_DIR)/generator_labyrinth.o \
$(SRC_LABYRINTH)/generator_labyrinth.h $(OBJ_DIR)/print_labyrinth.o \
$(SRC_LABYRINTH)/print_labyrinth.h $(OBJ_DIR)/struct_labyrinth.o \
$(SRC_LABYRINTH)/struct_labyrinth.h $(OBJ_DIR)/file_labyrinth.o \
$(SRC_LABYRINTH)/file_labyrinth.h

OBJ_DIR = ./obj
OBJ = $(OBJ_DIR)/main.o $(OBJ_LABYRINTH) $(OBJ_UTILS) $(OBJ_MENU) $(OBJ_PLAYER)

BIN_DIR = ./bin

all:
	$(MAKE) $(EXEC)
	$(MAKE) test

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$(EXEC)

$(OBJ_DIR)/main.o: ./src/main.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/generator_labyrinth.o: $(SRC_LABYRINTH)/generator_labyrinth.c $(SRC_LABYRINTH)/generator_labyrinth.h \
$(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/print_labyrinth.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/print_labyrinth.o: $(SRC_LABYRINTH)/print_labyrinth.c $(SRC_LABYRINTH)/struct_labyrinth.h \
$(SRC_LABYRINTH)/print_labyrinth.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/struct_labyrinth.o: $(SRC_LABYRINTH)/struct_labyrinth.c $(SRC_LABYRINTH)/struct_labyrinth.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/file_labyrinth.o: $(SRC_LABYRINTH)/file_labyrinth.c $(SRC_LABYRINTH)/file_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/user_input.o: $(SRC_PLAYER)/user_input.c $(SRC_PLAYER)/user_input.h $(SRC_LABYRINTH)/struct_labyrinth.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/move_player.o: $(SRC_PLAYER)/move_player.c $(SRC_PLAYER)/move_player.h $(SRC_LABYRINTH)/struct_labyrinth.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/file_score.o: $(SRC_PLAYER)/file_score.c $(SRC_PLAYER)/file_score.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/game_mode.o: $(SRC_PLAYER)/game_mode.c $(SRC_PLAYER)/game_mode.h $(SRC_LABYRINTH)/struct_labyrinth.h\
$(SRC_LABYRINTH)/generator_labyrinth.h $(SRC_LABYRINTH)/print_labyrinth.h $(SRC_PLAYER)/move_player.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/menu.o: $(SRC_MENU)/menu.c $(SRC_MENU)/menu.h $(SRC_UTILS)/utils.h
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/utils.o: $(SRC_UTILS)/utils.c $(SRC_UTILS)/utils.h
	$(CC) $(CFLAGS) $< -c -o $@

doc:
	doxygen
	firefox ./doc/html/index.html

clean:
	rm $(OBJ_DIR)/*.o 
	
clean_save:
	rm ./saves/*

clean_doc:
	rm -rf ./doc

distclean:
	rm $(BIN_DIR)/* &
	make clean &
	make clean_save &
	make clean_doc

test:
	@(cd ./test && $(MAKE))

.PHONY: all clean test doc clean_save clean_doc distclean
