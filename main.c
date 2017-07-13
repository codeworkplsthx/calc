#include "asciiToInt.h"

#include <stdio.h>


int
main(int argc, char* argv[])
{
  char s[21];
  printf("Enter a sequence of octal digits (properly formatted): \n");
  scanf("%s",s);
 
  long long num;
  octalAsciiToInt(s,&num);

  printf("64-bit integer: %lld\n",num);


 return(0);
}
