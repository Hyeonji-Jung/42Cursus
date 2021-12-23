#include "push_swap.h"

t_node	*get_new_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->val = num;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	init_stack(t_var *var)
{
	var->A = malloc(sizeof(t_stack));
	var->B = malloc(sizeof(t_stack));
	var->A->top = get_new_node(0);
	var->A->bottom = get_new_node(0);
	var->A->top->right = var->A->bottom;
	var->A->bottom->left = var->A->top;
	var->B->top = get_new_node(0);
	var->B->bottom = get_new_node(0);
	var->B->top->right = var->B->bottom;
	var->B->bottom->left = var->B->top;
}

void	push_top(t_stack *stack, t_node *new_node)
{
	t_node	*top;
	t_node	*temp;

	top = stack->top;
	temp = top->right;
	top->right = new_node;
	temp->left = new_node;
	new_node->left = top;
	new_node->right = temp;
}

void	push_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*bottom;
	t_node	*temp;

	bottom = stack->bottom;
	temp = bottom->left;
	bottom->left = new_node;
	temp->right = new_node;
	new_node->left = temp;
	new_node->right = bottom;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*top;
	t_node	*temp;

	top = stack->top;
	if (top->right == stack->bottom)
		return (0);
	temp = top->right;
	temp->right->left = top;
	top->right = temp->right;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}
