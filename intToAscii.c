#include "intToAscii.h"
#include "utility.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h> 

/* 
input: 32-bit integer
output: 32-byte string
 
Converts a two's complement integer to a string.
*/

void
intToBinaryAscii(long long* num, char* s)
{
   unsigned int digit = 0;
   int i = 0;
  while(*num != 0)
    {
      
      if (*num % 2 == 1) { digit = 1;}
      else if (*num % 2 == 0) { digit = 0;}
      s[i] = digit + '0';
      i++;
      *num >>= 1;
    }
 
  reverse(s);
}


void
intToDecimalAscii(long long* num, char* s)
{
  char* sign = &s[0];
  char* num_str = &s[1];

  if (num == 0)
  {
    s[0] = 'd'; s[1] = '0';
    return;
  }
  else if (num < 0)
  {
    s[0]  = '-';
    *(s+1) = 'd';
    num_str = &s[2];
    
  }
 
 else {*sign = 'd';}
 char* it = &s[2];

 while(*num != 0)
  {
    if (*num%10 < 0)
    {
      *it = -(*num%10) + '0';
    }
    else{
    *it = *num%10 + '0';
    }

    it++;
    *num /=10;

     }
 reverse(num_str); 
 }


void
intToHexAscii(long long* num, char* s)
{

  int i = 0;
  while (*num != 0)
  {
    if (*num%16 >= 0 && *num%16 <= 9)
    {
      s[i] = (*num%16) + '0';
    }
    else if (*num%16 >= 10 && *num%16 <= 15)
    {
      s[i] = (*num%16) + '7';
    }
    else if (*num%16 < 0 && *num%16 > -7 )
    {
      s[i] = (*num%16 + 16) + '7';
    }
    else if (*num%16 <= -7 && *num%16 >= -15)
    {
      s[i] =  (*num%16 + 16) + '0';
    }
    *num /= 16;
    i++;
  }
  reverse(s);
}




void
intToOctalAscii(long long* num, char* s)
{

  int i = 0;
  while (*num != 0)
  {
    if (*num%8 >= 0 && *num%8 <= 7)
    {
      s[i] = (*num%8) + '0';
    }
   else if (*num%8 <= -1 && *num%8 >= -7 )
    {
      s[i] = (*num%8 + 8) + '0';
    }
   *num /= 8;
    i++;
  }
  reverse(s);
}


