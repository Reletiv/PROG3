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
   averageDdataPoint(sensorData, DATA_SIZE);

   for (i = 0; i < DATA_SIZE; i++)
   {
      printf(" %lf ", sensorData[i]);
   }
   puts("");

   return 0;
}

void averageDdata(double data[], int size)
{
   double sum = 0.0;       // temp result calculation
   double result = 0.0;

   for (int i = 0; i < size; i++)
   {
      sum = sum + data[i];
   }
   result = sum/size;

   for (int i = 0; i < size; i++)
   {
      data[i] = result;
   }
}

void averageDdataPoint(double data[], int size)       //solution using pointer arithmatic
{
   double sum = 0.0;       // temp result calculation
   double result = 0.0;
   double *pData = data;
   for (int i = 0; i < size; i++)
   {
      sum = sum + *(pData+i);
   }
   result = sum/size;

   for (int i = 0; i < size; i++)
   {
      *(pData+i) = result;
   }
}
