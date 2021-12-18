#include "push_swap.h"

char	*sa(t_var *var)
{
	t_node	*temp;
	t_node	*top;

	top = var->A->top;
	temp = top->right;
	if (temp->right != var->A->bottom)
	{
		top->right = temp->right;
		temp->right->left = temp->left;
		temp->left = temp->right;
		temp->right = temp->right->right;
		top->right->right = temp;
		temp->right->left = temp;
	}
	return ("sa\n");
}

char	*sb(t_var *var)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*fixed3;
	t_node	*top;

	top = var->B->top;
	temp1 = top->right;
	temp2 = temp1->right;
	if (temp2 != var->B->bottom)
	{
		fixed3 = temp2->right;
		top->right = temp2;
		fixed3->left = temp1;
		temp1->left = temp2;
		temp1->right = fixed3;
		temp2->left = top;
		temp2->right = temp1;
	}
	return ("sb\n");
}

char	*ss(t_var *var)
{
	sa(var);
	sb(var);
	return ("ss\n");
}

char	*pa(t_var *var)
{
	t_node	*node;

	node = popTop(var->B);
	if (node)
		pushTop(var->A, node);
	return ("pa\n");
}

char	*pb(t_var *var)
{
	t_node	*node;

	node = popTop(var->A);
	if (node)
		pushTop(var->B, node);
	return ("pb\n");
}
