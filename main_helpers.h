/*
 *
 * File:   main_helpers.h
 * Author: naomi lambert
 *
 */

#ifndef MAIN_HELPERS_H
#define MAIN_HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * get_choice:  Reads in the game choice for the user to select which function to
 * 				demonstrate
 *
 * Parameters:
 *       prompt  -  A string prompt presented to the user.
 *
 * Returns:
 *       -1    -  if the user entered q
 *       1..3  -  if the user entered 1 2 or 3
 *
 */

int get_choice(const char *prompt);

#include<stdbool.h>
#ifdef __cplusplus
}
#endif

#endif /* PYRAMID_HELPERS_H */
