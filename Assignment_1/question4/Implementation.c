#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h"
int sol=0;
int  f; 
char g[1];

int next_position(int position){
	int mult=1;
    for (position; position>0; position--){
            mult = mult * 10;                  //return dynamic 10
    }
    return mult;
} 
int search(char *str, NodeType *list){
	NodeType *N;
	N=list;
    while(N!=NULL){
    	if(strcmp(N->str, str)==0) { return 1; }     // if letter there is in list --> return 1
    	N=N->next;
	}
	return 0;
}

int insert(char *str, NodeType **list, int counter_letter){
	int l, i, y=0;
	char s[1];
	NodeType *templist, *N, *P;
	templist = *list; 
	l=strlen(str);
	
	for(i=0; i<l; i++){
		s[y]=str[i];
        if(search(s, *list)==0){                  // If this letter there is not in array --> insert 
			N=(NodeType *)malloc(sizeof(NodeType));   // create a node 
            strcpy(N->str, s);                        // copy letter
            N->next=NULL;                             // and the next pointer of node N point to NULL
            if (*list == NULL) {      // If list is empty           
            	*list=N;              // list point to N
			}
			else {
				P=*list;                   
                while (P->next != NULL) P=P->next;  // I cross the list until I reach the end
                P->next=N;                          // and the next pointer of the node N point to N
            }
            counter_letter++;                       // I increase the counter because i count the size of the list
		}
		s[y]='\0';
	}
	return counter_letter;                       // i return the counter
}

void addarray(NodeType *list, Letters *array){
	NodeType *N;
	N=list;
	char s[1];
	int i=0;
	while(N!=NULL){
		strcpy(s, N->str);
	    if(	strcmp(N->str, g)==0){ f=i;}   // i save the position of the first letter of the word3
		array[i++].letter=s[0];            //  i fill the array
		N=N->next;
	}
}
int aritmetical_value(Letters *array, int counter, char *word){
	int y=0, l, equivalent_num=0, num, i,j, p;
	l=strlen(word);
	l=l-1;
	for (i = l; i >= 0; i--){
		for (j = 0; j < counter; j++){
			if (array[j].letter == word[i]) { break;}
        }
    	p=next_position(y++);   //for example if y=0 and p=10 the next is y=1 p=100
		num=p*array[j].item;    
        equivalent_num += num;
    }
    return equivalent_num;
}
void Has_the_problem_been_solved(Letters *array, int counter, char *word1, char *word2, char *word3){
	int num1, num2, num3, num, i;
    
    num1=aritmetical_value(array, counter, word1);   // find the aritmetical value for word 1
    num2=aritmetical_value(array, counter, word2);   // find the aritmetical value for word 2
    num3=aritmetical_value(array, counter, word3);   // find the aritmetical value for word 3
 
    num=num1+num2;     
	if (num3==num){  // if addition num1 and num2 equal with num3
	    if (array[f].item!=0){  //if the first letter from word3 is 0 there is not solution.
			sol=1;        // there is solution
			printf("|");
			for(i=0; i < counter; i++){
				printf("  %c = %d  | ", array[i].letter, array[i].item);
			}
			printf("\n");
		}
	}
}
void matching_numbers(int counter, Letters *array, int position, char *word1, char *word2, char *word3){
	int i;
	if (position == counter - 1){  //if i am in the last position
		for (int i = 0; i<=9 ; i++) {
			if (array[i].reserved_num == 0){   // if i is not used 
				array[position].item= i;       // i initialize the array->item equal with i
			    Has_the_problem_been_solved(array, counter, word1, word2, word3); // check if i find the solution	
			}
		}
	}
    else{
    	for (int i = 0; i <=9; i++){
    		if (array[i].reserved_num == 0){
    			array[position].item=i;    // i initialize the array->item equal with i
    			array[i].reserved_num=1;   // i initialize the array->reserved_num equal with 1 because the i used
    			matching_numbers(counter, array, position+1, word1, word2, word3);    // i call again the fuction to initialize the next positions
				array[i].reserved_num=0;            // i initialise the array->reserved_num equal with 0 to check others possible solutions
			}
	    }
	}
}
int solve_the_problem(char *word1, char *word2, char *word3){ 
    NodeType *L;
    L=NULL;
	int l1, l2, l3, c1, c2, c3, i, position=0;
	g[0]=word3[0];
	l1=strlen(word1);
	l2=strlen(word2);
	l3=strlen(word3);
    
    //insert the letter in the list and return the counter
	c1=insert(word1, &L, 0);   
	c2=insert(word2, &L, c1);
	c3=insert(word3, &L, c2);
;
	if((array=malloc(c3*sizeof(Letters)))==NULL){
		printf("Error:Not available memory\n");
		return 0;
	}
	
	for(i=0; i< c3; i++){
		array[i].reserved_num=0;     //I initialize the array	
	}
	
	addarray(L,array);    // I fill the array
	
	
	

	if (c3 > 10){ printf("ERROR! many letters.I want ten leters NOT %d. ", c3); return 0; }   // i check if letters is =>9
	
	
    matching_numbers(c3, array, position, word1, word2, word3);   
 
	return sol;
}


