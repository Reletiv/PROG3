# Exercise 6.2 Creation and Size of CSLL

## Informatie over de CSLL implementatie
(code in queueCSLL/app)
In deze opgave is de node opgebouwd uit twee structs (in queue.h):
<ul>
<li>De data is een struct gedefinieerd als data_t</li>
<li>De node is een struct gedefinieerd als node_t</li>
<li>pBack is ook gedefinieerd in een struct queue_t met nu nog 1 pointer pBack</li>
</ul>

## Maken van een CSLL
Dit heeft als implicatie dat zowel het maken en beheren van een node als het beheren van pBack via de structs verloopt. Een node maken gaat dan als volgt:
```c
node_t *pNew = (node_t *)malloc(sizeof(node_t));
```
pBack goed zetten gaat dan als volgt:

```c
pQueue->pBack = pNew;
```
## functie die een CSLL maakt

```c
void createQueue(queue_t *pQueue, data_t data)
{
   node_t *pNew = (node_t *)malloc(sizeof(node_t));		//Create a new node
   if (pNew != NULL)
   {
      pQueue->pBack = pNew;								//Connect to node to pBack
      pNew->data = data;                                //copy input struct data */
      pNew->pNextNode = pNew;							//close the circle
   }
}
```
## Een node toevoegen

Een node toevoegen (push) betekent dat er eerst een nieuwe node gemaakt moet worden:
```c
node_t *pNew = (node_t *)malloc(sizeof(node_t));     // new node
pNew->data = data;
// fill with data
```
Vervolgens moet deze ingevoegd worden, m.a.w. de pointers moeten goed gezet worden:
<ol>
<li>de pNextNode ( *pNew->pNextNode* ) van de nieuwe node moet wijzen naar de pNextNode waar pBack naar verwijst (*pQueue->pBack-pNextNode*) (dat is dus achter de eerste node)</li>
<li>de pNextNode van een eerste node (*pQueue->pBack-pNextNode*) in de CSLL moet gaan verwijzen naar de nieuwe node (pNew) Dan is de keten weer compleet en is de nieuwe node achter de eerste node van de CSLL ingevoegd.</li>
<li>de pBack (*pQueue->pBack*) gaat vervolgens wijzen naar de nieuwe node (pNew) zodat de nieuwe node aan het *"begin"* van de CSLL komt</li>
</ol> 

```c
void pushQueue(queue_t *pQueue, data_t data)
{
   node_t *pNew = (node_t *)malloc(sizeof(node_t));
   if (pNew != NULL)
   {
      pNew->data = data;
      pNew->pNextNode = pQueue->pBack->pNextNode;
      pQueue->pBack->pNextNode = pNew;
      pQueue->pBack = pNew;
   }
}
```

## Size van een CSLL bepalen

sizeQueue() kan worden afgeleid van showQueue(). Daarin staat het algoritme om het door een CSLL heen te lopen:

```c
const node_t *pNext = pQueue->pBack;

   if (pNext == NULL)
   {
      printf("Queue is empty\n");				// signal an empty queue
   } else
   if (pNext != NULL)                           //queue is not empty
   {
      do
      {
         pNext = pNext->pNextNode;              // set pointer to next
         <<actie voor deze node>>               // do something with this node (voor size: size++)
      } while (pNext != pQueue->pBack);         // as long as where are not back to the beginning
   }
```

Dit algoritme kan algemeen gebruikt worden.

# Exercise 6.3 Delete CSLL

Om de complete CSLL leeg te maken kan de functie popQueue() gebruikt worden om een node weg te gooien.

Bij het leegmaken van de queue worden alle nodes verwijderd en voor het algoritme is het van belang om te bepalen hoe je kunt bepalen of de queue leeg is.

Dat is als 
```c
pQueue->pBack = NULL;
```

Dus zolang (pBack != NULL) weer een popQueue();
```c
 while (pQueue->pBack != NULL)
   {
      printf("delete\n");
      popQueue(pQueue);
   }
```

# Exercise 6.4 Create a CSLL, checking pBack

Om zeker te weten dat de queue leeg is bij het maken van een nieuwe wordt getest op 

```c
pQueue->pBack != NULL
```

Is dit niet het geval dan is de queue niet leeg en is de return waarde -1
(de functie heeft dus nu ook een return waarde!)

# Exercise 6.5 checking malloc() in createCSLL

Dit gebeurt door een test op de pointer naar de nieuwe node:

```c
 node_t *pNew = (node_t *)malloc(sizeof(node_t));        // create new node   
   if (pNew != NULL)                                     // check malloc
```
de functie geeft nu -2 terug als het niet gelukt is.

