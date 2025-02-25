#include <stdio.h>
#include <stdlib.h>

//prototype
void hexdumpLong(long data);

int main(void)
{
   //test the function
   hexdumpLong(1234567890);
   hexdumpLong(-1);
   hexdumpLong(0);
   hexdumpLong(42);
   return 0;
}

void hexdumpLong(long data)
{
   // pointer naar elke byte van de long waarde
   unsigned char *bytePtr = (unsigned char*)&data;

   printf("Hex dump of long value %ld:\n", data);
   for (size_t i = 0; i < sizeof(long); i++)
   {
      // print elke byte als hex
      printf("%02x ", bytePtr[i]);
   }
   printf("\n");
}
