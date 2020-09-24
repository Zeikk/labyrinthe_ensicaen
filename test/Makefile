CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
EXEC = main_test
INCLUDES = ../includes/minunit.h
SRC_LABYRINTH = ../src/labyrinth
SRC_TEST_LABYRINTH = ./labyrinth
OBJ_LABYRINTH =  $(SRC_LABYRINTH)/test_generator_labyrinth.o $(SRC_LABYRINTH)/test_generator_labyrinth.h $(SRC_TEST_LABYRINTH)/test_struct_labyrinth.o $(SRC_TEST_LABYRINTH)/test_struct_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.c
OBJ = ./main.o $(INCLUDES) $(OBJ_LABYRINTH)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXEC)

main.o:	./main.c
	$(CC) $(CFLAGS) $< -c

test_struct_labyrinth.o: $(SRC_LABYRINTH)/test_struct_labyrinth.c $(SRC_LABYRINTH)/test_struct_labyrinth.h $(INCLUDES) $(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.c
	$(CC) $(CFLAGS) $< -c

test_generator_labyrinth.o: $(SRC_LABYRINTH)/test_generator_labyrinth.c $(SRC_LABYRINTH)/test_generator_labyrinth.h $(INCLUDES) $(SRC_LABYRINTH)/struct_labyrinth.h $(SRC_LABYRINTH)/struct_labyrinth.c
	$(CC) $(CFLAGS) $< -c

clean:
	rm *.o ./labyrinth/*.o
