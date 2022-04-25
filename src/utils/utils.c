/**
* ENSICAEN
* 6 Boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* document may be reproduced, copied or revised without written
* permission of the authors.
*/

/**
* @author Loïck LEPRÉVOST <loick.leprevost@ecole.ensicaen.fr>
* @version 1.0.0 2020-09-21
*/

/**
* @file utils.c
* @brief function which can be used in differents contexts
*/

#include <stdio.h>
#include "utils.h"

/** clean_buffer allows to clean the buffer
*/
void clean_buffer(void) {

    int c;
    do {
        c = getchar();
    } while(c != '\n' && c !=  EOF);

}