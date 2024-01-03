#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct listnode{
	Item item;
	struct listnode *next;
} NodeType;

typedef NodeType *NodePointer;

// Functions
void PrintList(NodeType *);
void insert_at_start(Item , NodeType **);
int rec_MAX(NodePointer, Item);

int main(void){
	
	NodeType *L;
    L=NULL;
    
    // I create list with different elements 
    insert_at_start(22, &L);
	insert_at_start(3, &L);
	insert_at_start(29, &L);
	insert_at_start(6, &L);
	insert_at_start(25, &L);
	insert_at_start(5, &L);
	insert_at_start(1, &L);
	insert_at_start(10, &L);
	insert_at_start(500, &L);
	insert_at_start(88, &L);
	insert_at_start(450, &L);
	insert_at_start(13, &L);
	insert_at_start(333, &L);
	insert_at_start(27, &L);
	insert_at_start(1001, &L);
	insert_at_start(9, &L);

    printf("My list:\n");
	PrintList(L);  // I print the list
	
	printf("The maximum element is %d\n", rec_MAX(L, 0));
	
	return 0;
}

// Insert at start elements
void insert_at_start(Item i, NodeType **L) {
	 NodeType *templist, *N;
     templist = *L; 
     N = (NodeType *)malloc(sizeof(NodeType));     // I create a node N
     N->item=i;                                    // I initialize the item of the node
     N->next = templist;                           // The next pointer of the node N point to templist (to the list)
     *L=N;                                         // L point to N
}

// Print List
void PrintList(NodeType *L){
      NodeType *N;

      printf("(");
      N=L;
      while(N != NULL) {
         printf("%d", N->item);              // I cross the list and i print the nodes.
         N=N->next;
         if (N!=NULL) printf(",");
      }
      printf(")\n");
}

//Return the maximum element from list
int rec_MAX(NodePointer list, Item x){
	if(list==NULL){                     // If i cross all nodes --> return the max element.
		return x;                          
	}
	if(list->item > x){                   // If the item of the current node is bigger than x then
		x=list->item;                     //--> x equal with this item and call a function again.
		return rec_MAX(list->next, x);   
	}
	else{
		return rec_MAX(list->next, x);    // Call a function again.
	}
	
}
