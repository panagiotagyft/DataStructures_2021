#include "sort_Types.h"

void PrintList(NodeType *);         //print list
void insert_at_start(Item , NodeType **);  // Insert node at START of list
int add_node( int ,int, NodeType **);      // I add the nodes
NodeType* ListSort(NodeType *);            // I sort the list
int delete_node(int, NodeType **);         // Delete node
int previous(int , NodeType *);            // Find the previous node
NodeType * check(NodeType *);              // Check which node needs to be sorted
int max(NodePointer, Item);                // Find max element
int min(NodeType *, Item);                 // Find min element
void InsertNewLastNode(int , NodeType **); // Insert node at the END of list
