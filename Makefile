CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
EXEC = main
SRC_LABYRINTH = ./src/labyrinth
OBJ_LABYRINTH = $(SRC_LABYRINTH)/generator_labyrinth.o $(SRC_LABYRINTH)/generator_labyrinth.h $(SRC_LABYRINTH)/print_labyrinth.o $(SRC_LABYRINTH)/print_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.o $(SRC_LABYRINTH)/struct_labyrinth.h
OBJ = ./src/main.o $(OBJ_LABYRINTH)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXEC)

main.o: ./src/main.c
	$(CC) $(CFLAGS) $< -c

generator_labyrinth.o: $(SRC_LABYRINTH)/generator_labyrinth.c $(SRC_LABYRINTH)/generator_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/print_labyrinth.h
	$(CC) $(CFLAGS) $< -c

print_labyrinth.o: $(SRC_LABYRINTH)/print_labyrinth.c $(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/print_labyrinth.h
	$(CC) $(CFLAGS) $< -c

struct_labyrinth.o: $(SRC_LABYRINTH)/struct_labyrinth.c $(SRC_LABYRINTH)/struct_labyrinth.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm *.o ./src/*.o ./src/labyrinth/*.o ./test/*.o ./test/labyrinth/*.o

test:
	@(cd ./test && $(MAKE))

clean_exec:
	rm $(EXEC) ./test/$(EXEC)_test

.PHONY: clean test clean_exec
