#include <stdio.h>
#include "union_Interface.h"

int main(void){
	NodePointer u;
	NodeType *A;
	NodeType *B;
    A=NULL;
    B=NULL;
    
    // I create my list A
    insert_at_start(11, &A);
	insert_at_start(3, &A);
	insert_at_start(26, &A);
	insert_at_start(35, &A);
	insert_at_start(25, &A);
	insert_at_start(57, &A);
	insert_at_start(1, &A);
	insert_at_start(21, &A);
	
	 // I create my list B
	insert_at_start(44, &B);
	insert_at_start(39, &B);
	insert_at_start(30, &B);
	insert_at_start(0, &B);
	insert_at_start(12, &B);
	insert_at_start(211, &B);
	insert_at_start(160, &B);
	insert_at_start(500, &B);
	insert_at_start(88, &B);
	insert_at_start(450, &B);
	insert_at_start(333, &B);
	insert_at_start(27, &B);
	insert_at_start(1001, &B);
	insert_at_start(9, &B);
	
	// print lists
	printf("A :  ");
	PrintList(B);
	printf("B :  ");
	PrintList(A);
	printf("\n");
	
	u=union_2lists(A, B);  //marge A and B lists
	
	printf("C :  ");
	PrintList(u);          // print the list
	
	return 0;
}
