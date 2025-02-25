#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int count;
   char *pText; /* must point to dynamic allocated memory! */
} problem_t;

int deepCopy(problem_t *pDestination, const problem_t *pSource);

int main(void)
{
   problem_t s1 = {1, NULL}; /* do not do ... = {1, "ABC"} */
   problem_t s2 = {2, NULL};
   problem_t s3 = {11, NULL}; 
   problem_t s4 = {12, NULL};

   s1.pText = (char *)malloc(4 * sizeof(char)); /* array of 4 chars */
   if (s1.pText != NULL)
   {
      strcpy(s1.pText, "111");
      s2 = s1;           /* shallow copy, problem? */
      s2.pText[0] = 'A'; /* problem? */

      printf("s1 = %d %s\n", s1.count, s1.pText);
      printf("s2 = %d %s\n", s2.count, s2.pText);

      free(s1.pText); /* problem? */
   }
   s2.pText[1] = 'B'; /* problem? */
   printf("s1 = %d %s\n", s1.count, s1.pText);
   printf("s2 = %d %s\n", s2.count, s2.pText);

   /* Deep copy for ok_t */
   printf("Deepcopy version starts here\n");
   // first create the string in S3
   s3.pText = (char *)malloc(4 * sizeof(char)); /* array of 4 chars */
   if (s3.pText != NULL)
   {
      strcpy(s3.pText, "NPb");             // put some dat in the struct
      deepCopy(&s4,&s3);
      printf("s3 = %d %s\n", s3.count, s3.pText);
      printf("s4 = %d %s\n", s4.count, s4.pText);

      strcpy(s4.pText, "AAA");             // put some data in the struct s4.pText
      printf("after changing s4.pText\n");
      printf("s3 = %d %s\n", s3.count, s3.pText);
      printf("s4 = %d %s\n", s4.count, s4.pText);

   } else
   {
      printf("problem allocating memory for S3.pText\n");
   }
   // run valgrind ./deepcopy before removing the comment
   // cleaning up the strings!
   free(s3.pText);                  // free up allocated memory
   s3.pText = NULL;                 // saveguard
   free(s4.pText);
   s4.pText = NULL;

   return 0;
}

int deepCopy(problem_t *pDestination, const problem_t *pSource)
{
   // allocate memory for the string in destination
   pDestination->pText = (char *)malloc(4 * sizeof(char)); /* array of 4 chars */
   if (pDestination->pText != NULL)
   {
   //copy data from Source to Destination
   pDestination->count = pSource->count;              //deepcopy count
   strcpy(pDestination->pText, pSource->pText);       //deepcopy pText
   } else
   {
      return -1;
   }
   return 0;
}
