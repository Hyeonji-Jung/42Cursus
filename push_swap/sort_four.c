#include "push_swap.h"

int		sort_four_a(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;
	int		flag;

	flag = 0;
	top = var->A->top;
	if (is_sorted(top->right, 4, S_A))
		return (1);
	max = max_node(top->right, 4);
	min = min_node(top->right, 4);
	if (min == top->right)
	{
		flag = 1;
		save_list(var, ra(var));
		sort_three_a(var);
		save_list(var, rra(var));
	}
	else if (max == top->right->right->right->right)
	{
		flag = 1;
		sort_three_a(var);
	}

	printf("sort_four_a\n");
	printStack_test(var->A);
	printStack_test(var->B);
	return (flag);
}

int		sort_four_b(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;
	int		flag;

	flag = 0;
	top = var->B->top;
	if (is_sorted(top->right, 4, S_B))
		return (1);
	max = max_node(top->right, 4);
	min = min_node(top->right, 4);
	if (max == top->right)
	{
		flag = 1;
		save_list(var, rb(var));
		sort_three_b(var);
		save_list(var, rrb(var));
	}
	else if (min == top->right->right->right->right)
	{
		flag = 1;
		sort_three_b(var);
	}

	printf("sort_four_b\n");
	printStack_test(var->A);
	printStack_test(var->B);
	return (flag);
}
