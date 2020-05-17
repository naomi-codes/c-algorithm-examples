/*
 * YOUR WORK GOES HERE!
 *
 * STUDENT_ID:
 *
 * ADDITIONAL COMMENTS (if any):
 */


#include "my_strings.h"

#define MAX_STR 20

int length(const char s[])
{
    return -1;
}


void reverse(char s[])
{

}


void insert(char s1[], const char s2[], int n)
{

}


bool search(const char s1[], const char s2[])
{
    return false;
}


/*
 * main_strings:  This is the entry point to your strings test.
 *                Samples have been provided.
 *
 * Pretend this is the main() function as you are use to writing,
 * i.e. the function where your program logic begins and terminates.
 */
int main_strings()
{
   printf("Length of \"Hello!\" is %d.\n", length("Hello!"));

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

   insert(ab, b, 5);
   printf("Combine strings: %s.\n", ab);

   return 0;
}

