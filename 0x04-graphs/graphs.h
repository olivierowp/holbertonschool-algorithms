#ifndef GRAPHS_H
#define GRAPHS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(X, Y) ((X) >= (Y) ? (X) : (Y))

/**
 * enum edge_type_e - Enumerates the different types of
 * connection between two vertices
 *
 * @UNIDIRECTIONAL: The connection is made only in one way
 * @BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_e
{
	UNIDIRECTIONAL = 0,
	BIDIRECTIONAL
} edge_type_t;

/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 */
typedef struct edge_s
{
	vertex_t *dest;
	struct edge_s *next;
} edge_t;

/**
 * struct vertex_s - Node in the linked list of vertices in the adjency list
 *
 * @index: Index of the vertex in the adjency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @nb_edges: Number of conenctions with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adgency linked list
 *   This pointer points to another vertex in the graph, but it
 *   doesn't stand for an edge between the two vertices
 */
struct vertex_s
{
	size_t index;
	char *content;
	size_t nb_edges;
	edge_t *edges;
	struct vertex_s *next;
};

/**
 * struct graph_s - Representation of a graph
 * We use an adjency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjency linked list
 */
typedef struct graph_s
{
	size_t nb_vertices;
	vertex_t *vertices;
} graph_t;

/* struct for BFS */
/**
 * struct queue_s - Element of a FIFO queue.
 * @vertex: pointer to the vertex stored here.
 * @depth: depth from this node to source node.
 * @next: pointer to next element.
 */
typedef struct queue_s
{
	vertex_t *vertex;
	size_t depth;
	struct queue_s *next;
} queue_t;

graph_t *graph_create(void);
vertex_t *graph_add_vertex(graph_t *graph, const char *str);
void graph_display(const graph_t *graph);
vertex_t *find_value(vertex_t *l_list, const char *value);
edge_t *vertex_add_edge(vertex_t *start, vertex_t *dest);
int graph_add_edge(graph_t *graph, const char *src,
				   const char *dest, edge_type_t type);
void free_vertex(vertex_t *vertex);
void graph_delete(graph_t *graph);
size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t depth));

size_t breadth_first_traverse(const graph_t *graph,
							  void (*action)(const vertex_t *v, size_t depth));

#endif /*__GRAPHS_H__*/
