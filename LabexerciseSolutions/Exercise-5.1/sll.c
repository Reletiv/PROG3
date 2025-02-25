#include "sll.h"

#include <stdio.h>

size_t sizeSLL(const node_t *pHead)
{
   const node_t *pNext = pHead;
   size_t size = 0;

   if (pNext == NULL)
   {
      size = 0;                  // if pHead = NULL the SLL is empty, size = 0
   }
   else
   {
      while (pNext != NULL)
      {
         size++;                    // this a node so count it!
         pNext = pNext->pNextNode;  // go to the next node
      }
   }
   return size;
}

void addSLL(node_t **ppHead, int data)                   // use node_t because we possible
							 //  want to manipulate  ppHead

{
   node_t *pNext = *ppHead;                              // save the pointer to beginning of the list
   node_t *pNew = (node_t *)malloc(sizeof(node_t));      // create a new node and save the pointer in pNew

   /* Check if allocation has succeeded */
   if (pNew != NULL)
   {
      pNew->data = data;				// set the data contents of the new node
      pNew->pNextNode = NULL;				// this new node is the end of the SLL so
                                                        // it points to NULL
   }
   if (pNext != NULL)                                   // only if the list is still empty
   {
      /* Traverse through every subsequent node in the SLL */
      while (pNext->pNextNode != NULL)                  // find the last node by checking it's next node
      {                                                 // if the pointer to the next node is NULL 
         pNext = pNext->pNextNode;
      }
      pNext->pNextNode = pNew;				// connect the new node at the end
   }
   else
   {
      *ppHead = pNew;					// connect the new node to the list by adding the pointer to the end

   }
}

void clearSLL(node_t **ppHead)
{
   node_t *pToBeRemoved = *ppHead;
   node_t *pNext = NULL;

   while (pToBeRemoved != NULL)
   {
      pNext = pToBeRemoved->pNextNode;
      free(pToBeRemoved);
      pToBeRemoved = pNext;
   }
   *ppHead = NULL;
}

void showSLL(const node_t *pHead)
{
   const node_t *pNext = pHead;

   if (pHead == NULL)
   {
      printf("SLL is empty\n");
   }
   else
   {
      while (pNext != NULL)
      {
         printf("Node %p:  Data = %d  pNext = %p\n", (void *)pNext, pNext->data,
                (void *)pNext->pNextNode);
         pNext = pNext->pNextNode;
      }
   }
}
