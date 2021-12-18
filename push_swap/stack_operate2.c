#include "push_swap.h"

char	*ra(t_var *var)
{
	t_node	*node;

	node = popTop(var->A);
	if (node)
		pushBottom(var->A, node);
	return ("ra\n");
}

char	*rb(t_var *var)
{
	t_node	*node;

	node = popTop(var->B);
	if (node)
		pushBottom(var->B, node);
	return ("rb\n");
}

char	*rr(t_var *var)
{
	ra(var);
	rb(var);
	return ("rr\n");
}

char	*rra(t_var *var)
{
	t_node	*node;

	node = popBottom(var->A);
	if (node)
		pushTop(var->A, node);
	return ("rra\n");
}

char	*rrb(t_var *var)
{
	t_node	*node;

	node = popBottom(var->B);
	if (node)
		pushTop(var->B, node);
	return ("rrb\n");
}
