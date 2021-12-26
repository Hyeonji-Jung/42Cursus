#include "push_swap.h"

void	sort_three_a(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->A->top;
	if (is_sorted(top->right, 3, S_A))
		return ;
	max = max_node(top->right, 3);
	min = min_node(top->right, 3);
	if (max == top->right || min == top->right)
	{
		if (max == top->right)
		{
			save_list(var, sa(var));
			save_list(var, ra(var));
			save_list(var, sa(var));
			save_list(var, rra(var));
			if (top->right->val > top->right->right->val)
				save_list(var, sa(var));
		}
		if (min == top->right)
		{
			save_list(var, ra(var));
			if (top->right->val > top->right->right->val)
				save_list(var, sa(var));
			save_list(var, rra(var));
		}
	}
	else if (max == top->right->right->right
		|| min == top->right->right->right)
	{
		if (top->right->val > top->right->right->val)
			save_list(var, sa(var));
		if (min == top->right->right->right)
		{
			save_list(var, ra(var));
			save_list(var, sa(var));
			save_list(var, rra(var));
			save_list(var, sa(var));
		}
	}
}

void	sort_three_b(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->B->top;
	if (is_sorted(top->right, 3, S_B))
		return ;
	max = max_node(top->right, 3);
	min = min_node(top->right, 3);
	if (max == top->right || min == top->right)
	{
		if (max == top->right)
		{
			save_list(var, rb(var));
			if (top->right->val < top->right->right->val)
				save_list(var, sb(var));
			save_list(var, rrb(var));
		}
		if (min == top->right)
		{
			save_list(var, sb(var));
			save_list(var, rb(var));
			save_list(var, sb(var));
			save_list(var, rrb(var));
			if (top->right->val < top->right->right->val)
				save_list(var, sb(var));
		}
	}
	else if (max == top->right->right->right
		|| min == top->right->right->right)
	{
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
		if (max == top->right->right->right)
		{
			save_list(var, rb(var));
			save_list(var, sb(var));
			save_list(var, rrb(var));
			save_list(var, sb(var));
		}
	}
}
