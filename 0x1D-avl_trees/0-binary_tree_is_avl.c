#include "binary_trees.h"

/**
 * is_valid_avl - check
 * @tree: tree
 * @min: min
 * @max: max
 * @height: height
 * Return: 1 or 0
 */
int is_valid_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int h1 = 0, h2 = 0;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (is_valid_avl(tree->left, min, tree->n, &h1) == 0 ||
		is_valid_avl(tree->right, tree->n, max, &h2) == 0)
	return (0);

	*height = ((h1 > h2) ? h1 : h2) + 1;

	if (abs(h1 - h2) > 1)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - tree
 * @tree: tree
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h = 0;

	if (tree == NULL)
		return (0);

	return (is_valid_avl(tree, INT_MIN, INT_MAX, &h));
}
