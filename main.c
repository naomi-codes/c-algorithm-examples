/*
 * File:   main.c
 * Author: naomi lambert
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_strings.h"
#include "my_pyramid_game.h"
#include "pyramid_helpers.h"
#include "main_helpers.h"

/*
 * main: responsible for outputting and processing user choice of demo
 *
 */
int main(int argc, char** argv)
{

	const char filename[25] = "test_input.txt";

	/** Print the inroduction to the game **/
	printf("\n***** C Examples *****\nHello! This program gives a demo of some popular algorithms in C.\n");
	printf("You have 3 choices:\n");
	printf("1 - String Test - Demonstrates string manipulations\n");
	printf("2 - The Pyramid Game - Solves a pyrmaid game board of your choosing, if it is possible\n");
	printf("3 - The file input version of The Pyramid Game\n");


	/* keep the program running until the user selects exit. */
	while (true) {

		/* game choice defaults to -1 to signal nothing has been chosen. */
		int game_choice = -1;

		/* invite user to choose an example */
		printf("\nChoose an example (1, 2 or 3) or type q to quit \n");
		game_choice = get_choice("Input: ");

		switch (game_choice) {
		case 1:
			printf("\n***You asked for string routines to be tested***\n");

			/* run strings demo */
			main_strings();
			break;
		case 2:
			printf("\n***You asked for the *interactive* pyramid game!***\n");

			/* run user input pyramid game */
			main_pyramid(2);
			break;
		case 3:

			printf("\n***You asked for file_input version of the pyramid game***\n");

			/* redirect input stream to specified file */
			freopen(filename, "r", stdin);

			/* remove prompts for user input during game */
			set_quiet(true);

			/* run the file input pyramid game */
			main_pyramid(3);

			/* flush stdin and remove any end of file errors */
			fflush(stdin);
			clearerr(stdin);
			break;
		case -1:

			/** terminate all processes */
			printf("Goodbye");
			exit(EXIT_SUCCESS);
		default:
			;
		}

		/* redirect std in to terminal */
		freopen("/dev/tty", "r", stdin);
		set_quiet(false);
	}

	return (EXIT_SUCCESS);
}

