#include "push_swap.h"

static void	sort_three_b_temp(t_var *var)
{
	save_list(var, rb(var));
	save_list(var, sb(var));
	save_list(var, rrb(var));
}


void	sort_only_three_a(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->A->top;
	if (is_sorted(top->right, 3, S_A))
		return ;
	max = max_node(top->right, 3);
	if (max == top->right)
		save_list(var, ra(var));
	else if (max == top->right->right)
		save_list(var, rra(var));
	if (top->right->val > top->right->right->val)
		save_list(var, sa(var));
	

	printf("sort_only_three_a\n");
	printStack_test(var->A);
	printStack_test(var->B);
}

void	sort_only_three_b(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->B->top;
	if (is_sorted(top->right, 3, S_B))
		return ;
	max = max_node(top->right, 3);
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


	printf("sort_only_three_b\n");
	printStack_test(var->A);
	printStack_test(var->B);
}

void	sort_three_a(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->A->top;
	if (is_sorted(top->right, 3, S_A))
		return ;
	max = max_node(top->right, 3);
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
	


	printf("sort_three_a\n");
	printStack_test(var->A);
	printStack_test(var->B);
}

void	sort_three_b(t_var *var)
{
	t_node	*top;
	t_node	*max;

	top = var->B->top;
	if (is_sorted(top->right, 3, S_B))
		return ;
	max = max_node(top->right, 3);
	if (max == top->right)
		sort_three_b_temp(var);
	else if (max == top->right->right)
	{
		save_list(var, sb(var));
		if (top->right->right->val > top->right->right->right->val)
			sort_three_b_temp(var);
	}
	else
	{
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
		sort_three_b_temp(var);
		save_list(var, sb(var));
	}

	printf("sort_three_b\n");
	printStack_test(var->A);
	printStack_test(var->B);
}
