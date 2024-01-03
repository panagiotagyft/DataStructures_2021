#include <stdio.h>
#include <stdlib.h>
#include "PQInterface1.h"

struct PriorityQueue{
           int Count;
           PQArray ItemArray;
        };
        
void Initialize(PQ *pq){
   *pq = malloc(sizeof(PQ));     // I initialize pq. I reserve space so that the pq has an address
   (*pq)->Count = 0;             // And i initialize the Count equal with zero
   
}

int Empty(PQ pq){
   return(pq->Count==0);   // If Count equal with zero then is empty return true
}


int Full(PQ pq){
   return(pq->Count==MAXCOUNT);     // i return the i item of count if Count equal with MAXCOUNT 
}

void Insert(PQItem Item, PQ pq){
   if (!Full(pq)) {
      pq->ItemArray[pq->Count]=Item;    //I insert element --> position: pq->Count
      pq->Count++;                      // and i increase the count for the next element 
   }
}


PQItem Remove(PQ pq)
{
   int i;
   int MaxIndex;
   PQItem MaxItem;

   if (!Empty(pq)){
      MaxItem=pq->ItemArray[0];         // The max element is in the first position 
      MaxIndex=0;
      for (i=1; i<pq->Count; ++i){
         if (pq->ItemArray[i] > MaxItem){  // if the current element is bigger than max element -->
            MaxItem=pq->ItemArray[i];      // then  now max element is the current element
            MaxIndex=i;                    // and the max index now is the current i
         }
      }
      pq->Count--;                         // I decrease the count because i delete the max item
      pq->ItemArray[MaxIndex]=pq->ItemArray[pq->Count];  
      return(MaxItem);
   }
}
