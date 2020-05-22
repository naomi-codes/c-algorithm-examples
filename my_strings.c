/*
 *
 * File: my_strings.c
 * Author: naomi lambert
 *
 *
 */


#include "my_strings.h"

#define MAX_STR 20

/*
 * length: Returns the length of a string.
 *
 * Parameters:
 *      string[] - string
 *
 * Returns: length of string string[].
 */
int length(const char string[])
{
    int count = 0;
    const char *p = string;

    if ( p != NULL) {
    while (*(p+count) != '\0'){
       count++;
        }
    }
    return count;
}


/*
 * reverse: Reverses a string s. For example, if outputting s
 *          produces "Hello" before the function, then outputting
 *          s after the function produces "olleH".
 *
 * Parameters:
 *      string[] - string
 *
 * Modifies: string[] so that the original string is stored in reverse order.
 */

void reverse(char string[])
{
    int len = length(string), j = len - 1, i = 0;
    char temp;

    while ( i < j) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
}


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
void insert(char s1[], const char s2[], int n)
{
    /* insert s2 into s1 immediately following the nth character
     * e.g. parameters @Alice and Bob, @Alice, @5 should result in
     * 'AliceAlice and Bob'
     *  */
    int i, j, k, q;

    int len_s2 = length(s2);
    int len_s1 = length(s1);

    if (n < len_s1){

        int other_chars_len = len_s1 - n;
        char other_chars[other_chars_len];

        for (i = 0; i < other_chars_len; i++){
            other_chars[i] = s1[n+i];
        }

        for (j = 0; j < len_s2; j++) {
            s1[n+j] = s2[j];
        }

        for (k = 0; k < other_chars_len; k++){
            s1[n+len_s2+k] = other_chars[k];
        }
    } else {

        for (q = 0; q < len_s2; q++)
            s1[len_s1+q] = s2[q];
    }
}


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
bool search(const char s1[], const char s2[])
{
    int len_s2 = length(s2);
    int len_s1 = length(s1);
    char temp[len_s2];
    int i = 0, j, k;
    bool match = true;

    if (len_s2 > len_s1){
        return false;
    } else {
        while (i <= len_s1 - len_s2) {
            for (j = 0; j < len_s2; j++) {
                temp[j] = s2[i+j];
            }
            i++;
        }

        for (k = 0; k < len_s2; k++){
            if (temp[k] != s2[k]){
                match = false;
            }
        }
    }

    if (match)
        return true;
    else
        return false;
}


/*
 * main_strings:  This is the entry point to the strings test.
 *                Samples have been provided.
 *
 */
int main_strings()
{
   printf("\nLength of \"Hello!\" is %d.\n", length("Hello!"));

   char str[MAX_STR + 1] = "Hello!";
   printf("The reverse of %s", str);
   reverse(str);
   printf(" is %s.\n", str);

   char ab[MAX_STR + 1] = "Alice and Bob";
   char  b[MAX_STR + 1] = "Alice";
   if(search(ab, b) == true) {
      printf("String '%s' is in '%s'!\n", b, ab);
   } else {
      printf("String '%s' is NOT in '%s'!\n", b, ab);
   }

   printf("Combine strings: '%s' and '%s'.\n", ab, b);
   insert(ab, b, 5);
   printf("Result is: '%s'.\n", ab);

   return 0;
}

