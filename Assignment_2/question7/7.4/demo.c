#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

void main(int argc, char *argv[])
 { int N,n, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    Key v; Item item;
    Tree t1, t2, t3;
    STinit(&t1);
    printf("FIRST Tree give %d elements\n",maxN);
    for (N = 0; N < maxN; N++){
    	if (sw) v = ITEMrand();
        else if (ITEMscan(&v) == EOF) break;
        key(item) = v;
        t1=STinsert(item, t1);
//        t1=STinsert1(item, t1);
    }
    STinit(&t2);
    printf("SECOND Tree give %d elements\n",maxN);
    for (N = 0; N < maxN; N++){
    	if (sw) v = ITEMrand();
        else if (ITEMscan(&v) == EOF) break;
        key(item) = v;
        t2=STinsert(item, t2);
//        t2=STinsert1(item, t2);  
    }
    STinit(&t3);
    printf("THIRD Tree give %d elements\n",maxN);
    for (N = 0; N < maxN; N++){
    	if (sw) v = ITEMrand();
        else if (ITEMscan(&v) == EOF) break;
        key(item) = v;
        t3=STinsert(item, t3);
//        t3=STinsert1(item, t3);
    }

	    printf("%d keys ", N);
        printf("%d distinct keys t1\n", STcount(t1));   
		printf("%d distinct keys t2\n", STcount(t2)); 
		printf("%d distinct keys t3\n", STcount(t3)); 
        
		Item i=STselect(3, t1);
		printf("t1: The item with the fourth smallest key is %10d\n", i);
		i=STselect(3,t2);
		printf("t2: The item with the fourth smallest key is %10d\n", i);
		
		printf("Print t3\n");
		STprint(t3);
		printf("=================================================================================\n");
		printf("Print t2\n");
		STprint(t2);
		printf("=================================================================================\n");
		printf("Print t1\n");
        STprint(t1);
        printf("=================================================================================\n");
        
        printf("i delete the fourth smallest key from t1,t2,t3\n");
        STdeleteAll(STselect(3,t1),t1);  
        STdeleteAll(STselect(3,t2),t2);
        STdeleteAll(STselect(3,t3),t3);
		
		printf("Print t3\n");
		STprint(t3);
		printf("=================================================================================\n");
		printf("Print t2\n");
		STprint(t2);
		printf("=================================================================================\n");
		printf("Print t1\n");
        STprint(t1);
        printf("=================================================================================\n");
        
        printf("%d distinct keys\n", STcount(t3)); 
		
 }
