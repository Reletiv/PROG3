#include <stdio.h>

void average2D(double *pD1, double *pD2);

int main(void)
{
   double d1 = 2.0;
   double d2 = 3.0;

   average2D(&d1, &d2);
   printf(" d1 = %lf   d2 = %lf\n", d1, d2);

   return 0;
}

void average2D(double *pD1, double *pD2)    // both arguments are transfered as references
{
    double result = 0.0;                    // just to make the calculation easy
    result = (*pD1 + *pD2)/2;               // use dereferencing to get the value of D1 and D2
    *pD1 = result;                          // again use dereferencing to manipulate the 
                                            // value of D1 and D2
    *pD2 = result;
}
