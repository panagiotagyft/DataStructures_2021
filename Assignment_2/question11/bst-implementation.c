#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode TreeNode24;
struct TreeNode {
  int item[4];
  int Counter;
  TreeNode24 *link[4];
  int N;
};
typedef enum { False, True }Bool;
TreeNode24 *head;
int x;
int f;

int Fix(TreeNode24 *);

TreeNode24 *create(int , TreeNode24 *);
void insert_item(int , TreeNode24 *,TreeNode24 *, int);
void split(int , int *, TreeNode24 *,TreeNode24 *, TreeNode24 **, int );
Bool find_pos(int , TreeNode24 *, TreeNode24 **, int *);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     Nodes      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int STcount(){ return head->N;}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       Insert Items    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void STinsert(int item) {
  int index;
  TreeNode24 *progeny;
  
  if (find_pos(item, head, &progeny, &index)==1){ head = create(index, progeny);}
  Fix(head);  // Fix N
}

TreeNode24 *create(int item, TreeNode24 *progeny) {      // I make a new root
  TreeNode24 *Node;
  Node = (TreeNode24 *)malloc(sizeof(TreeNode24));
  Node->Counter = 1;                                  // I initialize the counter equal with one
  Node->link[0] = head;             
  Node->link[1] = progeny;
  Node->item[1] = item;
  return Node;
}

void insert_item(int item, TreeNode24 *n,TreeNode24 *progeny, int position) {
  int j;
  // I move all branches and elements to the right because i want to make room for new item.
  for(j=n->Counter; j> position; j--) {
    n->item[j + 1] = n->item[j];
    n->link[j + 1] = n->link[j];
  }
  //I insert the new item into a node
  n->item[position + 1] = item;
  n->link[position + 1] = progeny;
  n->Counter++;                // and i increase the counter because i insert new element 
}



void split(int item, int *index, TreeNode24 *node,TreeNode24 *progeny, TreeNode24 **newnode, int position) {
  int half, i;
  
  // I find where i split the full node 
  if (position > 2){ half = 3; }
  else{  half = 2; }

  *newnode = (TreeNode24 *)malloc(sizeof(TreeNode24));
  for (i=half+1; i <= 3; i++){    // i move half elements to the right node 
    (*newnode)->item[i - half] = node->item[i];
    (*newnode)->link[i - half] = node->link[i];
  }
  // I fix the counters 
  node->Counter = half;                
  (*newnode)->Counter = 3 - half;

  // I insert the new item in the right node 
  if (position > 2) { insert_item(item, *newnode, progeny, position - half);} 
  else { insert_item(item, node, progeny, position); } 
  
  *index = node->item[node->Counter];
  (*newnode)->link[0] = node->link[node->Counter];
  node->Counter--;
}

