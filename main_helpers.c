/*
 * main_helpers.c
 *
 *      Author: naomi lambert
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#include "main_helpers.h"

#define BUFSIZE 4096

const char FUNCTIONS[3] = {'1', '2', '3'};
const int VALID_FUNCTIONS = 3;

/*
 * get_pegnum:  Reads a peg number from the user, prompting them with
 *              the given prompt.
 *
 *              This function is fairly complex. No need to worry if it's
 *              difficult to understand.
 *
 *              "static" indicates that this function is only
 *              available in this file.
 *
 * Parameters:
 *       prompt  -  A string prompt presented to the user.
 *
 * Returns:
 *       -1    -  if the user entered "end"
 *       0..14 -  if the user entered a valid peg number
 *
 */

int get_choice(const char *prompt)
{
	char buffer[BUFSIZE];
	int got_input = 0;
	int game_choice = -1;;

	/* Loop until we get something valid from the user. */
	while (!got_input) {
		/* Print out the provided prompt. */
		printf("%s", prompt);

		/*
		 * This reads a line of up to BUFSIZE characters from the user.
		 * fgets returns NULL if there is an input error.
		 */
		if (fgets(buffer, BUFSIZE, stdin) == NULL) {
			fprintf(stderr, "\n");
			fprintf(stderr, "An error occurred while reading input.  "
					"Exiting program.\n");
			exit(1);
		} else {

			/* We successfully read in a line of input. */
			int start;
			int len;
			int pos;

			/* 'len' holds the length of the string in 'buffer'. */
			len = strlen(buffer);


			/*
			 * Strip off any whitespace at the end of the string, by
			 * writing 0 (the end of string character) over it.  Updates
			 * 'len' to keep it at the length of the string.
			 */
			while ((len > 0) && isspace(buffer[len - 1])) {
				len--;
				buffer[len] = 0;
			}

			for (start = 0; isspace(buffer[start]); start++) {
				/*
				 * No actions in the loop -- we just want start to be the
				 * position of the first non-whitespace character.
				 */
			}

			/*
			 * Start is now the position of the first non-whitespace
			 * character in buffer.
			 */
			if (buffer[start] == 0) {
				/* The string was all whitespace, soprompt again. */
				continue;
			}

			/* Check if they said "q". */
			if (buffer[start] == 'q')
			{
				got_input = 1;
				game_choice = -1; /* This is how we tell our caller the user
				 * said "end".
				 */
			} else {

				int is_number = 1; /* true until proven false */

				if (buffer[start] == '-') {
					pos = start + 1; /* Skip over starting '-'. */
				} else {
					pos = start; /* no minus to skip over */
				}

				for (; pos < len; pos++) {
					/*
					 * It isn't a number if it contains any
					 * non-digit characters.
					 */

					if (!isdigit(buffer[pos])) {
						is_number = 0;
					}
				}

				if (!is_number) {
					printf("\nYou must enter either one of 1, 2 or 3 ");
					printf("or enter q to quit.\n");
				} else {
					game_choice = atoi(buffer + start);

					int match = 0;
					for (int i = 1; i <= 3; i++) {
						if (game_choice == i) {
							match = 1;
						}
					}

					if (match == 1) {
						got_input = 1;
					}
				} /* from else clause of if (!is_number) */
			} /* from else clause of if (buffer[start] == 'q' */
		} /* from else clause of if (fgets(...) == NULL) */
	} /* from while(!got_input) */

	return game_choice;
}
