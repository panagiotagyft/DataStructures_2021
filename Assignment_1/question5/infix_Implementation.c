#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "item.h"

// int stack
static int *s;
static int N;

// Initialize the first stack
void STACKinit(int maxN){
  s = malloc(maxN * sizeof(int));     // I create the first stack
  N = 0;
}

// I check if the stack is empty
int STACKempty(void){ return N == 0; }       // If stack is empty return 0

void STACKpush(Item item){ s[++N] = item; }  // I increase N to insert the element

Item STACKpop(void){ 
    Item c;         
    c=s[N--];      // I lower the N to export the element
	return c; }  

static int *r;
static int N2;

void secSTACKinit(int maxn){
  r = malloc(maxn * sizeof(int));   // I create the second stack
  N2 = 0;
}

int secSTACKempty(void){ return N2 == 0; }   // If stack is empty return 0

void secSTACKpush(int item){ r[++N2] = item; } // I increase N2 to insert the element

int secSTACKpop(void){
	int i=r[N2];      
    r[N2--]=0;   // I lower the N2 to export the element and i initialize the current position with zero
    return i;
}
