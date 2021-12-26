#include "push_swap.h"

static void	sort_four_a_temp(t_var *var)
{
	t_node	*top;
	t_node	*min;

	top = var->A->top;
	min = min_node(top->right, 4);
	sort_three_a(var);
	if (min == top->right->right->right->right)
		save_list(var, rra(var));
}

static void	sort_four_b_temp(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->B->top;
	max = max_node(top->right, 4);
	sort_three_b(var);
	if (max == top->right->right->right->right)
		save_list(var, rrb(var));
}

void	sort_only_four_a(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->A->top;
	if (is_sorted(top->right, 4, S_A))
		return ;
	max = max_node(top->right, 4);
	min = min_node(top->right, 4);
	if (max == top->right || min == top->right)
	{
		save_list(var, ra(var));
		sort_four_a_temp(var);
	}
	else if (max == top->right->right->right->right
		|| min == top->right->right->right->right)
		sort_four_a_temp(var);
	else
	{
		save_list(var, rra(var));
		sort_four_a_temp(var);
	}
}

void	sort_only_four_b(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->B->top;
	if (is_sorted(top->right, 4, S_B))
		return ;
	max = max_node(top->right, 4);
	min = min_node(top->right, 4);
	if (max == top->right || min == top->right)
	{
		save_list(var, rb(var));
		sort_four_b_temp(var);
	}
	else if (max == top->right->right->right->right
		|| min == top->right->right->right->right)
		sort_four_b_temp(var);
	else
	{
		save_list(var, rrb(var));
		sort_four_b_temp(var);
	}
}
