# Het maken van een hexdump programma.

Voor deze exercise geldt verder dat de basiscode in het boek staat onder *hexdump*.

De kern van dit programma zit in de mogelijkheid om pointers middels casting zich als een ander type te laten gedragen, bijvoorbeeld:

## casting
**int *pVar = NULL;** is een pointer naar een integer, pVar + 1 wijst naar de volgende integer in het geheugen (wat dus meestal 4 bytes verder is)
**(unsigned char *)pVar** is een casting van de pointer pVar. Deze pointer zal zich nu als 	een pointer naar een char gedragen. pVar + 1 wijst dus niet naar de volgende integer maar naar de volgende char (wat dus één byte is) 
De implicatie hiervan is interessant, namelijk een dereference van **(unsigned char *)pVar** een char is. Dus ook als zodanig behandeld kan worden om bijv. in bytes door het geheugen te lopen.

## Over het onderdeel little endian and big endian
Dit gaat om de wijze waarop een integer in het geheugen wordt opgeslagen. Wordt gestart met de MSB (most significant byte) of de LSB (least significant byte).
Dat is te herkennen door een test te doen op hoe de integer 1 is opgeslagen. de LSB van 1 is 0x01. Als in de eerste byte van de integer 1 0x00 in het geheugen staat wordt gestart met de MSB. 


| 0x00 | 0x00 | 0x00 | 0x01|     Big-endian

Als in de eerste byte 0x01 staat dan wordt gestart met de LSB.

| 0x01 | 0x00 | 0x00 | 0x00|     Little-endian

De functie isLittleEndian() doet dit door bye 0 te testen op waarde 1. 


