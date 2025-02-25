#include <stdio.h>

typedef struct
{
   int element1;
   char element2;
} data_t;

void fillStruct(data_t *data);
void clearStruct(data_t *data);
void printStruct(const data_t *data);

#define N_ARRAY (3)

data_t array[N_ARRAY];

int main(void)
{
   for(int n=0; n<N_ARRAY; ++n)
   {
      fillStruct(&array[n]);
      printStruct(&array[n]);
   }

   return 0;
}

void fillStruct(data_t *data)           // data is called by reference with a pointer
                                        // of the type data_t
{
   static int n = 1;
   static char c = 'A';

   data->element1 = n;
   data->element2 = c;

   n = (n == 26) ? 1 : (n+1);           // a ternary operator: result is 1 if n == 26
                                        // else result is n + 1
   c = (c == 'Z') ? 'A' : (c+1);
}

void printStruct(const data_t *data)    // there is no change for data, so const is used
                                        // there is still a call by reference because
                                        // the argument is a structure wich can't be
                                        // transfered by value
{
    static int first = 0;
    
    if (first == 0)                         // if first == 0, print a header
    {
        printf("The contents of data:\n");
        printf("Element1\tElement2\n");
        first = 1;        
    }
    else
    {
        printf("%6d\t%10c\n", data->element1, data->element2);  // print both members, try to
                                                                // ugly way to aline them
                                                                // with the headers
    }
}

void clearStruct(data_t *data)
{

      // Implement function clearStruct
      
       data->element1 = 0;                  // clear is defined as 0
       data->element2 = '\0';                // clear is defined as \0 (is value 0)
}
