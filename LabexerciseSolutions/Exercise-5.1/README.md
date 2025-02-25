# Exercise 5.1 singly linked list grootte bepalen

Voor dat je deze opdracht kunt doen, moet je een copie maken van de bookcode *bookcode/singlyLinkedList/app* directory. Daar staat de basi inclusief de SLL library die beschikbaar is.

## Basis algoritme voor het doorlopen van een SLL
Een van de basis algoritmes, dus code snippet, voor een SLL is om door een lijst heen te lopen. Deze code is te vinden in de library bij o.a. showSLL en ziet er in basis als volgt uit:

```c
const node_t *pNext = pHead;

   if (pHead == NULL)					//controleer of de lijst niet leeg is, dan is de start nl. NULL
   {
      printf("SLL is empty\n");
   }
   else
   {
      while (pNext != NULL)				// loop door de lijst heen totdat verwijzing NULL wordt
      {
		<<actie voor de node>>			// hier kun iets doen, pNext is de huidige node
									// pNext->data verwijst naar de dat van de huidige node
		pNext = pNext->pNextNode;		// zorg dat pNext naar de volgende node verwijst
									// dan kan 
      }

```
## sizeSLL()

Dit kan dus bij de sizeSLL worden gebruikt, de actie is dan het tellen van de node door *size++*

