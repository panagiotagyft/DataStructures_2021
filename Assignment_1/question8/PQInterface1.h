#include "PQTypes1.h"
/* defines types PQItem and PriorityQueue */

typedef struct PriorityQueue *PQ;

void Initialize (PQ*);      // I intialize PriorityQueue
int Empty (PQ);             // I check if my array is empty 
int Full (PQ);              // I check if my array is full
void Insert (PQItem, PQ);   // I insert one element
PQItem Remove (PQ);         // I export and remove the max element
