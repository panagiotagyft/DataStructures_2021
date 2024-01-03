#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

typedef struct STnode* link;

struct STnode { Item item; link l, r; int N; };
struct set{                    // I make a struct and i include head and dummy z
	link head;
	link z;
};

link NEW(Item item, link l, link r, int N)
  { link x = malloc(sizeof *x);
    x->item = item; x->l = l; x->r = r; x->N = N;
    return x;
  }

void STinit(Tree *t)
  { *t = malloc(sizeof(Tree));
     (*t)->head= ((*t)->z = NEW(NULLitem, NULL, NULL, 0)); }  // i initialize the empty tree with dummy node z (z is a NULL node)

int STcount(Tree t) {  return t->head->N; }  //return the number of nodes 

Item searchR(link h, Key v, link z)
  { Key t = key(h->item);               
    if (h == z) return NULLitem;   // if tree is null --> return -1 the key does not exist in the tree
    if eq(v, t) return h->item;    // if i found the key -->> i return the item
    if less(v, t) return searchR(h->l, v, z);  //if the key is smaller than the root key --> i give to the left branche the key
             else return searchR(h->r, v, z);  // else  i give to the right branche the key
  }

Item STsearch(Key v, Tree t)
  { return searchR(t->head, v, t->z); }

link insertR(link h, Item item, link z)
  { Key v = key(item), t = key(h->item);
    if (h == z) return NEW(item, z, z, 1); // if tree is null --> return a new node that contains the element
    if less(v, t)                       //if the key is smaller than the root key --> i give to the left branche the item  
         h->l = insertR(h->l, item, z);
    else h->r = insertR(h->r, item, z);  // else  i give to the right branche the item  
    (h->N)++; return h;       //increase the N
  }

Tree STinsert1(Item item, Tree t)
  { t->head = insertR(t->head, item, t->z); 
    return t;
  }

link rotR(link h) // makes the old root right subtree of the new root
  {   link x = h->l; h->l = x->r; x->r = h; 
    return x;
  }
link rotL(link h)  // makes the old root eft subtree of the new root
  { link x = h->r; h->r = x->l; x->l = h; 
    return x; }


/* code for inserting a key at the root of a BST */

link insertT(link h, Item item, link z) // insert the new node into the root of a tree. The new element inserted ino the root of the appropriate subtree
  { Key v = key(item);
    if (h == z) return NEW(item, z, z, 1);
    if (less(v, key(h->item)))
      { h->l = insertT(h->l, item, z); h = rotR(h); }
    else
      { h->r = insertT(h->r, item, z); h = rotL(h); }
    return h;
  }
int increase_N(link h, link z){ 
	int i, j;
	h->N=0;
	if (h == z){ return 0;}   // if the current node is empty i return ZERO
	i=increase_N(h->r, z);    // I traverse the right branches
	j=increase_N(h->l, z);    // I traverse the left branches
    h->N= i + j + 1;          // i add up the results of recursion calls and one because we count and the current node.
    return h->N;
}
Tree STinsert(Item item, Tree t){
    t->head= insertT(t->head, item, t->z); 
    increase_N(t->head, t->z);
    return t;
  }


/* code for finding the k-th smallest item in a BST */

Item selectR(link h, link z, int k)
  { int t = h->l->N;
    if (h == z) return NULLitem;   // if tree is null --> return -1 the key does not exist in the tree
    if (t > k) return selectR(h->l, z, k);   // if  t is bigger than key traverse the left branche
    if (t < k) return selectR(h->r,z, k-t-1);  //else traverse the right branche
    return h->item;
  }

Item STselect(int k, Tree t)
  { return selectR(t->head, t->z, k); }
 

/* code for partitioning a BST */

link partR(link h, int k)
  { int t = h->l->N;
    if (t > k )
      { h->l = partR(h->l, k); h = rotR(h); }
    if (t < k )
      { h->r = partR(h->r, k-t-1); h = rotL(h); }
   return h;
  }
  
/* code for deleting a key from a BST */

link joinLR(link a, link b, link z)  //the smaller node of the right subtree becomes root and then the left branche point to the lrft subtree
  {
    if (b == z) return a;
    b = partR(b, 0); b->l = a;
    return b;
  }

link deleteR(link h,link z, Key v)   // remove the first node with a key v that is found inside the tree. I traverse all the tree until found the node
  { link x; Key t = key(h->item);    //to be deleted 
    if (h == z) return z;
    if (less(v, t)) h->l = deleteR(h->l, z, v);
    if (less(t, v)) h->r = deleteR(h->r, z, v);
    if (eq(v, t))
      { x = h; h = joinLR(h->l, h->r, z); free(x); }  //combine  the two subtrees
    return h;
  }

Tree STdeleteAll(Key v, Tree t)
  { t->head = deleteR(t->head, t->z, v);
    increase_N(t->head, t->z);  // i fix N
    if (STsearch(v,t) != NULLitem){ //If there is more same elemnts -->> delete
    	STdeleteAll(v, t);
	}
	return t;
}


void print(link h,link z, int count){
	
    if (h == z){ return;} // If h is a NULL node -->> return
  
    count += 10;
  
    print(h->r, z, count);  // go to right child first
  
    printf("\n");
    for (int i = 10; i < count; i++){ printf(" "); }
    printf("{%3d %3d}\n",h->item, h->N); // i print the current node after space
  
    print(h->l, z, count); //go to left child
}
  
// Wrapper over print2DUtil()
void STprint(Tree t)
{
   // I initialise space counter equal with zero
   print(t->head,t->z, 0);
}


///* code for joining two BSTs */
//
//link STjoin(link a, link b)
//  {
//    if (b == z) return a;
//    if (a == z) return b;
//    b = STinsert(b, a->item);
//    b->l = STjoin(a->l, b->l);
//    b->r = STjoin(a->r, b->r);
//    free(a);
//    return b;
//  }

