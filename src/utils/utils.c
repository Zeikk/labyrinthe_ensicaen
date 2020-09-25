#include <stdio.h>

void clean_buffer(void) {

    int c;
    do {
        c = getchar();
    } while(c != '\n' && c !=  EOF);

}