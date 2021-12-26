#include "push_swap.h"

void	sort_four_a(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->A->top;
	if (is_sorted(top->right, 4, S_A))
		return ;
	max = max_node(top->right, 4);
	min = min_node(top->right, 4);
	if (min == top->right)
	{
		save_list(var, ra(var));
		sort_three_a(var);
		save_list(var, rra(var));
	}
	else if (max == top->right->right->right->right)
		sort_three_a(var);
}

void	sort_four_b(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->B->top;
	if (is_sorted(top->right, 4, S_B))
		return ;
	max = max_node(top->right, 4);
	min = min_node(top->right, 4);
	if (max == top->right)
	{
		save_list(var, rb(var));
		sort_three_b(var);
		save_list(var, rrb(var));
	}
	else if (min == top->right->right->right->right)
		sort_three_b(var);
}
