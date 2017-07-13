#include "asciiToInt.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void
binaryAsciiToInt(char* s, long long* n)
{
  unsigned char i = 1;
  for(; i <= 65;i++)
  {
    if (s[i] == '1'){ *n = (*n << 1) + 1;}
    else if (s[i] == '0'){ *n = *n << 1;}

  }
}

void
octalAsciiToInt(char* s, long long* n)
{
  unsigned char i = 1;
  for(;i <= 21;i++)
  {
    unsigned char digit = s[i] - '0';
    if (digit >= 0 && digit <= 7)
    {
      *n = (*n << 3) + digit;
    }
    else if (s[i] == '\0') { return; }

    else
    {
      printf("octalAsciiToInt(): Error. Badly-formed input. Exiting...\n");
      exit(-1);
    }
   }
}
void
decimalAsciiToInt(char* s, long long* n)
{
  
  bool isNeg = false;
  if (s[0] == '-')
  {
    isNeg = true;
  }
  else if (s[0] == 'd')
  {
    isNeg = false;
  }
  else
  {
    printf("decimalAsciiToInt(): Error. Badly-formed input: Exiting...\n");
    exit(-1);
  }
  
  if (isNeg)
  {
    unsigned char power = strlen(s)-3;
    unsigned char i = 2;
    for(;i <= 19;i++)
    {
      if (s[i] == '\0')
      {
        *n *= -1; return;
      }

      signed int digit = s[i] - '0';

      long long product = (long long)(digit * pow(10,power));
      *n = *n + product;
      power--; 
    }
     *n *= -1;

  }
  else
  {

    unsigned char power = strlen(s)-2;
    unsigned char i = 1;
    for(;i <= 19;i++)
    {
       if (s[i] == '\0') { return; }

      signed int digit = s[i] - '0';

     long long product = (long long)(digit * pow(10,power));
     *n = *n + product;
     power--;
    }
   
   } 
}

void
hexAsciiToInt(char* s, long long* n)
{
    
  unsigned char i = 1;
  for(;i <= 16;i++)
  {
    if (s[i] == '\0')
    {
      return;
    }
    int digit;
    hexCharToInt(&s[i],&digit);
    if (digit >= 0 && digit <= 0xF)
    *n = (*n << 4) + digit;

    else
    {
      printf("Error. Badly-formatted input. Exiting...\n");
      exit(-1);
    }
 

  } 

}
    
void
hexCharToInt(char* c, int* n)
{
  if (*c >= '0' && *c <= '9')
  {
    *n = *c - '0';
     return;
  }
  else
  { 
  switch(*c)
  {
    case 'A': case 'a': *n = 0xA; break;
    case 'B': case 'b': *n = 0xB; break;
    case 'C': case 'c': *n = 0xC; break;
    case 'D': case 'd': *n = 0xD; break;
    case 'E': case 'e': *n = 0xE; break;
    case 'F': case 'f': *n = 0xF; break;
    default:
	printf("hexCharToInt(): Error. Badly-formed input. Exiting...\n");
        exit(-1);
  }
  }
}

