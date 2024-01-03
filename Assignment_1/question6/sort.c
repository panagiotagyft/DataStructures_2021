#include <stdio.h>
#include "sort_Interface.h"

int main(void){
	
	NodeType *L;
    L=NULL;
    
    PrintList(L);  // print the list
    
    // I create my list
    insert_at_start(11, &L);    
	insert_at_start(3, &L);
	insert_at_start(26, &L);
	insert_at_start(35, &L);
	insert_at_start(25, &L);
	insert_at_start(57, &L);
	insert_at_start(1, &L);
	insert_at_start(21, &L);
	
	PrintList(L);  // I print list before sorting
	L=ListSort(L); // Sort my list
	PrintList(L);  // Print my sort list
	
	return 0;
}
