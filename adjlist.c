////////////////////////////////////////////////////////////////////////////////////////////////////
//// This library allows to create a DIRECTED graph using the adjacency list technique          ////
//// An adjacency list is a collection of unordered lists used to represent a finite graph.     ////
//// non oriented graphs are not supported by this implementation but since non oriented graphs ////
//// are a subset of directed graphs it is possible to use it for undirected graphs as well.    ////
//// Methods description is inside graph.h Furhter information added in each method if needed   ////
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <assert.h>
#define TRUE 1
#define FALSE 0

////////////////////////////////////////////////
////////////// STRUCTURES //////////////////////
////////////////////////////////////////////////

struct node{
	int vertex;
	int weight;
	struct node* next;
};

typedef struct graph{
	int vertex_count;
	int edges_count;
	struct node **list;
}*Graph;
////////////////////////////////////////////////

/*
* IMPORTANT: The number of vertices of the graph is immutable.
*/
Graph graph_create(int n){
	Graph g=malloc(sizeof(struct graph));
	assert(g);
	g->edges_count=0;
	g->vertex_count=n;
	g->list=calloc(n,sizeof(struct node *));
	assert(g->list);
	return g;
}

void graph_destroy(Graph g){
	assert(g);
	struct node* tmp=g->list[0];
	struct node* tofree;
	while(tmp){
		tofree=tmp;
		tmp=tmp->next;
		free(tofree);
	}
	free(g);
}

static struct node* createNode(int val){
	struct node* nn=malloc(sizeof(struct node));
	assert(nn);
	nn->vertex=val;
	nn->next=NULL;
	return nn;
}

int out_degree(Graph g,int source){
	assert(g);
	assert(source<=g->vertex_count);
	struct node* tmp=g->list[source];
	int outc=0;
	while(tmp){
		outc++;
		tmp=tmp->next;
	}
	return outc;
}

/*
* adds the edge from source to sink.
* To make this implementation Undirected you can
* either add some lines of code or call two times this method
* exchange source and sink during the second invocation
*/
void add_edge(Graph g,int source, int sink){
	add_edge_weight(g,source,sink,0);
}

void add_edge_weight(Graph g,int source,int sink, int weight){
	assert(source<=g->vertex_count);
	assert(sink<=g->vertex_count);
	assert(sink!=source);
	if(has_edge(g,source,sink))return;
	struct node* nn=createNode(sink);
	nn->next=g->list[source];
	nn->weight=weight;
	g->list[source]=nn;
	g->edges_count++;
}

/*
* this method has the same mechanism of a linked-list (which it is)
*/
void remove_edge(Graph g,int source,int sink){
	assert(g);
	assert((source<g->vertex_count)&&(source>=0));
	assert((sink<g->vertex_count)&&(sink>=0));
	assert(sink!=source);
	struct node* tmp=g->list[source];
	if(tmp==NULL)
		return;
	if(tmp->vertex==sink){
		g->list[source]=tmp->next;
		g->edges_count--;
	}
	else{
		struct node* prev=tmp;
		tmp=tmp->next;
		while(tmp){
			if(tmp->vertex==sink){
				prev=tmp->next;
				free(tmp);
				--g->edges_count;
				break;
			}
			tmp=tmp->next;
		}
	}
}
int has_edge(Graph g, int source, int sink){
	assert(g);
	assert((source>=0)&&(source<=g->vertex_count));
	assert((sink>=0)&&(sink<=g->vertex_count));
	struct node* tmp;
	tmp=g->list[source];
	while(tmp){
		if(tmp->vertex==sink)
			return TRUE;
	tmp=tmp->next;
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
* abstraction function of the graph.
*/
void print_graph(Graph g){
	assert(g);
	struct node* tmp;
	for(int i=0;i<g->vertex_count;i++){
		tmp=g->list[i];
		printf("V[%d]->{",i);
		while(tmp){
			printf("[%d(%d)], ",tmp->vertex,tmp->weight);
			tmp=tmp->next;
		}
		printf("}\n");
	}
}
