#include "push_swap.h"

static int	get_pivot_idx_b(int size, int pre_pivot_idx)
{
	int	gap;

	if (size <= 3)
		return (pre_pivot_idx - 1);
	gap = size / 2;
	return (pre_pivot_idx - gap);
}

static int	send_half_element_b(t_var *var, int pivot, int pre_size)
{
	int	size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = get_any_stack_size_b(pre_size);
	while (size--)
	{
		if (var->B->top->right->val > pivot)
		{
			answer++;
			save_list(var, pa(var));
		}
		else
		{
			count++;
			save_list(var, rb(var));
		}
	}
	if (get_stack_size(var->B) != size)
		while (count--)
			save_list(var, rrb(var));
	return (answer);
}

void	re_b(t_var *var, int pre_size, int pre_pivot_idx)
{
	int		now_pivot_index;
	int		size;
	int		send_count;

	size = get_any_stack_size_b(pre_size);
	now_pivot_index = get_pivot_idx_b(size, pre_pivot_idx);
	if (size <= 3)
	{
		if (size == 2)
		{
			if (var->B->top->right->val < var->B->top->right->right->val)
				save_list(var, sb(var));
		}
		else if (size == 3 && get_stack_size(var->B) != size)
			sort_three_b(var);
		else if (size == 3 && get_stack_size(var->B) == size)
			sort_only_three_b(var);
		return ;
	}
	if (size == 4)
	{
		if (get_stack_size(var->B) == size)
		{
			sort_only_four_b(var);
			return ;
		}
		else if (sort_four_b(var) == 1)
			return ;
	}
	send_count = send_half_element_b(var,
			var->pivot_arr[now_pivot_index], pre_size);
	re_a(var, size, now_pivot_index);
	re_b(var, size, now_pivot_index);
	while (send_count--)
		save_list(var, pb(var));
}
