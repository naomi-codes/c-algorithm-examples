/*
 * File:   main.c
 * Author: marwan
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
 *
 */
int main(int argc, char** argv)
{


	printf("\n***** C Examples *****\nHello! This program gives a demo of some popular algorithms in C.\n");
	printf("You have 3 choices:\n");
	printf("1 - String Test - Demonstrates string manipulations\n");
	printf("2 - The Pyramid Game - Solves a pyrmaid game board of your choosing, if it is possible\n");
	printf("3 - The file input version of The Pyramid Game\n");

	while (true) {
		FILE *fp, *stdf = stdin;
		int game_choice = -1;

		printf("\nChoose an example or type q to quit \n");
		game_choice = get_choice("Input: ");

		switch (game_choice) {
		case 1:
			printf("\n***You asked for string routines to be tested***\n");
			main_strings();
			break;
		case 2:
			printf("\n***You asked for the *interactive* pyramid game!***\n");
			main_pyramid();
			break;
		case 3:
			printf("\n***You asked for file_input version of the pyramid game***\n");
			fp = freopen("test_input.txt", "r", stdf);
			set_quiet(true);
			main_pyramid();
			fclose(fp);
			set_quiet(false);
			break;
		case -1:
			printf("Goodbye");
			exit(EXIT_SUCCESS);
		default:
			;
		}
	}

	return (EXIT_SUCCESS);
}

