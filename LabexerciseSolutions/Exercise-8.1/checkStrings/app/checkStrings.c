#include "checkStrings.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE_MACADDRESS 17 /*!< Format MAC address 17 chars */

void trim(char dest[], const char src[])
{
   const char *pWSleading = src;
   const char *pWStrailing = src + strlen(src) - 1;
   int i = 0;

   while (isspace(*pWSleading))
   {
      pWSleading++;
   }
   while (isspace(*pWStrailing) && (pWStrailing >= src))
   {
      pWStrailing--;
   }
   while (pWSleading <= pWStrailing)
   {
      dest[i++] = *pWSleading++;
   }
   dest[i] = '\0';
}

bool isInteger(const char str[])
{
   bool isOK = true;

   for (size_t i = 0; i < strlen(str); i++)
   {
      if (!isdigit(str[i]))
      {
         isOK = false;
         break;
      }
   }
   return isOK;
}

bool isIntExtend(const char str[])
{
   int i = 0;
   bool isInteger = true;
   if (str[0] == '\0') // zero length string
   {
      isInteger = false;
   }
   while (str[i] != '\0' &&
          isInteger) // as long as it is not the of the string
   {
      if (i == 0 && strlen(str) > 1) // if this is the first character
      {
         if (!(str[i] == '-' || str[i] == '+' ||
               isdigit(str[i]))) // and is not a digit or minus or plus
         {
            isInteger = false; // then it is not an integer
         }
      }
      else if (!isdigit(str[i])) // if one of the chars is not a digit
      {
         isInteger = false; // then it is not an integer
      }
      i++;
   }
   return isInteger;
}


bool isMACaddress(const char str[])
{
   if (strlen(str) != SIZE_MACADDRESS)
   {
      return false;
   }
   unsigned int s;
   int nOK =
      sscanf(str, "%02x:%02x:%02x:%02x:%02x:%02x", &s, &s, &s, &s, &s, &s);
   return (nOK == 6);
}
