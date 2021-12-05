#include "push_swap.h"

t_node	*getNewNode(int num)
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

void	initStack(t_var *var)
{
	var->A = malloc(sizeof(t_stack));
	var->B = malloc(sizeof(t_stack));
	var->A->top = getNewNode(0);
	var->A->bottom = getNewNode(0);
	var->A->top->right = var->A->bottom;
	var->A->bottom->left = var->A->top;
	var->B->top = getNewNode(0);
	var->B->bottom = getNewNode(0);
	var->B->top->right = var->B->bottom;
	var->B->bottom->left = var->B->top;
}

void	pushTop(t_stack *stack, t_node *new_node)
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

void	pushBottom(t_stack *stack, t_node *new_node)
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

t_node	*popTop(t_stack *stack)
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

t_node	*popBottom(t_stack *stack)
{
	t_node	*bottom;
	t_node	*temp;

	bottom = stack->bottom;
	if (bottom->left == stack->top)
		return (0);
	temp = bottom->left;
	temp->left->right = bottom;
	bottom->left = temp->left;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}

void	printStack_test(t_stack *stack) ////////////// please erase!
{
	t_node	*p;

	printf("TOP:   ");
	p = stack->top->right;
	while (p != stack->bottom)
	{
		printf("%d ", p->val);
		p = p->right;
	}
	printf("  :BOTTOM\n");
}
