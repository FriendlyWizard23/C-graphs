/* basic directed graph type */
typedef struct graph *Graph;
/* create a new graph with n vertices labeled 0..n-1 and no edges */
Graph graph_create(int);
/* free all space used by graph */
void graph_destroy(Graph);
/* delete an edge from an existing graph */
void remove_edge(Graph,int,int);
/* add an edge with weight 0 to an existing graph */
void add_edge(Graph, int, int);
/* removes an edge from the list with source and sink*/
void remove_edge(Graph,int,int);
/* add an edge with weight to an existing graph */
void add_edge_weight(Graph,int,int,int);
/* return the number of vertices*/
int vertex_count(Graph);
/* return the number of edges */
int edge_count(Graph);
/* return the out degree (n of edges coming out from a vertex)of a vertex  */
int out_degree(Graph,int);
/* return true if a source has  an edge*/
int has_edge(Graph,int, int);
/* print graph */
void print_graph(Graph g);

