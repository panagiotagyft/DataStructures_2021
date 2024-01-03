#include <stdio.h>
#include <stdlib.h>
#include "sort_Interface.h"

void PrintList(NodeType *L){
      NodeType *N;

      printf("(");
      N=L;
      while(N != NULL) {
         printf("%d", N->item);       // I cross the list and i print the nodes
         N=N->next;
         if (N!=NULL) printf(",");
      }
      printf(")\n");
}
void insert_at_start(Item i, NodeType **L) {
	 NodeType *templist, *N;                 
     templist = *L; 
     N = (NodeType *)malloc(sizeof(NodeType)); 
     N->item=i;                           // I initialize the item of the node
     N->next = templist;                  // The next pointer of the node N point to templist (to the list)
     *L=N;                                // L point to N
}

NodeType *ListSort(NodeType *list){
	NodeType *N, *K;
	N=list;
	K=N;
	int v, x, r, m;
	r=max(list, 0);          // I find the max element
	x=delete_node(r, &list); // I delete the max element node
	InsertNewLastNode(x, &list);    // and i insert this element at the end
	m=min(list,r);                  // I find the min element
    x=delete_node(m, &list);        // I delete the min element node
    insert_at_start(x, &list);      // and i insert this element at the start 
	N=list;                         // I initialize --> N point to first node
	N=N->next;                      // N point to the next element because the first element it's OK
	while(N!=NULL){                
		N=check(list);              // Return the node N which is in the wrong place or the last node            
		if(N->item==r){ return list; }  // If the item of the node N equal with r (r is the max element)means that N is the last node and i return the list
		v=previous(N->item, list);      // else i found which should be the previous node of the node Í
		x=delete_node(N->item, &list);  // É delete node N
		add_node(x, v, &list);          // I add the node N in the right position and after for the node v which I found from function previous
        N=check(list);                  // I check again the list 
	}
}

int delete_node(int value, NodeType **list){
	NodeType *N, *temp, *K;
	N=*list;  // I have two pointers this is previous
	K=*list;
	K=K->next;   // this is next
    if(N->item==value){  // if node which i want to delete is the current node and first node
    	temp=N;       
		N=N->next;       // N point to the next node
		*list=N;         // list pointer point to N
		free(temp);      // i free the node
		return value;
	}
	else{
		while(K!=NULL){        // I search all nodes
			if(K->item==value){   // If node is the node witch i want delete  
				N->next=K->next;  // the previous node point where point and the current node
				free(K);
				
				return value;
			}
			K=K->next;      // i increase the K and N
			N=N->next;
		}
	}
}

int add_node(int value,int v, NodeType **list){
	NodeType *N, *K, *temp;
	K=*list;
	N=malloc(sizeof(NodeType));
	N->item=value;               
	while(K!=NULL){     
		if(K->item == v){     // if i found the previous node --> 
			N->next=K->next;  // The next pointer of the node N point to where it point and the next pointer of the node K
			K->next=N;        // The next pointer of the node K point to N
			return 1;         
		}

		else{
			K=K->next;            // ELSE check and the next node
		}
	}
}
int previous(int value, NodeType *list){
	int i;
	NodeType *N;
	N=list;
	for(i=value-1; i>=0; i--){           // I check all numbers 
		while(N!=NULL){                  // I search all nodes.If i is equal with one node
			if(i==N->item){  return N->item;} //then number i there is in the list and i is the previous item of the value.For example if value=2 & i=0 and N->item equal i ->return the item
			N=N->next;                        
		}
		N=list;
	}
	return value;
}
NodeType *check(NodeType *list){
	NodeType *previous, *current, *K;   
	if(list->next!=NULL){ 
	// I have 3 pointers
	    current=list;                    
	    previous=list;
	    previous=previous->next; // previous point to the second element
	    current=current->next;
	    current=current->next;   // current point to the third element 
	    K=list;                  // K point to the first element
	    while(current!=NULL){
		   if(K->item < previous->item ){    // if k node item is less than previous node item --> continue and check ELSE RETURN K node
			   if(previous->item < current->item){  // if previous node item is less than current node item --> increase all pointers point to the next elements
				   previous=previous->next;
				   current=current->next;
				   K=K->next;
			   }
			   else{ return current;}       //Else return current node
			}
		    else{ return K;}
	    }
    }
	return previous;            //Else return previous  node if list->next point to NULL        
}
int max(NodePointer list, Item x){
	
	if(list==NULL){ return x; }     // If i cross all nodes --> return the max element.
	if(list->item > x){             // If the item of the current node is bigger than x then
		x=list->item;               //--> x equal with this item and call a function again.
		return max(list->next, x);
	}
	else{ return max(list->next, x); } // Call a function again.
}

int min(NodeType *list, Item x){
	NodeType *N;
	N=list;
	int i;
		for(i=0; i <=x; i++){             // I check all number i=0 to i=x(max number)
			while(N!=NULL){               // I cross all nodes
			if(i==N->item){ return N->item;}    // If the item of one node is equal with i return thw min number
			 N=N->next;                         // else continue --> to the next node
	    }
	    N=list;                   // I initialize the N and i check i=i+1
	}
}
void InsertNewLastNode(int i, NodeType **L){
      NodeType *N, *P;

      N=(NodeType *)malloc(sizeof(NodeType));
      N->item=i;                 // I initialize the item of the node
      N->next=NULL;              // The next pointer of the node N point to NULL

      if (*L == NULL) {     // If list is empty 
         *L=N;              // L point to N
      } else {
         P=*L;              // I initialize P
         while (P->next != NULL) P=P->next;    // I cross the list until I reach the end
         P->next=N;                            // and the next pointer of the node N point to N
      }

}
