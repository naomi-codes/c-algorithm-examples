/*
 *
 * File:   my_pyramid_game.h
 * Author: naomi lambert
 *
 */

#ifndef MY_PYRAMID_GAME_H
#define MY_PYRAMID_GAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>


/*
 *
 * solve: This is the game 'engine', in which the logic is based.
 *        It takes a board in any valid state, and determines
 *        if the game is solvable.
 *
 * Parameters:
 *        board - an integer array of size 15, with contents either 0 or 1.
 *
 * Returns:
 *        1  -  If the board is solvable;
 *        0  -  otherwise.
 */
int solve(int board[]);


/*
 * main_pyramid:  This is the entry point to the pyramid game
 *
 */

int main_pyramid(int source);


#ifdef __cplusplus
}
#endif

#endif /* MY_PYRAMID_GAME_H */

