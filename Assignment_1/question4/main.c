#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h"

int main(void) {
	char word1[10], word2[10], word3[10];
    int s;	
	//i store the 3 words
	printf("The first word:  \n");
	scanf("%s", word1);
	printf("The second word:  \n");
	scanf("%s", word2);
	printf("The third word:  \n");
	scanf("%s", word3);
	
	

	s=solve_the_problem(word1, word2, word3);
	if (s==0) { printf("I can't solve the problem\n"); }
    else { printf("This is the solution of this problem\n"); }
	return 0;
}
