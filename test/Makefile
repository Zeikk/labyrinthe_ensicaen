CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
EXEC = main_test
CPPFLAGS =  -I ../includes

SRC_LABYRINTH = ../src/labyrinth
SRC_TEST_LABYRINTH = ./labyrinth

OBJ_LABYRINTH =  $(OBJ_DIR)/test_generator_labyrinth.o $(SRC_TEST_LABYRINTH)/test_generator_labyrinth.h\
$(OBJ_DIR)/test_struct_labyrinth.o $(SRC_TEST_LABYRINTH)/test_struct_labyrinth.h\
$(SRC_LABYRINTH)/struct_labyrinth.h $(OBJ_DIR)/struct_labyrinth.o \
$(SRC_LABYRINTH)/generator_labyrinth.h $(OBJ_DIR)/generator_labyrinth.o \
$(OBJ_DIR)/file_labyrinth.o $(SRC_LABYRINTH)/file_labyrinth.h \
$(OBJ_DIR)/print_labyrinth.o $(SRC_LABYRINTH)/print_labyrinth.h

SRC_PLAYER = ../src/player
SRC_TEST_PLAYER = ./player
OBJ_PLAYER = $(OBJ_DIR)/test_user_input.o $(SRC_TEST_PLAYER)/test_user_input.h \
$(OBJ_DIR)/user_input.o $(SRC_PLAYER)/user_input.h \
$(OBJ_DIR)/utils.o $(SRC_UTILS)/utils.h \
$(OBJ_DIR)/game_mode.o $(SRC_PLAYER)/game_mode.h \
$(OBJ_DIR)/move_player.o $(SRC_PLAYER)/move_player.h \
$(OBJ_DIR)/file_score.o $(SRC_PLAYER)/file_score.h

SRC_UTILS = ../src/utils

OBJ_DIR = ../obj
OBJ = $(OBJ_DIR)/main_test.o $(OBJ_LABYRINTH) $(OBJ_PLAYER)

BIN_DIR = ../bin

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$(EXEC)

$(OBJ_DIR)/main_test.o:	./main_test.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(OBJ_DIR)/test_struct_labyrinth.o: $(SRC_TEST_LABYRINTH)/test_struct_labyrinth.c $(SRC_TEST_LABYRINTH)/test_struct_labyrinth.h \
$(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(OBJ_DIR)/test_generator_labyrinth.o: $(SRC_TEST_LABYRINTH)/test_generator_labyrinth.c $(SRC_TEST_LABYRINTH)/test_generator_labyrinth.h \
$(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.c $(SRC_LABYRINTH)/generator_labyrinth.h \
$(SRC_LABYRINTH)/generator_labyrinth.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(OBJ_DIR)/test_user_input.o: $(SRC_TEST_PLAYER)/test_user_input.c $(SRC_TEST_PLAYER)/test_user_input.h \
$(SRC_PLAYER)/user_input.c $(SRC_PLAYER)/user_input.h $(SRC_UTILS)/utils.h $(SRC_UTILS)/utils.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@
