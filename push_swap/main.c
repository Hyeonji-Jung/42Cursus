#include "push_swap.h"

static int	send_half_element_init(t_var *var, int pivot)
{
	int	size;
	int	count;

	count = 0;
	size = var->max_size;
	while (size--)
	{
		if (var->A->top->right->val <= pivot)
			save_list(var, pb(var));
		else
		{
			count++;
			save_list(var, ra(var));
		}
	}
	if (get_stack_size(var->A) != size)
		while (count--)
			save_list(var, rra(var));
	return (0);
}

static void	re(t_var *var)
{
	int		now_pivot_index;
	int		size;

	if (var->max_size <= 3)
	{
		if (var->max_size == 2)
		{
			if (var->A->top->right->val > var->A->top->right->right->val)
				save_list(var, sa(var));
		}
		else if (var->max_size == 3)
			sort_only_three_a(var);
		return ;
	}
	now_pivot_index = var->max_size / 2;
	if (var->max_size % 2 == 0)
		now_pivot_index -= 1;
	send_half_element_init(var, var->pivot_arr[now_pivot_index]);
	re_a(var, var->max_size, now_pivot_index);
	re_b(var, var->max_size, now_pivot_index);
	size = var->max_size / 2;
	if (var->max_size % 2 == 1)
		size += 1;
	while (size--)
		save_list(var, pa(var));
}

int	main(int argc, char *argv[])
{
	t_var	var;

	if (argc >= 2)
	{
		init_stack(&var);
		init_list(&var);
		preprocess(&var, argc, argv);
		re(&var);
		optimize_list(var.list);
		print_list(&var);
		printStack_test(var.A);
	}
	else
		exit(0);
}
