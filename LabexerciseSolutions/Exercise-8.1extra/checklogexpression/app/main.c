/* Testen van logical expressie */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

#define NUMBEROFTESTCASES 8



typedef struct testcase
{
   bool a;
   bool b;
   bool c;
   bool result;
} testcase_t;

int main(void)
{
   bool a;
   bool b;
   bool c;
   bool result;
   testcase_t testcases[NUMBEROFTESTCASES] = {
      {true, true, true, true},
      {true, true, false, true},
      {true, false, true, true},
      {true, false, false, false},
      {false, true, true, true},
      {false, true, false, true},
      {false, false, true, true},
      {false, false, false, false}
      };
   for (int i = 0; i < NUMBEROFTESTCASES; i++)
   {
      a = testcases[i].a;
      b = testcases[i].b;
      c = testcases[i].c;
      result = testcases[i].result;
      if (testfunc(a, b, c) == result)
      {
         printf("%d passed\n", i);
      } else
      {
         printf("%d failed\n", i);
      } 


   }

   return 0;
}