//I searching the position for new element
Bool find_pos(int item, TreeNode24 *node, TreeNode24 **progeny, int *index) {
  
  // I have empty tree 
  if (node==NULL) {
    *progeny = NULL;
    *index = item;
    return True;
  }

  int position;  
  
  if (item >= node->item[1]) { // i take the rightmost branch
  	for (position = node->Counter; (item < node->item[position] && position > 1 ); position--); // I search all elements into node
  	if (item == node->item[position]) { return False;}   //if item exist --> return false (zero)
  } 
  else { position = 0; } //i take the leftmost branch
  
  if (find_pos(item, node->link[position], progeny, index)==1) {
    if (node->Counter >= 3) { split(*index, index, node, *progeny, progeny, position);  return True;}  // overflow -->> split
	else { insert_item(*index, node, *progeny, position); }   // insert the element into current node
  }
  return False;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Search ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void search(int item, int *position, TreeNode24 *node) {  // i traverse the tree looking for item
  if (node==NULL) { return; }  // The tree is empty. There is not elements

  if (item < node->item[1]) { *position = 0;}
  else {
    for (*position = node->Counter; (item < node->item[*position] && *position > 1); (*position)--); // I search all elements into node
      
    if (item == node->item[*position]) { //if i found the element ->> print message, increase f (f is flag) and return
      printf("%d is found", item);
      f++;
      return;
    }
  }
  search(item, position, node->link[*position]);  // Search and the others nodes to find the element
 
  return;
}
void STsearch(int item){
	int i;
	f=0;
	search(item, &i, head);
	if(f==0){ printf("%d not found", item);   // fis flag if f is equal with zero ---> the elesement does not exist in the tree and print message
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Fix the Number of Nodes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int Fix(TreeNode24 *node){
	int i,j=0;
	node->N=0;
    if(node->link[0]==NULL){ node->N=1; return node->N;}   // if there are not other branches current node N is one AND return N
    else if(node->link[0]!=NULL){                          // if there are other branches
	    for (i = 0; i < node->Counter+1; i++) {
		j=Fix(node->link[i]);                            // i traverse all tree and i increase in the current node the N
        if(j!=1){ node->N=node->N+j;}                    
        else{ node->N=node->N+j; }
        }
		node->N=node->N+1;
		return  node->N;	
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Print the Tree ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void print(TreeNode24 *node) {
  int i;
  // Print all elements of the current node
  if (node!=NULL) {
    for (i = 1; i <= node->Counter; i++) {
    	printf("{item: %d} | {N: %d} | {count: %d} ",  node->item[i], node->N, node->Counter);  
	}
    printf("\n");
    for (i = 0; i < node->Counter+1; i++) {  print(node->link[i]); } // Traverse the others branches
  }
}
void inorder(TreeNode24 *node){
  int i;
  if (node!=NULL) {
    for (i = 0; i < node->Counter; i++) {
      inorder(node->link[i]);
      printf("%d ", node->item[i + 1]);
    }
    inorder(node->link[i]);
  }
}
void STprint(){

	print(head);
	
	printf("\n");
	printf("Inorder Traversal : ");
	inorder(head);
	printf("\n\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Find the i key  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void selectR(TreeNode24 *node, int k) {
  int i;
  if (node!=NULL) {
    for (i = 0; i < node->Counter; i++) {
    	selectR(node->link[i],k);
		if(x==k && f==0){  f=node->item[i+1];} // if x equal with k --> the key was found 
        x++;       // I increase the x because for the next item
	}
    selectR(node->link[i],k);   // i traverse the others branches
  }
}

int STselect(int k){
	x=0;  // x is the counter   
	f=0;  // f--> variable that i save the result
	selectR(head,k);  // selectR find the element
	return f;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Delete ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Copy(TreeNode24 *n, int i) {
  TreeNode24 *p;
  p = n->link[i];

  while(p->link[0] != NULL){ p = p->link[0];}
  n->item[i] = n->item[1];
}

void Remove_value(TreeNode24 *n, int p) {
	
  for(int i = p + 1; i <= n->Counter; i++) {
    n->item[i - 1] = n->item[i];
    n->link[i - 1] = n->link[i];
  }
  n->Counter--;
}

void left(TreeNode24 *node, int i)
{ TreeNode24 *n;
  int j;
 
  n=node->link[i-1];   // i move item from parent --> left node 
  n->Counter++;
  n->item[n->Counter]=node->item[i];
  n->link[n->Counter]=node->link[i]->link[0];
  
  n=node->link[i];  // i move item from right node --> parent 
  node->item[i]=n->item[1];
  n->link[0]=n->link[1];
  n->Counter--;
  
  for (j=1; j<=n->Counter; j++){ //i shift all elements in the right node one position left
    n->item[j]=n->item[j+1];
    n->link[j]=n->link[j+1];
  }
  return;
}
void right(TreeNode24 *node, int i){ 
  TreeNode24 *n;
  int j;

  n=node->link[i];
  for (j=n->Counter; j > 0; j--){ // shift all elements in the right node one position 
    n->item[j+1]=n->item[j];
    n->link[j+1]=n->link[j];
  }
  n->item[1]=node->item[i];
  n->link[1]=n->link[0];   // move item from parent to right node 
  n->Counter++;
  
  n=node->link[i-1];
  node->item[i]=n->item[n->Counter];
  node->link[i]=n->link[n->Counter];
  n->Counter--;
  return;
}
void fusionNodes(TreeNode24 *node, int i)
{
  int j;
  TreeNode24 *right;
  TreeNode24 *left;
  
  right=node->link[i];
  left=node->link[i-1];    // work with the left node 
  left->Counter++;                  //i insert the element from the parent 
  left->link[left->Counter]=right->link[0];
  left->item[left->Counter]=node->item[i];
  for (j=1; j<=right->Counter; j++){ //i insert all elements from right node 
    left->Counter++;
    left->item[left->Counter]=right->item[j];
    left->link[left->Counter]=right->link[j];
  }
  for (j=i; j < node->Counter; j++){  // delete item from parent node 
    node->item[j]=node->item[j+1];
    node->link[j]=node->link[j+1];
  }
  node->Counter--;
  free(right);           /* free right node */
}

void Store(TreeNode24 *node, int i) {
  if (i==0) {  // leftmost element
    if (node->link[1]->Counter > 2) { left(node, 1); }
	else {  fusionNodes(node, 1);}
  }
  else  if (i == node->Counter){   // rightmost element
		if (node->link[i-1]->Counter > 2){ right(node, i); }
        else{ fusionNodes(node, i); }
    }
  else if (node->link[i+1]->Counter > 2){ left(node, i+1); }
  else if (node->link[i-1]->Counter > 2){ right(node, i); }
  else{ fusionNodes(node, i); }
	
}

int Search_node(TreeNode24 *node, int item,  int *i){
  if (item < node->item[1]){  // i take the leftmost branch. If item < node->item ---->>>> position (i) equal with zero and return false (zero)
    *i=0;
    return 0;
  } 
  else {             
    for (*i=node->Counter; item < node->item[*i] && *i > 1; (*i)--);   // i do a sequential search through the elements 
    if(item == node->item[*i]){ return 1;}   // if i found the item in the current node -->>> return true (1) 
    else{ return 0; }   //else false (zero)
  }
}

void RemoveFromTheNode(int item, TreeNode24 *node){
  int i;          // location of branch and element on which to search 
  if (!node){ return; } // element was not in the tree
  else {
    if (Search_node(node, item , &i)==1){
      if (node->link[i-1]){
        Copy(node, i);  // replaces the right item -->> by its successor */
        RemoveFromTheNode(node->item[i], node->link[i]);
      } 
	  else{ Remove_value(node, i); }  // remove element from position i of current node
    }
    else{ RemoveFromTheNode(item, node->link[i]); }  // element was not found in the current node
    if (node->link[i]){
    	if (node->link[i]->Counter < 2){  Store(node, i);  }   // restore the minimum number and store in the right position
	}
  }
}


TreeNode24 *deleteR(TreeNode24 *node, int item){
  TreeNode24 *OldRoot;      // used if -->>> empty root 

  RemoveFromTheNode(item, head);
  if (node->Counter==0){    // head is empty 
    OldRoot=node;
    node=node->link[0];
    free(OldRoot);
  }
  return node;
}

void STdelete(int item){
	head=deleteR(head, item);
	Fix(head);    // i fix the N
}
