#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "item.h"
#include "stack.h"

/* evaluates infix expressions containing + and * signs and one digit numbers */
int main(int argc, char *argv[]) 
{
  char *inf = argv[1];;
  Item a;
  int n, i,right, left;
  
  n=strlen(inf);
  n=2*n;
  STACKinit(n);   // I initialize the first stack
  secSTACKinit(n);  // I initialize the second stack
  for (i = 0; i < n; i++){
      if (inf[i] == ')'){      // If inf[i] == ')' means i should to export elements from the stack    
      	while(!STACKempty()){    
      		a=STACKpop();         // I take an element out of the stack
      		if (a == '+'){ secSTACKpush( secSTACKpop()+ secSTACKpop()); }      // If a equal + --> I take two elements out of the stack and i add them 
			if (a == '*'){ secSTACKpush( secSTACKpop()* secSTACKpop()); }      // If a equal * --> I take two elements out of the stack and i multiply them
	    }
	  }
      if ((inf[i] == '+') || (inf[i] == '*')){
      	STACKpush(inf[i]);       // I push in the stack
	  }
      if ((inf[i] >= '0') && (inf[i] <= '9')){
      	STACKpush(inf[i]);         // I push in the first stack
	    secSTACKpush(inf[i] - '0');  // I push in the second stack
      }
   }
  printf("The result: %d\n", secSTACKpop());
  return 0;
}
