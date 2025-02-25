#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

int createQueue(queue_t *pQueue, data_t data)
{
   int succesful = 0;
   node_t *pNew = (node_t *)malloc(sizeof(node_t));
   if (pNew != NULL)   
   {   if (pQueue->pBack != NULL)                  // is pQueue an empty queue?
      {
         if (pNew != NULL)
         {
            pQueue->pBack = pNew;
            pNew->data = data; /* copy input struct data */
            pNew->pNextNode = pNew;
         }
      } else
      {
         succesful = -1;                        // queue is not empty
      }
   } else
   {
      succesful = -2;
   }
   return succesful;
}

int emptyQueue(const queue_t *pQueue)
{
   return pQueue->pBack == NULL;
}

size_t sizeQueue(const queue_t *pQueue)         // base is copied from showQueue
{
   size_t size = 0;
   const node_t *pNext = pQueue->pBack;

   if (pNext != NULL)                           //queue is not empty
   {
      do
      {
         pNext = pNext->pNextNode;              // set pointer to next
         size++;                                // increase size
      } while (pNext != pQueue->pBack);         // as long as where are not back to the beginning
   }
   return size;
}

data_t *frontQueue(const queue_t *pQueue)
{
   data_t *pFrontData = NULL;
   if (!emptyQueue(pQueue))
   {
      pFrontData = &(pQueue->pBack->pNextNode->data);
   }
   return pFrontData;
}

data_t *backQueue(const queue_t *pQueue)
{
   data_t *pBackData = NULL;
   if (!emptyQueue(pQueue))
   {
      pBackData = &(pQueue->pBack->data);
   }
   return pBackData;
}

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

void popQueue(queue_t *pQueue)
{
   if (pQueue->pBack != NULL)
   {
      node_t *pDelete = pQueue->pBack->pNextNode;
      if (pDelete == pQueue->pBack)
      {
         /* size queue == 1 */
         pQueue->pBack = NULL;
      }
      else
      {
         pQueue->pBack->pNextNode = pDelete->pNextNode;
      }
      free(pDelete);
   }
}

void deleteQueue(queue_t *pQueue)
{
   /* local pointer for traversing all nodes in queue */
//   node_t *pDelete = pQueue->pBack;
   // use popqueue to delete a node
   while (pQueue->pBack != NULL)
   {
      printf("delete\n");
      popQueue(pQueue);
   }
}

void showQueue(const queue_t *pQueue)
{
   const node_t *pNext = pQueue->pBack;

   if (pNext == NULL)
   {
      printf("Queue is empty\n");
   }
   else
   {
      printf("Queue contains:\n");
      do
      {
         pNext = pNext->pNextNode;
         printf(
            "pNode = %p  Data = '%d' '%s'\n"
            "                        pNextNode = %p\n",
            (void *)pNext, pNext->data.intVal, pNext->data.text, (void *)pNext->pNextNode);
      } while (pNext != pQueue->pBack);
   }
}
