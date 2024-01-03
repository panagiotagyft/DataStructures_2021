#ifndef  __ITEM_H__ 
#define __ITEM_H__ 
#define NULLitem NULL

typedef int Vertex;
typedef enum {FALSE, TRUE} Boolean;

typedef struct queue Queue;
typedef struct graph Graph;
typedef struct path pathways;
typedef struct edge Edge;

void undirected(Graph** );   // I craete one graph
Graph* Initialize(Graph* , int );   // This function initialize the graph
void InsertEdge(Graph* , int , int );  // I insert the edge in the graph 
void ShowGraph(Graph* );     // I print the graph  
int IsConnected(Graph *);    // This function return the number of subgraphs
int ConnectedComponents(Graph *); // The function ConnectedComponents returns the number of connected components
//...........................................
void InitializeQueue(Queue *, int );  // I initialize the queue
int Empty(Queue *);                 // if queue is empty return 1
void Insert(int , Queue *, int );   // This function insert element in the queue
void Remove(Queue *, int *, int );  // This function remove element from the queue
void PrintElement(Vertex );         // I use this function to print the elements
void BreadthFirst(Graph *, void (*Visit)(Vertex), int );   // i print bfs traversal
pathways **ShortestPaths(Graph *,int);             //The function  ShortestPaths return array in which the minimal paths are stored 
void printpaths(pathways** , Graph *);               // This fuction print the MinimumSpanningTree

#endif
