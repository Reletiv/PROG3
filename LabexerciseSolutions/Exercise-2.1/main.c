#include <stdio.h>

int isLittleEndian(void);
void hexdumpLong(long int data);

int main(void)
{
   long int i1 = 0;
   long int i2 = 1;
   long int i3 = 255;

   if (isLittleEndian())
   {
      puts("     Little endian integers:\n");
   }
   else
   {
      puts("     Big endian integers:\n");
   }

   hexdumpLong(i1);
   puts("");
   hexdumpLong(i2);
   hexdumpLong(-i2);
   puts("");
   hexdumpLong(i3);
   hexdumpLong(-i3);

   return 0;
}

int isLittleEndian(void)
{
   const int test = 1;
   const unsigned char* pByte = (const unsigned char*)&test;

   return pByte[0] == 1;
}

void hexdumpLong(long int data)
{
   const unsigned char *pData = (const unsigned char *)&data;

   printf("%10d = ", data);
   for (size_t i = 0; i < sizeof(long int); i++)
   {
      printf("%02x ", pData[i]);
   }
   printf("\n");
}
