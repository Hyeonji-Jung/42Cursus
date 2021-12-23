#include "push_swap.h"

char	*ra(t_var *var)
{
	t_node	*node;

	node = pop_top(var->A);
	if (node)
		push_bottom(var->A, node);
	return ("ra\n");
}

char	*rb(t_var *var)
{
	t_node	*node;

	node = pop_top(var->B);
	if (node)
		push_bottom(var->B, node);
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

	node = pop_bottom(var->A);
	if (node)
		push_top(var->A, node);
	return ("rra\n");
}

char	*rrb(t_var *var)
{
	t_node	*node;

	node = pop_bottom(var->B);
	if (node)
		push_top(var->B, node);
	return ("rrb\n");
}
