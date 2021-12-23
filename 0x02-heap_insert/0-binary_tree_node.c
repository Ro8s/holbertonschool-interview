#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node
 * @parent: Pointer to parent node
 * @value: Value to insert in the node
 *
 * Return: Pointer to the new node or NULL in fail
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
if (!new_node)
{
return (NULL);
}
new_node->left = NULL;
new_node->right = NULL;
new_node->parent = parent;
new_node->n = value;
return (new_node);
}
