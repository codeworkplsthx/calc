#include "asciiToInt.h"

#include <stdio.h>
int 
main(int argc, char* argv[])
{
  long long n;
  hexAsciiToInt(argv[1],&n);
 
  printf("%lld\n",n);
 return(0);
}
