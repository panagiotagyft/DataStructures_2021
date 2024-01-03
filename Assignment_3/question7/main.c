#include <stdio.h>
#include "Interface.h"

int main(int argc, char *argv[]){
	int number_V, x, y, i, j, l;
	Graph* graph;
	FILE *fp;
    char p;
    
	if ((fp = fopen(argv[1], "rb")) == NULL){
		perror("fopen source-file");
		return 1;
	}
	
	fscanf(fp,"%d", &number_V);    // I save the first element --> the number of vertices
	
	undirected(&graph);        // I craete one graph
	graph=Initialize(graph, number_V);    // This function initialize the graph
    
	while (fscanf(fp,"%d",&x) != EOF) {
		fscanf(fp,"%c",&p);
		fscanf(fp,"%d",&y);
		InsertEdge(graph, x, y);
	}

	ShowGraph(graph);    // I print the graph  
	printf("BFS:   ");
	
	BreadthFirst(graph, PrintElement, 0);    // I print bfs cross 
	printf("\n\n");
	
	l=IsConnected(graph);   // This function return the number of subgraphs
	if(l==1){ printf("Connected Graph\n\n");}    // If l==1 -->> the graph is connected
	else{ printf("Disconnected Graph. Subgraphs: %d\n\n",l);}     // If l!=1 -->> the graph is not connected
	
	printf("ConnectedComponents:  %d\n\n",ConnectedComponents(graph));    // The function ConnectedComponents returns the number of connected components

	 ShortestPaths(graph,2); //---...   The function  ShortestPaths return array in which the minimal paths are stored 
	
	printpaths(ShortestPaths(graph,2), graph);    // I use printpaths function to print the shortest paths 
	printf("\n\n");
	fclose(fp);
	return 0;
}
