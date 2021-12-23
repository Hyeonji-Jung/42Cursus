#include "push_swap.h"

int	is_sorted(t_node *t1, t_node *t2, t_node *t3, int now_stack)
{
	if (now_stack == S_A)
	{
		if (t1->val < t2->val && t2->val < t3->val)
			return (1);
		return (0);
	}
	else
	{
		if (t1->val > t2->val && t2->val > t3->val)
			return (1);
		return (0);
	}
}

void	sort_only_three_a(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->A->top;
	if (is_sorted(top->right, top->right->right, top->right->right->right, S_A))
		return ;
	max = max_node(top->right, top->right->right, top->right->right->right);
	if (max == top->right)
		save_list(var, ra(var));
	else if (max == top->right->right)
		save_list(var, rra(var));
	if (top->right->val > top->right->right->val)
		save_list(var, sa(var));
}

void	sort_only_three_b(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->B->top;
	if (is_sorted(top->right, top->right->right, top->right->right->right, S_B))
		return ;
	max = max_node(top->right, top->right->right, top->right->right->right);
	if (max == top->right)
	{
		save_list(var, rrb(var));
		save_list(var, sb(var));
	}
	else if (max == top->right->right)
	{
		if (top->right->val > top->right->right->right->val)
			save_list(var, sb(var));
		else
			save_list(var, rb(var));
	}
	else
	{
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
		save_list(var, rrb(var));
	}
}

void	sort_three_a(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->A->top;
	if (is_sorted(top->right, top->right->right, top->right->right->right, S_B))
		return ;
	max = max_node(top->right, top->right->right, top->right->right->right);
	if (max == top->right)
	{
		save_list(var, sa(var));
		save_list(var, ra(var));
		save_list(var, sa(var));
		save_list(var, rra(var));
	}
	else if (max == top->right->right)
	{
		save_list(var, ra(var));
		save_list(var, sa(var));
		save_list(var, rra(var));
	}
	if (top->right->val > top->right->right->val)
		save_list(var, sa(var));
}

void	sort_three_b(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->B->top;
	if (is_sorted(top->right, top->right->right, top->right->right->right, S_B))
		return ;
	max = max_node(top->right, top->right->right, top->right->right->right);
	if (max == top->right)
	{
		save_list(var, rb(var));
		save_list(var, sb(var));
		save_list(var, rrb(var));
	}
	else if (max == top->right->right)
	{
		save_list(var, sb(var));
		if (top->right->right->val > top->right->right->right->val)
		{
			save_list(var, rb(var));
			save_list(var, sb(var));
			save_list(var, rrb(var));
		}
	}
	else
	{
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
		save_list(var, rb(var));
		save_list(var, sb(var));
		save_list(var, rrb(var));
		save_list(var, sb(var));
	}
}
