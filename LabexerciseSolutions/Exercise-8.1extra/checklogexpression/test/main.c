/* Unit tests: using Unity unit test framework */

#include "../app/functions.h"
#include "unity.h"
#include <stdio.h>
#include <stdbool.h>


void test_logExpr(void)
{
   printf("---- trim()\n");

   {
      //example with variables a, b, c
      bool a = true;
      bool b = true;
      bool c = false;
      TEST_ASSERT_TRUE_MESSAGE(testfunc(a,b,c), "test 1");
      //example without variables
      TEST_ASSERT_TRUE_MESSAGE(testfunc(true,false,false), "test 2");
   }
}



int main(void)
{
   UNITY_BEGIN();
   printf("== Unit tests 'Logical expressions' ==\n\n");
   RUN_TEST(test_logExpr);
   return UNITY_END();
}
