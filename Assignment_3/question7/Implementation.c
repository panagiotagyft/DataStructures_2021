#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

struct edge{
	Vertex endpoint;
	struct edge *nextedge;
};

struct graph{
	int n;
	Edge **firstedge;
};

// I use this struct for queue
struct queue{
	int counter;
	int start;
	int finish;
	int elements[20];
};

// I use this struct to save the shortest paths
struct path{
	int x;
	int y;
	struct path *next;
};


void undirected(Graph** undirectedGraph){   // I create the undirected graph
	*undirectedGraph=malloc(sizeof(Graph*));  // I reserve memory for the graph
}

Graph* Initialize(Graph* graph_un, int n){   // I initialize the adjacency list weighted undirected graph
	int i;
	graph_un->n=n;
	graph_un->firstedge=malloc(n*sizeof(Edge*));    // I reserve memory for the vertices
	for(i=0; i < n; i++){
		graph_un->firstedge[i]=NULL;                // I initialize all vertices with NULL (NULL means that the vertices have no edges).
	}
	return graph_un;          // I return the undirected graph which consists only of the vertices and there are no edges in it.
}

void InsertEdge(Graph* graph_un, int x, int y){     // This function insert a new edge into a graph 
 	Edge* node;
 	Edge* n;
 	node=malloc(sizeof(Edge));           // I reserve memory for the edge
 	node->endpoint=y;                    // I set endpoint of edge equal with y (y--->end of edge)
 	if(graph_un->firstedge[x]==NULL){          // If vertex haven't edges -->> I insert the edge at start
 		node->nextedge=graph_un->firstedge[x];
 	    graph_un->firstedge[x]=node;
	}
	else{           // else i insert the edge at the end 
		n=graph_un->firstedge[x];       
		while(n->nextedge!=NULL){
			n=n->nextedge;
		}
		n->nextedge=node;
	}
 	//           ^^^^ 
	// I do this |||| process because i want to put the edges in ascending order

	// I also save edge y -->> x because my graph is undirected and i do the same process (now x=y and y=x)
    node=malloc(sizeof(Edge));               // I reserve memory for the edge
 	node->endpoint=x;                        // I set endpoint of edge equal with x (x--->end of edge)
 	if(graph_un->firstedge[y]==NULL){       // If vertex haven't edges -->> I insert the edge at start
 		node->nextedge=graph_un->firstedge[y];
 	    graph_un->firstedge[y]=node;
	}
	else{               // else i insert the edge at the end 
		n=graph_un->firstedge[y];
		while(n->nextedge!=NULL){
			n=n->nextedge;
		}
		n->nextedge=node;
	}
 }

void ShowGraph(Graph* graph_un){         // I print the  adjacency list representation
  int i; 
  Edge*  e;
  for (i = 0; i < graph_un->n; i++){    // for current vertex i print all edges
    e= graph_un->firstedge[i];
    printf("\n Vertex %d : ", i);
    while (e!=NULL) {
      printf("{ %d }-> ", e->endpoint);
      e = e->nextedge;
    }
    printf("\n\n");
  }
}

void PrintElement(Vertex x)
{
  printf("%4d  ", x);
}

