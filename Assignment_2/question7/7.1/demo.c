#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

void main(int argc, char *argv[])
 { int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    Key v; Item item;
    STinit(maxN);
    if(sw==0){ printf("Give %d elements\n", maxN);}
    for (N = 0; N < maxN; N++)
      {
        if (sw) v = ITEMrand();
          else if (ITEMscan(&v) == EOF) break;
        key(item) = v;
        STinsert(item);
//        STinsert1(item);
      }
    STsort(ITEMshow); printf("\n");
    printf("%d keys ", N);
    printf("%d distinct keys\n", STcount());
    STprint();
    
	/* checking the behaviour of select operation by selecting the item with the 4th smallest key */
    Item i=STselect(3);
    printf("The item with the fourth smallest key is %10d\n\n", i);
    
    /* checking the behaviour of delete operation by deleting i*/
    printf("I delete the %d\n", i);
    STdelete(i);
    STprint();
 }
