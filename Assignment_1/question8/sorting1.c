#include <stdio.h>
#include "PQInterface1.h"
#include "PQTypes1.h"
/* Note: MAXCOUNT is 10 */

// I fill PriorityQueue
void PriorityQueueSort(SortingArray A)
{
   int i;
   PQ pq;

   Initialize(&pq);
   for (i=0; i<MAXCOUNT; ++i) Insert(A[i], pq);
   //printf("The queue contains %d elements\n",(*pq)->Count); // With this print i check if all it's OK 
    
   for (i=MAXCOUNT-1; i>=0; --i) A[i]=Remove(pq);
}
int SquareOf(int x)
{
  return x*x;          // i create elements
}

int main(void)
{
   int i, A[MAXCOUNT];

   for (i=0; i<10; ++i){
      A[i]=SquareOf(3*i-13);
      printf("%d ",A[i]);
    }
    printf("\n");

    PriorityQueueSort(A);

    for (i=0; i<10; ++i) {
      printf("%d ",A[i]);
    }
    printf("\n");
}
