#ifndef FILE_SCORE
#define FILE_SCORE

typedef struct {

    char player_name[100];
    int score;

} struct_score;

void save_score(char *filename, char *player_name, int score, int length);
int check_best_score(char *filename, int score);
void get_score(char *filename);

#endif