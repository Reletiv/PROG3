#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isInt(const char str[]);

int main(int argc,
         char *argv[]) // add the correct arguments
                       // argc count of arguments including command
                       // argv a pointer to an array of strings
{
   int sum = 0;
   if (argc > 1)
   {
      printf("There are %d arguments for %s:\n", argc - 1, argv[0]);
      for (int i = 1; i < argc; i++)
      {
         printf("%s\t%s\t%d\n", argv[i],
                isInt(argv[i]) ? "Integer" : "Non Integer", atoi(argv[i]));
         if (isInt(argv[i]))
         {
            sum = sum + atoi(argv[i]);
         }
      }
      printf("Sum of these arguments is: %d\n", sum);
   }
   else
   {
      printf("There are no arguments\n");
   }
   return 0;
}

bool isInt(const char str[])
{
   int i = 0;
   bool isInteger = true;
   printf("%d\n", strlen(str));
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
