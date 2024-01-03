#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

struct edge{
	Vertex endpoint;
	int weight;
	struct edge *nextedge;
};

struct graph{
	int n;
	Edge **firstedge;
};

// I use this struct for sorted 
struct array_sort{
  int weight;
  int x;
  int y;
};

void undirected(Graph** undirectedGraph){  // I create the undirected graph
	*undirectedGraph=malloc(sizeof(Graph*));   // I reserve memory for the graph
}

Graph* Initialize(Graph* graph_un, int n){ // I initialize the adjacency list weighted undirected graph
	int i;                                      
	graph_un->n=n;
	graph_un->firstedge=malloc(n*sizeof(Edge*));  // I reserve memory for the vertices
	for(i=0; i < n; i++){
		graph_un->firstedge[i]=NULL;   // I initialize all vertices with NULL (NULL means that the vertices have no edges).
	}                                  
	return graph_un;                   // I return the undirected graph which consists only of the vertices and there are no edges in it.
}

void InsertEdge(Graph* graph_un, int x, int y, int w){   // This function insert a new edge into a graph 
 	Edge* node;
 	Edge* n;   
 	node=malloc(sizeof(Edge));       // I reserve memory for the edge
 	node->endpoint=y;                // I set endpoint of edge equal with y (y--->end of edge)
 	node->weight=w;                  // I set weight of edge equal with w
 	if(graph_un->firstedge[x]==NULL){    // If vertex haven't edges -->> I insert the edge at start
 		node->nextedge=graph_un->firstedge[x];  
 	    graph_un->firstedge[x]=node;            
	}
	else{                   // else i insert the edge at the end 
		n=graph_un->firstedge[x];
		while(n->nextedge!=NULL){
			n=n->nextedge;
		}
		n->nextedge=node;
	}
 	//           ^^^^ 
	// I do this |||| process because i want to put the edges in ascending order

	// I also save edge y -->> x because my graph is undirected and i do the same process (now x=y and y=x)
    node=malloc(sizeof(Edge));    // I reserve memory for the edge
 	node->endpoint=x;             // I set endpoint of edge equal with x (x--->end of edge)
 	node->weight=w;               // I set weight of edge equal with w
 	if(graph_un->firstedge[y]==NULL){      // If vertex haven't edges -->> I insert the edge at start
 		node->nextedge=graph_un->firstedge[y];
 	    graph_un->firstedge[y]=node;
	}
	else{            // else i insert the edge at the end 
		n=graph_un->firstedge[y];
		while(n->nextedge!=NULL){
			n=n->nextedge;
		}
		n->nextedge=node;
	}
 }

void ShowGraph(Graph* graph_un){   // I print the  adjacency list representation
  int i;
  Edge*  e;
  for (i = 0; i < graph_un->n; i++){  
    e= graph_un->firstedge[i];       // for current vertex i print all edges
    printf("\n Vertex %d\n ", i);
    while (e!=NULL) {                  // i print all edges 
      printf("{ %d  %d }-> ", e->endpoint, e->weight);
      e = e->nextedge;
    }
    printf("\n");
  }
}

ArraySort* MinimumSpanningTree(Graph* graph, int e){
	int counter=0; 
	int i, j, x, y;
	int parent[graph->n];                    
	int size[graph->n];
	ArraySort *l, *route_MST;
	ArraySort current_edge;
	l=sort(graph, graph->n, l, e);     // I sort all the edges in ascending order by weight

	route_MST=malloc(e*sizeof(ArraySort));   // I create a dynamic array which i will save the path

	for(i=0; i < graph->n; i++){
		parent[i]=i;                 // I initialize the parent and the size of tree equall with the current i and zero 
		size[i]=0;                   // I save the rank of trees
	}

	j=0;
	while(counter != graph->n-1){
		current_edge=l[j];
		x=find(current_edge.x, parent); // find returns the set which contained in x
		y=find(current_edge.y, parent); // find returns the set which contained in y

		if(x!=y){
			route_MST[counter]=current_edge;
			counter++;
			Union(x, y , parent, size);   // union ofthe sets containing x and y into a new set
		}
		j++;
	}

	return route_MST;
}

