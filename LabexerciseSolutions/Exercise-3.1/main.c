#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isInt(const char str[]);

int main(int argc, char *argv[])       // add the correct arguments
                                       // argc count of arguments including command
                                       // argv a pointer to an array of strings
{
   int sum = 0;
   if (argc > 1)
   {
      printf("There are %d arguments for %s:\n", argc - 1, argv[0]);
      for (int i = 1; i < argc; i++)
      {
         printf("%s\t%s\n", argv[i], isInt(argv[i])?"Integer":"Non Integer");
         sum = sum + atoi(argv[i]);
      }
      printf("Sum of these arguments is: %d\n", sum);
   } else
   {
      printf("There are no arguments\n");
   }
   return 0;
}

bool isInt(const char str[])
{
   int i = 0;
   bool isInteger = true;
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
