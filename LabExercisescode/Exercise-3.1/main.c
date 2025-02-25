#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool isInt(const char str[]);

int main(int argc, char *argv[])
{
   if (argc == 1)  // No arguments given
   {
      fprintf(stderr, "Error: No arguments provided. Please provide integer values.\n");
      return 1;
   }

   int sum = 0;
   for (int i = 1; i < argc; i++)  // Start from 1 to skip the program name
   {
      if (isInt(argv[i]))  // Check if argument is a valid positive integer
      {
         sum += atoi(argv[i]);  // Convert string to integer and add to sum
      }
      else
      {
         fprintf(stderr, "Error: '%s' is not a valid integer.\n", argv[i]);
         return 1;
      }
   }

   printf("Sum of all valid integers: %d\n", sum);
   return 0;
}

bool isInt(const char str[])
{
   int i = 0;
   bool isInteger = true;

   while (str[i] != '\0')  // Loop through each character of the string
   {
      if (!isdigit(str[i]))  // If any character is not a digit
      {
         isInteger = false;
         break;
      }
      i++;
   }

   return isInteger;
}
