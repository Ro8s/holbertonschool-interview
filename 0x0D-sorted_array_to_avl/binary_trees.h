#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/* INCLUDED LIBRARIES */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* STRUCTS AND DEFINITIONS */
/* Basic Binary Tree */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s* parent;
	struct binary_tree_s* left;
	struct binary_tree_s* right;
} binary_tree_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* FUNCTION PROTOTYPES */
/* function to print binary tree with formatting */
void binary_tree_print(const binary_tree_t*);

/* function to build AVL tree from sorted array */
avl_t* sorted_array_to_avl(int* array, size_t size);
/* function to add nodes to AVL tree from sorted array recursively */
int add_node_avl(int* array, size_t size, avl_t** tree, int add_left);
/* function to free AVL tree if malloc fails creating a later node */
void free_avl(avl_t** tree);

#endif /* _BINARY_TREES_H_ */