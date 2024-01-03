#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

void main(int argc, char *argv[])
 { int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    Key v; Item item; char s1[20]; char s2[20];
    STinit(maxN);
    for (N = 0; N < maxN; N++)
      { printf("Arithmos Mitroou\n");
        if (sw) v = ITEMrand();
          else if (ITEMscan(&v) == EOF) break;
        key(item) = v;
        printf("FirstName\n");
        scanf("%s",s1);
        printf("LastName\n");
        scanf("%s",s2);
//        STinsert(item, s1, s2);
          STinsert1(item, s1, s2);
      }
      
    STsort(ITEMshow); printf("\n");
    printf("%d keys ", N);
    printf("%d distinct keys\n", STcount());
    printf("\n");
    STprint();
    Item i=STselect(3);
    printf("The item with the i smallest key is %10d\n\n", i);
    printf("I delete the %d\n\n", i);
    STdeleteAll(i);
    STprint();
     
 }
