/* basic directed graph type */
typedef struct graph *Graph;
/* create a new graph with n vertices labeled 0..n-1 and no edges */
Graph graph_create(int n);
/* free all space used by graph */
void graph_destroy(Graph);
/* delete an edge from an existing graph */
void delete_edge(Graph,int source,int sink)
/* add an edge with weight 0 to an existing graph */
void add_edge(Graph, int source, int sink);
/* add an edge with weight to an existing graph */
void add_edge_weight(Graph,int source,int sink,int weight);
/* return the number of vertices*/
int vertex_count(Graph);
/* return the number of edges */
int edge_count(Graph);
/* return the out degree (n of edges coming out from a vertex)of a vertex  */
int out_degree(Graph g,int source);
/* return true if a source has  an edge*/
int has_edge(Graph g,int source, int sink);
/* print graph */
void print_graph(Graph g);

