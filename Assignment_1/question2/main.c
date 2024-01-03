#include <stdio.h>
#include "DoublyList_Interface.h"

int main (void){
	ListNode a, b, anext, aprev, c;
	
	//I create my list
	List l=Create();
    printf("The list is %s empty \n",	( IsEmpty(l)) ? " " : "not" );
	printf("List size: %d\n", Size(l));
	
	//I insert new node at the end of the list with item 29
	AddLast(l, make(29));
	printf("I insert new node at the end of the list with item 29\n");
	printf("List size: %d\n", Size(l));
	Print(l);
	
	//I insert new node at start of the list with item 12
	AddFirst(l, make(12));
	printf("I insert new node at start of the list with item 12\n");
	printf("List size: %d\n", Size(l));
	Print(l);
	
	//I insert new node at the end of the list with item 25
	AddLast(l,make(25));
	printf("I insert new node at the end of the list with item 25\n");
	printf("List size: %d\n", Size(l));
	Print(l);
	
	//I insert new node at start of the list with item 100
	AddFirst(l, make(100));
	printf("I insert new node at start of the list with item 100\n");
	printf("List size: %d\n", Size(l));
	Print(l);
	
	//I insert new node at start of the list with item 50
	AddFirst(l, make(50));
	printf("I insert new node at start of the list with item 50\n");
	printf("List size: %d\n", Size(l));
	Print(l);
	
	//I insert new node at start of the list with item 80
	AddFirst(l, make(80));
	printf("I insert new node at start of the list with item 80\n");
	printf("List size: %d\n", Size(l));
	Print(l);
	
	//I insert new node at the end of the list with item 70	
	AddLast(l, make(70));
	printf("I insert new node at the end of the list with item 70\n");
	printf("List size: %d\n", Size(l));
	Print(l);

    //The last node
    a=GetLast(l);
    printf("\n The last node is: %d\n", item(a));
    
    //I insert new node after the last node %d of the list with item 49
    AddAfter(l, make(49), a);
    printf("I insert new node after the last node %d of the list with item 49\n", item(a));
    Print(l); 
    
    //The last node 
    a=GetLast(l);
    printf("\n The last node is: %d\n", item(a));
    printf("I remove the last node %d\n", item(a));
    Remove(l, a);
    Print(l);
    printf("List size: %d\n", Size(l));
    
    a=GetLast(l);
    printf("\n The last node is: %d\n", item(a));
    aprev=GetPrev(l,a);
    printf("The previous node from the node %d is %d\n",item(a), item(aprev));
    
    b=GetFirst(l);
    printf("\n The first node is: %d\n", item(b));
    
    //I insert new node before the first node %d of the list with item 32
	AddBefore(l, make(32), b);
	printf("I insert new node before the first node %d of the list with item 32\n", item(b));
    Print(l);
    printf("List size: %d\n", Size(l));
   
    b=GetFirst(l);  //The first node
    printf("\n The first node is: %d\n", item(b));
    printf("I remove the first node %d\n",item(b));  
    Remove(l, b);
    Print(l);
    
    b=GetFirst(l);
    printf("\n The first node is: %d\n", item(b));
    anext=GetNext(l,b);
    printf("The next node from the node %d is %d\n",item(b), item(anext));
    
    //I insert new node before the node %d of the list with item 46
    AddBefore(l, make(46), anext);
    printf("I insert new node before the node %d of the list with item 46\n",item(anext));
    Print(l);
    printf("List size: %d\n", Size(l));
    
    c=anext;
    anext=GetNext(l,c);
    printf("The next node from the node %d is %d\n",item(c), item(anext));
    
    AddAfter(l, make(76), anext );
    printf("I insert new node after the node %d of the list with item 76\n", item(anext));
    Print(l);
    printf("List size: %d\n", Size(l));
		
	aprev=GetPrev(l,anext);
	printf("The previous node from the node %d is %d\n",item(anext), item(aprev));
    
    printf("I remove the node %d\n", item(aprev));
    Remove(l, aprev);
    Print(l);
    printf("List size: %d\n", Size(l));
    
	printf("The list is %s empty \n",	( IsEmpty(l)) ? " " : "not" );
    
}
