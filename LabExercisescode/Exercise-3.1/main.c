#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool isInt(const char str[]);

int main(int argc, char *argv[])
{
   // error geen argumenten
   if (argc == 1)
   {
      fprintf(stderr, "Error: No arguments provided. Please provide integer values.\n");
      return 1;
   }

   // som berekenen
   int sum = 0;
   for (int i = 1; i < argc; i++)  // start vanaf 1 om naam over te slaan
   {
      if (isInt(argv[i]))  // check of argument een integer is
      {
         sum += atoi(argv[i]);  // convert string naar int en voeg hem toe aan de som
      }
      else
      {
         fprintf(stderr, "Error: '%s' is not a valid integer.\n", argv[i]);
         return 1;
      }
   }

   // som printen
   printf("Sum of all valid integers: %d\n", sum);
   return 0;
}

// int checker
bool isInt(const char str[])
{
   int i = 0;
   bool isInteger = true;

   // check of eerste karakter + of - is
   if (str[i] == '+' || str[i] == '-')
   {
      i++;
   }

   // checken of er een letter in de string zit
   while (str[i] != '\0')
   {
      if (!isdigit(str[i]))
      {
         isInteger = false;
         break;
      }
      i++;
   }

   return isInteger;
}
