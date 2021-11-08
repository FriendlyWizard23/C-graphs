/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// This library allows to create a DIRECTED graph using the adjcacency matrix technique                ////
//// an adjacency matrix is a square matrix used to represent a finite graph.                            ////
//// The elements of the matrix indicate whether pairs of vertices are adjacent or not in the graph.     ////
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

//////////////////////////////////////////////
/////////////////// STRUCTURES ///////////////
//////////////////////////////////////////////

typedef struct graph{
	int vertex_count;
	int edges_count;
	int **matrix;
	int **weight;
}*Graph;

///////////////////////////////////////////////
///////////////////////////////////////////////

Graph graph_create(int n){
	assert(n>0);
	Graph g=malloc(sizeof(struct graph));
	assert(g);
	g->vertex_count=n;
	g->edges_count=0;
	g->matrix=(int **)malloc(n * sizeof(int*));
	g->weight=(int **)malloc(n * sizeof(int*));
	for(int i=0;i<g->vertex_count;i++){
		g->matrix[i]=(int*)malloc(n*sizeof(int*));
		g->weight[i]=(int*)malloc(n*sizeof(int*));
		for(int j=0;j<g->vertex_count;j++){
			g->matrix[i][j]=0;
			g->weight[i][j]=0;
		}
	}
	return g;
}

void graph_destroy(Graph g){
	assert(g);
	free(g->matrix);
	free(g->weight);
	free(g);
}

int out_degree(Graph g, int source){
	assert(g);
	assert((source>=0)&&(source<g->vertex_count));
	int count=0;
	for(int j=0;j<g->vertex_count;j++){
		if(g->matrix[source][j]==1)
			++count;
	}
	return count;
}

void remove_edge(Graph g,int source,int sink){
	assert(g);
	assert((source>=0)&&(source<g->vertex_count));
	assert((sink>=0)&&(sink<g->vertex_count));
	if(has_edge(g,source,sink)){
		g->matrix[source][sink]=0;
		g->weight[source][sink]=0;
		g->edges_count--;
	}
}

/*
* adds the edge from source to sink.
* To turn this implementation into undirected you can
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
	assert((source>=0)&&(source<g->vertex_count));
	assert((sink>=0)&&(sink<g->vertex_count));
	if(has_edge(g,source,sink)==TRUE)return;
	g->matrix[source][sink]=1;
	g->weight[source][sink]=weight;
	++g->edges_count;
}

int has_edge(Graph g,int source, int sink){
	assert(g);
	assert((source>=0)&&(source<=g->vertex_count));
	assert((sink>=0)&&(sink<=g->vertex_count));
	return g->matrix[source][sink]==1;
}

int vertex_count(Graph g){
	assert(g);
	return g->vertex_count;
}

int edge_count(Graph g){
	assert(g);
	return g->edges_count;
}

void print_graph(Graph g){
	assert(g);
	for(int i=0;i<g->vertex_count;i++){
		if(i==0)
			printf("{%4s}","mat.");
		printf("{%4d}",i);
	}
	printf("\n");
	for(int i=0;i<g->vertex_count;i++){
		printf("{%4d}",i);
		for(int j=0;j<g->vertex_count;j++){
			printf("[%4d]",g->matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<g->vertex_count;i++){
		if(i==0)
			printf("{%4s}","wei.");
		printf("{%4d}",i);
	}
	printf("\n");
	for(int i=0;i<g->vertex_count;i++){
		printf("{%4d}",i);
		for(int j=0;j<g->vertex_count;j++){
			// modify this printf in case you wanted to print formatted large numbers
			printf("[%4d]",g->weight[i][j]);
		}
		printf("\n");
	}
}

