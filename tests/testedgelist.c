#include <stdio.h>
#include "../edgeslist.c"

int main(){
	Graph g=graph_create(10);
	add_edge(g,9,2);
	add_edge(g,2,9);
	add_edge(g,1,9);
	add_edge(g,1,0);
	print_graph(g);
	printf("OUT DEGREE OF VERTEX 2: %d\n",out_degree(g,2));
	printf("NUMBER OF EDGES: %d\n",edge_count(g));
	printf("NUMBER OF VERTICES: %d\n",vertex_count(g));
	printf("Graph has edge 2-9?: %d\n",has_edge(g,2,9));
	remove_edge(g,2,9);
	printf("DELETING EDGE 2-9..\n");
	remove_edge(g,1,0);
	printf("DELETING EDGE 1-0..\n");
	remove_edge(g,9,2);
	remove_edge(g,9,2);
	printf("DELETING EDGE 9-2 2 times..\n");
	print_graph(g);
	printf("NUMBER OF EDGES NOW: %d\n",edge_count(g));
	printf("TRYING TO ADD 2 IDENTICAL EDGES...\n");
	add_edge(g,4,6);
	add_edge(g,4,6);
	printf("NUMBER OF EDGES NOW: %d\n",edge_count(g));
}
