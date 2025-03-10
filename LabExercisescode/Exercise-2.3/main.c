#include <stdio.h>

#define DATA_SIZE 4

void averageDdata(double data[], int size);

int main(void)
{
   int i = 0;
   double sensorData[DATA_SIZE] = {1.0, 2.0, 3.0, 4.0};

   averageDdata(sensorData, DATA_SIZE);

   for (i = 0; i < DATA_SIZE; i++)
   {
      printf(" %lf ", sensorData[i]);
   }
   puts("");

   return 0;
}

void averageDdata(double data[], int size)
{
   double totaal = 0.0;
   double gemiddelde = 0.0;

   // totaal uitrekenen
   for (int i = 0; i < size; i++)
   {
      totaal += data[i];
   }

   // gemiddelde uitrekenen
   gemiddelde = totaal / size;

   // waarden vervangen voor gemiddelde
   for (int i = 0; i < size; i++)
   {
      data[i] = gemiddelde;
   }
   return;
}

