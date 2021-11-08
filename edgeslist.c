/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// This library allows to create a DIRECTED graph using the edges list technique                       ////
//// An edge list is a list or array of all the edges in a graph.                                        ////
//// The underlying data structure is a single list of pairs (first Vertex and second vertex)            ////
//// non oriented graphs are not supported by this implementation but since non oriented graphs          ////
//// are a subset of directed graphs it is possible to use it for undirected graphs as well.             ////
//// Methods description is defined inside graph.h Further information is added in each method if needed ////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "graph.h"
#define TRUE 1
#define FALSE 0

///////////////////////////////////////////////////////
////////////////// STRUCTURES /////////////////////////
///////////////////////////////////////////////////////
typedef struct edge{
	int fv; 	//first vertex
	int sv; 	//second vertex
	int weight; 	//weight of the edge
}*Edge;

typedef struct graph{
	int vertex_count;
	int edges_count;
	Edge *edges;
}*Graph;

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

/*
* Number of vertices is IMMUTABLE
*/
Graph graph_create(int n){
	assert(n>0);
	Graph g=malloc(sizeof(struct graph));
	assert(g);
	g->vertex_count=n;
	g->edges_count=0;
}

void graph_destroy(Graph g){
	assert(g);
	assert(g->edges);
	Edge cur=g->edges[0];
	Edge tofree;
	for (int i=0;i<(g->vertex_count)-1;i++){
		tofree=cur;
		cur=g->edges[i+1];
		free(tofree);
	}
	free(g);
}

int out_degree(Graph g,int source){
	assert(g);
	assert(g->edges);
	assert((source<g->vertex_count)&&(source>=0));
	int count=0;
	for(int i=0;i<g->edges_count;i++){
		if(g->edges[i]->fv==source)
			count++;
	}
	return count;
}

void remove_edge(Graph g,int source,int sink){
	assert(g);
	assert((source<g->vertex_count)&&(source>=0));
	assert((sink<g->vertex_count)&&(source>=0)&&(sink!=source));
	//If the edge to eliminate is in the last position of the edges array simply free it
	if((g->edges[g->edges_count-1]->fv==source)&&(g->edges[g->edges_count-1]->sv==sink)){
		free(g->edges[g->edges_count-1]);
		--g->edges_count;
		return;
	}
	//If the edge to eliminate is in the first or middle position of the edges
	//then a process of compression is needed
	for(int i=0;i<g->edges_count;i++){
		if((g->edges[i]->fv==source)&&(g->edges[i]->sv==sink)){
			for(int j=i;j<g->edges_count-1;j++){
				g->edges[j]->fv=g->edges[j+1]->fv;
				g->edges[j]->sv=g->edges[j+1]->sv;
			}
			free(g->edges[--g->edges_count]);
			return;
		}
	}
}

/*
* adds the edge from source to sink.
* To turn this implementation into Undirected you can
* either add some lines of code or call two times this method
* exchanging source and sink during the second call
*/

/*
* a non-weighted edge is just an edge with 0 weight
*/
void add_edge(Graph g,int source,int sink){
	add_edge_weight(g,source,sink,0);
}

void add_edge_weight(Graph g,int source,int sink,int weight){
	assert(g);
	assert((source<g->vertex_count)&&(source>=0));
	assert((sink<g->vertex_count)&&(source>=0)&&(sink!=source));
	if(has_edge(g,source,sink))return;
	g->edges=realloc(g->edges,(g->edges_count+1)*sizeof(struct edge));
	assert(g);
	g->edges[g->edges_count]=malloc(sizeof(struct edge));
	g->edges[g->edges_count]->fv=source;
	g->edges[g->edges_count]->sv=sink;
	g->edges[g->edges_count]->weight=weight;
	g->edges_count+=1;
}

int has_edge(Graph g,int source, int sink){
	assert(g);
	assert((source<g->vertex_count)&&(source>=0));
	assert((sink<g->vertex_count)&&(source>=0)&&(sink!=source));
	for(int i=0;i<g->edges_count;i++){
		if(g->edges[i]->fv==source && g->edges[i]->sv==sink)
			return TRUE;
	}
	return FALSE;
}

int vertex_count(Graph g){
	assert(g);
	return g->vertex_count;
}

int edge_count(Graph g){
	assert(g);
	return g->edges_count;
}

/*
* abstraction function of the graph
*/
void print_graph(Graph g){
	assert(g);
	for(int i=0;i<g->edges_count;i++){
		printf("{[%d-%d](%d)}\n",g->edges[i]->fv,g->edges[i]->sv,g->edges[i]->weight);
	}
}
