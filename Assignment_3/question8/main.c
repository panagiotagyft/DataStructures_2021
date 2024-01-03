#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

int main(void){
	int number_V, number_nodes, x, y, w, i=0, j, x1, y1, w1;
	char p;
	Graph* graph;
	ArraySort* mst;
	scanf("%d", &number_V);  // I save the first element --> the number of vertices
	undirected(&graph);      // I craete one graph
	graph=Initialize(graph, number_V);   // This function initialize the graph
	
	for(j=0; j < number_V*number_V; j++){
		scanf("%d", &x);
		scanf("%c", &p);
		scanf("%d", &y);
		scanf("%c", &p);
		scanf("%d", &w);
		i++;
		if(x1==x && y1==y && w1==w){ break;}	
		x1=x; y1=y; w1=w;	
		InsertEdge(graph, x, y, w);    // I insert the edge in the graph 
	}
	ShowGraph(graph);    // I print the graph  
	mst=MinimumSpanningTree(graph, i);   // This function returns the MinimumSpanningTree
	print_MST(mst, graph);    // This fuction print the MinimumSpanningTree
	return 0;
}
