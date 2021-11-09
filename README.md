# C-graphs
## purpose
This repository provides various simple implementations of graphs in C.
## why i did make it
I needed to use some graphs for a university project but i didn't find an easy-to-use library online so i decided to code my own.
I know that there is igraph (https://igraph.org/c/) but it was a little too much complex for my needs.
## some basic backgorund theory
Graphs are structures made of vertices and edges, and as far as we know from the Graph Theory these are some of the main ways they can be represented:
  1) Edge List = an edge list is a data structure used to represent a graph as a list of its edges. An (unweighted) edge is defined by its start and                    end vertex, so each edge may be represented by two numbers.
  2) Adjacency List = an adjacency list is a collection of unordered lists used to represent a finite graph. Each unordered list within an adjacency                         list describes the set of neighbors of a particular vertex in the graph.
  3) Adjacency Matrix = an adjacency matrix is a square matrix used to represent a finite graph. The elements of the matrix indicate whether pairs of                           vertices are adjacent or not in the graph.
  4) Incidence Matrix = an incidence matrix is a two-dimensional Boolean matrix, in which the rows represent the vertices and columns represent the                             edges. The entries indicate whether the vertex at a row is incident to the edge at a column. 

## how to use
As you can see there is no need of installation of any kind.
These are just libraries so you only need to use these files as such, clone them and import them in your code (as you can see in the example)