void Union(int x, int y, int *parent, int* size){
	x=find(x,parent);   // find returns the set which contained in x
	y=find(y,parent);   // find returns the set which contained in y
    
	if(size[x] > size[y]){     // i merge the bigger tree below the small one 
		parent[y]=x;    
	}
	else if(size[x] < size[y]){  // i merge the smaller tree below the large one 
		parent[x]=y;
	}
	else{     // if x equal y i set parent[y] equal x and i increase the rank of tree x
		parent[y]=x;
		size[x]=size[x]+1;
	}
}
Vertex find(int vertex, int* parent){
	if(parent[vertex]==vertex){ return vertex;}
	return find(parent[vertex], parent);
}

ArraySort * sort(Graph* graph, int n, ArraySort *l, int e){
	int i, j, k=0,m=0;
	
	l=malloc(e*sizeof(ArraySort));  // I reserve a dynamic array with size equal with num of edges
	
	for(i=0; i < e ; i++){   // I initialize the array equal with -1
		l[i].x=-1;
		l[i].y=-1;
		l[i].weight=-1;
	}
	for(i=0; i< graph->n; i++){    
		while(graph->firstedge[i]!=NULL){
			for(j=0; j < e; j++){                                            // I check if i save into the l the same edge.Because the graph is undirected i save the same edge 2 
				if(l[j].x==graph->firstedge[i]->endpoint && l[j].y==i){k=1;} // times in the adjacency list. First (x,y) and second (y,x). IF i save into the l the edge i have a flag 
			}	                                                             // flag --> k and i set k equal with 1,which means -->> yes this edge has been saved
			                                                                  
			if(k!=1){  // If current edge has not been saved 
				if(l[0].weight==-1){    // If l is empty --->> i insert the edge in the first position
					l[0].weight=graph->firstedge[i]->weight;  
				    l[0].y=graph->firstedge[i]->endpoint;
				    l[0].x=i;
			    }
			    else{
			    	for(j=0; j < e; j++){
			    		
			    		if(l[j].weight > graph->firstedge[i]->weight){   // If the weight of the current position is bigger than weight of edge wich i want to insert in the l
			    			for(k=e-1; k > j; k--){                      // I move all elements one position down.If element m is in the position 3 i move it to the position 4
			    				l[k].weight=l[k-1].weight;
			    				l[k].x=l[k-1].x;
			    				l[k].y=l[k-1].y;
							}
			    			l[j].weight=graph->firstedge[i]->weight;   // I insert the element in the current position j of array l
			    			l[j].x=i;
			    			l[j].y=graph->firstedge[i]->endpoint;
			    		    m=1;                    // And i set m equal with 1.m is a flag and 1 means that the current element inserted
			    		    break;                  // and i stop the procedure
						}
						if(l[j].weight==-1 && m==0){  // If current element is not inserted and the current position of l is equal with -1 ---> insert the element
							l[j].weight=graph->firstedge[i]->weight;
				            l[j].y=graph->firstedge[i]->endpoint;
				            l[j].x=i;
				            break;   // I stop the procedure
						}
					}
				}
			}
			k=0; m=0;   // I initialize the flags k and m equal with ZERO
			graph->firstedge[i]=graph->firstedge[i]->nextedge; // I check the next edge
		}
	}
	return l;    // Finally i return the array l
}

void print_MST(ArraySort* MST, Graph* graph){
	int i, cost=0;
	printf("\n\n");
	printf("The minimum weight spanning tree :\n");
	for(i=0; i < graph->n ; i++){
		if(MST[i].x==0 && MST[i].y==0 && MST[i].weight==0){ continue; }
		printf("edge(%2d , %2d)=%2d(weight)\n",MST[i].x, MST[i].y, MST[i].weight);
		cost+=MST[i].weight;
	}
	printf("\n\n");
	printf("Minimum cost: %d\n", cost);
}
