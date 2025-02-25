#include <stdbool.h>

bool testfunc(bool a, bool b, bool c)
{
   if (a && b || c)
   {
      return true;
   } else
   {
      return false;
   }
}
