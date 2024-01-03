#ifndef  __ITEM_H__ 
#define __ITEM_H__ 
#define NULLitem NULL

typedef int Vertex;

typedef struct edge Edge;
typedef struct graph Graph;
typedef struct array_sort ArraySort;

void undirected(Graph** );  // I craete one graph
Graph* Initialize(Graph* , int );   // This function initialize the graph
void InsertEdge(Graph* , int , int , int);   // I insert the edge in the graph 
void ShowGraph(Graph* );             // I print the graph  
ArraySort* MinimumSpanningTree(Graph*, int);    // This function returns the MinimumSpanningTree
Vertex find(int , int* );                         //find returns the set which contained element
ArraySort * sort(Graph*, int , ArraySort *, int);   // This function -->> sorted all the edges in ascending order by weight
void Union(int , int , int *, int* );  // union ofthe sets containing x and y into a new set
void print_MST(ArraySort*, Graph*);    // This fuction print the MinimumSpanningTree

#endif
