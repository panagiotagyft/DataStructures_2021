#include <stdio.h>
#include <stdlib.h>
#include "ST.h"

void main(void)
 { int i;
 
    STinsert(6);
    STinsert(4);
    STinsert(12);
    STinsert(15);
    STinsert(3);
    STinsert(5);
    STinsert(10);
    STinsert(8);
    STinsert(11);
    STinsert(13);
    STinsert(14);
    STinsert(17);
    
	STprint();
    printf("Nodes:  %d \n", STcount()); 
    i=STselect(3);
    printf("The item with the fourth smallest key is %10d\n", i);
    printf("Delete %d\n", STselect(1));
    i=STselect(1);
	STdelete(i);
	printf("Now check if %d there is \n",i);
    STsearch(4);
    printf("\n");

 }
