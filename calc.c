#include "asciiToInt.h"
#include "intToAscii.h"

#include <stdio.h>
#include <string.h>

int 
main(int argc, char* argv[])
{
   
   if (argc < 4)
   {
     printf("calc <op> <num1> <num2> <base>\n");
   }

   char op = *argv[1];
  
   long long number[2] = {0,0};
   char output[65];
   memset(output,0,65);

    /* convert ascii string to correct format */
   long long result = 0;
   switch(*argv[2])
   {
     case 'd': case '-':  decimalAsciiToInt(argv[2],&number[0]); break;
     case 'x': hexAsciiToInt(argv[2],&number[0]); break;
     case '0': octalAsciiToInt(argv[2],&number[0]); break;
     case 'b': binaryAsciiToInt(argv[2],&number[0]); break;
     default: printf("main(): Error. Badly-formed input. Exiting...\n");
   }
   switch(*argv[3])
   {
     case 'd': case '-': decimalAsciiToInt(argv[3],&number[1]); break;
     case 'x': hexAsciiToInt(argv[3],&number[1]); break;
     case '0': octalAsciiToInt(argv[3],&number[1]); break;
     case 'b':  binaryAsciiToInt(argv[3],&number[1]); break;
     default: printf("main(): Error. Badly-formed input. Exiting...\n");

   }
    
    /* apply correct operation to numbers  */
   switch(op)
   {
     case '+': result = number[0] + number[1]; break;
     case '-': result = number[0] - number[1]; break;
     case '*': result = number[0] * number[1]; break;
     default: printf("main(): Error. Badly-formed input. Exiting...\n");

   }
   /* convert result to correct base */
   char output_base = *argv[4];
  
  switch(output_base)
   {
     case 'd':  intToDecimalAscii(&result,output); break;
     case 'x':  intToHexAscii(&result,output); break;
     case '0':  intToOctalAscii(&result,output); break;
     case 'b':  intToBinaryAscii(&result,output); break;
     default: printf("main(): Error. Badly-formed input. Exiting...\n");

   }
  printf("%s\n",output);
 
  return 0;
}