void BreadthFirst(Graph *G, void (*Visit)(Vertex), int start)
{
  Queue Q;
  Boolean visited[G->n];
  Vertex v, w;
  Edge *curedge;

  for (v=0; v < G->n; v++){ visited[v]=FALSE;}            // I initialize all positions of array visited equal with FALSE.
  int count=0;           
  InitializeQueue(&Q, G->n);     // I initialize the QUEUE.
  
  for(v=0; v < G->n; v++){     // I check all vertices.
  	if(count==0){ v=start; count++;}   // if counter equal with one i initialize v equal with start vertex and i increase the count because i dont want the situation to be true again
  	if(!visited[v]){ 
	  Insert(v, &Q, G->n);       // Insert the vertex in the Queue.
  	  do {
        Remove(&Q, &v, G->n);    // I remove the first element of queue 
        if (!visited[v]){        // If current vertex has not visited 
           visited[v]=TRUE;      // I initialize position v in array visited equal with TRUE
           Visit(v);             // and i print the current vertex 
        }
        curedge=G->firstedge[v];  /* curedge is a pointer to the first edge (v,_) of V */
        while (curedge){
            w=curedge->endpoint;  /* w is a successor of v and (v,w) is the current edge */
            if (!visited[w]) Insert(w, &Q, G->n);
            curedge=curedge->nextedge;  /*curedge is a pointer to the next edge (v,_) of V */
        }
      } while (!Empty(&Q) );
    }
    if(v==G->n-1 && count==1 && visited[start]){ count++; v=-1;}       // if counter equal with one and v equal with the last vertex and i have visited the start vertex i start from 
   }                                                                   // the first node.
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Queue.
void InitializeQueue(Queue *queue, int n){
	int i;
	
	queue->counter=0;              // I initialize the counter equal with zero --->>> Empty queue
	queue->start=0;                // I initialize the first pointer --->> 0
	queue->finish=0;               // I initialize the last pointer --->> 0
}

int Empty(Queue *queue){
	return (queue->counter==0);     // If queue is empty return 1
}

void Insert(int item, Queue *queue, int n){
	queue->elements[queue->finish]=item;    // Insert the element in the right position 
	queue->finish=(queue->finish+1)%n;      // i make the last pointer  to point to the right position 
	++(queue->counter);                     // i increase the counter
}

void Remove(Queue *queue, int *item, int n){ 
	*item=queue->elements[queue->start];      // I remove the element from queue
	queue->start=(queue->start+1)%n;          // i make the last pointer  to point to the right position 
	--(queue->counter);                // i decrease the counter
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int IsConnected(Graph *G)
{
  int counter=0;
  Queue Q;
  Boolean visited[G->n];
  Vertex v, w;
  Edge *curedge;

  for (v=0; v < G->n; v++)   // I initialize all positions of array visited equal with FALSE.
    visited[v]=FALSE;

  InitializeQueue(&Q, G->n);   // I initialize the QUEUE.

  for (v=0; v < G->n; v++){      // I check all vertices.
    if (!visited[v]){
      Insert(v, &Q, G->n);      // Insert the vertex in the Queue.
      do {
         Remove(&Q, &v, G->n);   // I remove the first element of queue 
         if (!visited[v]){       // If current vertex has not visited 
           visited[v]=TRUE;      // I initialize position v in array visited equal with TRUE
         }
         curedge=G->firstedge[v];  // curedge is a pointer to the first edge (v,_) of V 
         while (curedge!=NULL){
            w=curedge->endpoint;  // w is a successor of v and (v,w) is the current edge 
            if (!visited[w]) { Insert(w, &Q, G->n); }
            curedge=curedge->nextedge;  // curedge is a pointer to the next edge (v,_) of V 
         }
      } while (!Empty(&Q));
      counter++; 	   //counter subgraph  --->>> if counter > 1 the edges is not connected.    
    }
   }
   return counter;   // If i cross all vertices i return the counter.
}

int ConnectedComponents(Graph *G)
{
  int counter=0;
  Queue Q;
  Boolean visited[G->n];
  int check[G->n][G->n];
  Vertex v, w, i;
  Edge *curedge;

  for (v=0; v < G->n; v++){         
  	 for (i=0; i < G->n; i++){ check[v][i]=-1; }    // I make this array to store the edges. 
  }
  for (v=0; v < G->n; v++)          // I initialize all positions of array visited equal with FALSE.
    visited[v]=FALSE;

  InitializeQueue(&Q, G->n);       // I initialize the QUEUE.

  for (v=0; v < G->n; v++){        // I check all vertices.
    if (!visited[v]){
      Insert(v, &Q, G->n);         // Insert the vertex in the Queue.
      do {
         Remove(&Q, &v, G->n);     // I remove the first element of queue 
         if (!visited[v]){         // If current vertex has not visited 
           visited[v]=TRUE;        // I initialize position v in array visited equal with TRUE --->>> i visited this vertex and i set the position equal with TRUE.
         }
         curedge=G->firstedge[v];  // curedge is a pointer to the first edge (v,_) of V 
         while (curedge!=NULL){
            w=curedge->endpoint;  // w is a successor of v and (v,w) is the current edge */
            check[v][w]=1;         // I set the position [v][w] equal with one ,the position [v][w] is the edge of graph. 
            if (!visited[w]) Insert(w, &Q, G->n);  // If cuurent vertec has not visited -->> insert the vertex in the queue.
            curedge=curedge->nextedge;  //curedge is a pointer to the next edge (v,_) of V 
         }
      } while (!Empty(&Q));
      
    }
   }

   for (v=0; v < G->n; v++){
  	  for (i=0; i < G->n; i++){
  	 	if(check[v][i]==1){
  	 		counter++;   // I count the edges.
  	 		if(check[i][v]==1){ check[i][v]=-1;}   // If i have saved the same edge 2 times i find the second edge and i set the position equal with -1.
		}
	  }
   }
   return counter;
}

void paths_sub(Graph *G, int n,int ** array, int l){
  Queue Q;
  Boolean visited[n];
  Vertex v, w;
  Edge *curedge;
  int i,j, ok=0;
  // I initialize all positions of array equal with -1 
  for(i=0; i<l; i++){
  	for(j=0; j<n; j++ ){
  		array[i][j]=-1;
	  }
  }
  i=0; j=0;
  for (v=0; v < G->n; v++)
    visited[v]=FALSE;                  // I initialize all positions of array visited equal with FALSE

  InitializeQueue(&Q, n);      // I initialize the QUEUE
  
  for (v=0; v < G->n; v++){
    if (!visited[v]){
    	j=0; 
    	array[i][j]=v;     // i save the element. position i and j=0.This element is the parent vertex
    	j++;
      Insert(v, &Q, n);    // Insert the vertex in the Queue.
      do {
         Remove(&Q, &v, n);   // I remove the first element from queue 
         if (!visited[v]){    // If current vertex has not visited
           visited[v]=TRUE;
         }
         curedge=G->firstedge[v];  /* curedge is a pointer to the first edge (v,_) of V */
         while (curedge!=NULL){
            w=curedge->endpoint;  /* w is a successor of v and (v,w) is the current edge */
            if (!visited[w]) {
            	Insert(w, &Q, n);   // If current vertex has not visited -->> insert the vertex in the Queue.
  	                for(int l=0; l<n; l++ ){   // I check if current element is stored in the array
  		             if( array[i][l]==w){ok=1;}  // if urrent element is stored in the array i have the flag ok and i set ok equal with 1 
	                }
                
                if(ok==0){         // if urrent element is  not stored in the array 
                	array[i][j]=w; // i save the element
                	j++;
				}
				ok=0;
			}
            curedge=curedge->nextedge;  //curedge is a pointer to the next edge of v
         }
      } while (!Empty(&Q));
      i++;    
    }
   }

}
pathways **ShortestPaths(Graph *G,int StartVertex){ 
  pathways **paths;
  pathways* node;
  Queue Q;
  Boolean visited[G->n];
  Vertex v, w;
  Edge *curedge;
  int s[G->n];
  int i, x, end, t,u,count=0, flag, l;
  int **array;
  l=IsConnected(G);
  array=malloc(l * sizeof(int *));
  for (i = 0 ; i < l ; i++) {
    array[i] = malloc(G->n * sizeof(int));
  }
  paths_sub(G,G->n, array,l);
  
  // i check where it is the start vertex 
  for(t=0; t < l; t++){
  	for(u=0; u < G->n; u++){
  		if(StartVertex==array[t][u]){count++; break;}  //I check where is the position of start vertex in the array.
	  }
	  if(count!=0){break;}
  }
  
  paths=malloc((G->n)*sizeof(pathways*));
  for(int K=0; K< G->n; K++){  paths[K]=NULL; }   // i initialize all positions of paths
  
  for (end=0; end < G->n; end++){  // i cross all vertices
  	if(end==StartVertex ){          // if end vertex is the start vertex 
	  	node=malloc(sizeof(pathways*));    // in the current position of array paths 
	  	node->x=-1;                     // i set x and y equal with -1 ...-1 is flag for i print the right message
	  	node->y=-1;
	  	node->next=paths[end];
	  	paths[end]=node;
	    continue;                 // and i continue to the next end vertex
		}
  	for(u=0; u < G->n; u++){       //I check if current end vertex is exists in the graph or current subgraph
  		if(array[t][u]==end){ flag=1; break;}  // if it exists in the graph i have flag and i set the flag equal with 1
	  }
	  if(flag==0){    // if end vertex does not exist in the graph 
	  	node=malloc(sizeof(pathways*));  // in the current position of array paths 
	  	node->x=-2;                      // i set x and y equal with -2 ...-2 is flag for i print the right message
	  	node->y=-2;
	  	node->next=paths[end];
	  	paths[end]=node;
	    continue;       // and i continue to the next end vertex
	  }
    for (v=0; v < G->n; v++){ visited[v]=FALSE; }    // I initialize all positions of array visited equal with FALSE --->> ALL vertices have noy visited
    for(i=0;i< G->n; i++){ s[i]=-1; }                 // I initialize all positions of array s equal with -1 --->>s is the parent array
    
    InitializeQueue(&Q,G->n);     // I initialize the QUEUE
    Insert(StartVertex, &Q, G->n);   // Insert the StartVertex in the Queue.
    visited[StartVertex]=FALSE;      // and i initialize the StartVertex equal with FALSE

    do {
        Remove(&Q, &v,G->n);    // I remove the first element from queue 
        if (!visited[v]){       // If current vertex has not visited
          visited[v]=TRUE;       // I initialize position v in array visited equal with TRUE -->>> i visited this vertex and i set the position TRUE
	    }
       
	    curedge=G->firstedge[v];  // curedge is a pointer to the first edge  of v 
        while (curedge){
        	w=curedge->endpoint;  // w is a successor of v and (v,w) is the current edge 
            if (!visited[w]){
            	Insert(w, &Q, G->n);
            	if(s[w]==-1){ s[w]=v; }   // I save the parent v and the chlid --->>> i saved the edge (x,y) or (v,w)
			}
            curedge=curedge->nextedge;  //curedge is a pointer to the next edge of v
         }
      } while (!Empty(&Q) );

	  x=end;
	  
	  while(s[x]!=StartVertex){   // while the parent is not equal with start vertex
	  	node=malloc(sizeof(pathways*));   // I save the all edges in the current position of paths  
	  	node->x=s[x];           // i save the start " parent "
	  	node->y=x;              // and the end 
	  	node->next=paths[end];
	  	paths[end]=node;
	  	x=s[x];
	  }
	  node=malloc(sizeof(pathways*));
	  node->x=s[x];
	  node->y=x;
	  node->next=paths[end];
	  paths[end]=node;

	  flag=0;   // i initialize the flag
  }
 
  for (i = 0 ; i < l ; i++) {
  	free(array[i]);
  } 
  free(array);
 return paths;
}

void printpaths(pathways** paths, Graph *G ){
	int i;
	pathways* n;
	for(i=0; i< G->n; i++){
	  n=paths[i];
	  printf("Shortest Path from 2 to vertex %d:   ", i);
	  while(n!=NULL){
	  	if(n->x==-1 && n->y==-1){ printf("The end and the start vertex is the same and the length of the path is 0  ");}
	  	else if(n->x==-2 && n->y==-2){ printf("Disconnected graph.The vertex %d is not included in subgraph which i search ", i);}
	  	else{ printf("{ %3d %3d }-->>",n->x, n->y);}
	  	n=n->next;
	  }
	  printf("\n\n");	
	}
}

