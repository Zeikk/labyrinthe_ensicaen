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
* @version 1.0.0 2020-09-26
*/


/**
* @file menu.h
* @brief All prototypes of menu.c
*/

#ifndef MENU
#define MENU

/** scan_menu allows to select an menu option
* @return user's choice between 1 and 4
*/
int scan_menu(void);

/** display_menu displays the menu and the labyrinth loaded if filename is not NULL
* @param filename a pointer describing a filename
* @return scan_menu value
*/
int display_menu(char *filename);

#endif