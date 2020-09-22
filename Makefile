CC = gcc
CFLAGS =
EXEC = main
SRC_LABYRINTHE = ./src/labyrinthe
OBJ_LABYRINTHE = $(SRC_LABYRINTHE)/generator_labyrinthe.o $(SRC_LABYRINTHE)/generator_labyrinthe.h $(SRC_LABYRINTHE)/print_labyrinthe.o $(SRC_LABYRINTHE)/print_labyrinthe.h $(SRC_LABYRINTHE)/struct_labyrinthe.o $(SRC_LABYRINTHE)/struct_labyrinthe.h
OBJ = ./src/main.o $(OBJ_LABYRINTHE)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXEC)

main.o: ./src/main.c
	$(CC) $(CFLAGS) $< -c

generator_labyrinthe.o: $(SRC_LABYRINTHE)/generator_labyrinthe.c $(SRC_LABYRINTHE)/generator_labyrinthe.h $(SRC_LABYRINTHE)/struct_labyrinthe.h $(SRC_LABYRINTHE)/print_labyrinthe.h
	$(CC) $(CFLAGS) $< -c

print_labyrinthe.o: $(SRC_LABYRINTHE)/print_labyrinthe.c $(SRC_LABYRINTHE)/struct_labyrinthe.h $(SRC_LABYRINTHE)/print_labyrinthe.h
	$(CC) $(CFLAGS) $< -c

struct_labyrinthe.o: $(SRC_LABYRINTHE)/struct_labyrinthe.c $(SRC_LABYRINTHE)/struct_labyrinthe.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm -r *.o ./src/*.o ./src/labyrinthe/*.o

.PHONY: clean
