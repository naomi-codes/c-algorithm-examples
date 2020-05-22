/*
 * main_helpers.c
 *
 *  Created on: 22 May 2020
 *      Author: zee
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#include <main_helpers.h>

#define BUFSIZE 4096

const char FUNCTIONS[4] = {'s', 'f', 'p', 'q'};
const int VALID_FUNCTIONS = 4;

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

char get_choice(const char *prompt)
{
	char buffer[BUFSIZE];
	int got_input = 0;
	char game_choice;

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

			if (strlen(buffer) != 1) {
				printf("\nYou must enter either one of s, p or f. ");
				printf("or q to quit.\n");
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

				if (is_number) {
					printf("\nYou must enter either one of s, p or f. ");
					printf("or q to quit.\n");
				} else {

					game_choice = buffer[0];

					bool match = false;
					for (int i = 0; i < VALID_FUNCTIONS; i++) {
						if (game_choice == FUNCTIONS[i])
							match = true;
					}

					if (match)
						got_input = 1;
				} /* from else clause of if (!is_number) */
			} /* from else clause of strlen(buffer != 1) */
		} /* from else clause of if (fgets(...) == NULL) */
	} /* from while(!got_input) */

	return game_choice;
}
