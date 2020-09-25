CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
EXEC = main

SRC_MENU = ./src/menu
OBJ_MENU = $(SRC_MENU)/menu.o $(SRC_MENU)/menu.h

SRC_UTILS = ./src/utils
OBJ_UTILS = $(SRC_UTILS)/utils.o $(SRC_UTILS)/utils.h

SRC_LABYRINTH = ./src/labyrinth
OBJ_LABYRINTH = $(SRC_LABYRINTH)/generator_labyrinth.o \
$(SRC_LABYRINTH)/generator_labyrinth.h $(SRC_LABYRINTH)/print_labyrinth.o \
$(SRC_LABYRINTH)/print_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.o \
$(SRC_LABYRINTH)/struct_labyrinth.h

OBJ = ./src/main.o $(OBJ_LABYRINTH) $(OBJ_UTILS) $(OBJ_MENU)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXEC)

main.o: ./src/main.c
	$(CC) $(CFLAGS) $< -c

generator_labyrinth.o: $(SRC_LABYRINTH)/generator_labyrinth.c $(SRC_LABYRINTH)/generator_labyrinth.h \
$(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/print_labyrinth.h
	$(CC) $(CFLAGS) $< -c

print_labyrinth.o: $(SRC_LABYRINTH)/print_labyrinth.c $(SRC_LABYRINTH)/struct_labyrinth.h \
$(SRC_LABYRINTH)/print_labyrinth.h
	$(CC) $(CFLAGS) $< -c

struct_labyrinth.o: $(SRC_LABYRINTH)/struct_labyrinth.c $(SRC_LABYRINTH)/struct_labyrinth.h
	$(CC) $(CFLAGS) $< -c

menu.o: $(SRC_MENU)/menu.o $(SRC_MENU)/menu.h $(SRC_UTILS)/utils.o $(SRC_UTILS)/utils.h
	$(CC) $(CFLAGS) $< -c

utils.o: $(SRC_UTILS)/utils.o $(SRC_UTILS)/utils.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm /src/*.o $(SRC_MENU)/*.o $(SRC_UTILS)/*.o $(SRC_LABYRINTH)/*.o ./test/*.o

test:
	@(cd ./test && $(MAKE))

clean_exec:
	rm $(EXEC) ./test/$(EXEC)_test

.PHONY: clean test clean_exec
