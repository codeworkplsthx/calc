#include "utility.h"

/*
 
 Swaps two characters.
 input: char*, char*
 output: void
 
 Remarks:
 Helper function for reverse.
 */
void
swap(char* a, char* b)
{
 char tmp = *a;
 *a = *b;
 *b = tmp;
}
/*
 
 Reverses a string
 
 Input: pointer to string
 
 Output: void
 
 Remarks:
 
 Does not allocate memory. You must provide your own.
 
 
 */

void
reverse(char* str)
{
  char* p = str;
  char* q = str + strlen(str)-1;
   
    while (p < q) 
    {
      swap(p,q);
      p++;
      q--;
    }      
}


