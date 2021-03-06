
/*
 * DO NOT EDIT THIS FILE.
 *
 * File:   my_string.h
 * Author: naomi lambert
 *
 */

#ifndef MY_STRING_HELPERS_H
#define MY_STRING_HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * length: Returns the length of a string.
 *
 * Parameters:
 *      string[] - string
 *
 * Returns: length of string s[].
 */

int length(const char string[]);


/*
 * reverse: Reverses a string s. For example, if outputting s
 *          produces "Hello" before the function, then outputting
 *          s after the function produces "olleH".
 *
 * Parameters:
 *      string[] - string
 *
 * Modifies: s[] so that the original string is stored in reverse order.
 */

void reverse(char string[]);


/*
 * insert: Inserts s2 into s1 at the nth character of s1. The size
 *         of s1[] array is assumed to be large enough to store s1 + s2.
 *         For an n == 0, s2 precedes s1. For n >= length-of-s1, s2 follows s1.
 *
 * Parameters:
 *      s1[] - string
 *      s2[] - string
 *      n    - integer
 *
 * Modifies: s1[] so that it contains the original s1, additionally
 *           with s2 inserted at the nth location in s1.
 */

void insert(char s1[], const char s2[], int n);


/*
 * search: Determines if string s2 appears as a substring in s1.
 *
 * Parameters:
 *      s1[] - string
 *      s2[] - string
 *
 * Returns:
 *      true  - if s2 is in s1;
 *      false - otherwise.
 */

bool search(const char s1[], const char s2[]);


/*
 * main_strings:  This is the entry point to your strings test.
 *                Samples have been provided.
 *
 * Pretend this is the main() function as you are use to writing,
 * i.e. the function where your program logic begins and terminates.
 */
int main_strings();



#ifdef __cplusplus
}
#endif

#endif /* MY_STRING_HELPERS_H */

