#include "push_swap.h"

char	*sa(t_var *var)
{
	t_node	*temp;
	t_node	*top;

	top = var->A->top;
	temp = top->right;
	top->right = temp->right;
	temp->right->left = temp->left;
	temp->left = temp->right;
	temp->right = temp->right->right;
	top->right->right = temp;
	temp->right->left = temp;
	return ("sa");
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
	fixed3 = temp2->right;
	top->right = temp2;
	fixed3->left = temp1;
	temp1->left = temp2;
	temp1->right = fixed3;
	temp2->left = top;
	temp2->right = temp1;
	return ("sb");
}

char	*ss(t_var *var)
{
	sa(var);
	sb(var);
	return ("ss");
}

char	*pa(t_var *var)
{
	t_node	*node;

	node = popTop(var->B);
	if (node)
		pushTop(var->A, node);
	return ("pa");
}

char	*pb(t_var *var)
{
	t_node	*node;

	node = popTop(var->A);
	if (node)
		pushTop(var->B, node);
	return ("pb");
}

char	*ra(t_var *var)
{
	t_node	*node;

	node = popTop(var->A);
	if (node)
		pushBottom(var->A, node);
	return ("ra");
}

char	*rb(t_var *var)
{
	t_node	*node;

	node = popTop(var->B);
	if (node)
		pushBottom(var->B, node);
	return ("rb");
}

char	*rr(t_var *var)
{
	ra(var);
	rb(var);
	return ("rr");
}

char	*rra(t_var *var)
{
	t_node	*node;

	node = popBottom(var->A);
	if (node)
		pushTop(var->A, node);
	return ("rra");
}

char	*rrb(t_var *var)
{
	t_node	*node;

	node = popBottom(var->B);
	if (node)
		pushTop(var->B, node);
	return ("rrb");
}

char	*rrr(t_var *var)
{
	rra(var);
	rrb(var);
	return ("rrr");
}
