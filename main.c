/*
 * File:   main.c
 * Author: marwan
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "my_strings.h"
#include "my_pyramid_game.h"
#include "main_helpers.h"

/*
 *
 */
int main(int argc, char** argv)
{
   /**if (argc != 2) {
      fprintf(stderr, "Usage: %s [s|p|f]\n"
                      "  where:\n "
                      "    s - executes your string test (Task 1)\n "
                      "    p - executes the *interactive* pyramid game\n "
                      "    f - executes the file-input pyramid game\n "
                      "        (Note that file must be \"text_input.txt\")\n",
              argv[0]);
      exit(EXIT_FAILURE);
   }**/

   printf("***** C Examples *****\nHello! This program gives a demo of some popular algorithms in C.\n");
   printf("You have 3 choices:\n");
   printf("1 - String Test - Demonstrates string manipulations\n");
   printf("2 - The Pyramid Game - Solves a pyrmaid game board of your choosing, if it is possible\n");
   printf("3 - The file input version of The Pyramid Game\n");

   char game_choice = get_choice("Input: ");

   switch (game_choice) {
      case 's':
         printf("You asked for string routines to be tested.\n");
         main_strings();
         break;
      case 'p':
         printf("You asked for the *interactive* pyramid game!\n");
         main_pyramid();
         break;
      case 'f':
         printf("You asked for file_input version of the pyramid game.\n");
         freopen("test_input.txt", "r", stdin);
         set_quiet(true);
         main_pyramid();
         break;
      case 'q':
    	  print("Goodbye");
    	  exit(EXIT_SUCCESS);
      default:
         ;
   }

   return (EXIT_SUCCESS);
}

