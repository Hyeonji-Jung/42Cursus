#include "push_swap.h"

static int	get_pivot_idx_a(int size, int pre_pivot_idx)
{
	int	gap;

	if (size <= 3)
		return (pre_pivot_idx + 2);
	gap = size / 2;
	if (size % 2 == 1)
		gap += 1;
	return (pre_pivot_idx + gap);
}

static int	send_half_element_a(t_var *var, int pivot, int pre_size)
{
	int	size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = get_any_stack_size_a(pre_size);
	while (size--)
	{
		if (var->A->top->right->val <= pivot)
		{
			answer++;
			save_list(var, pb(var));
		}
		else
		{
			count++;
			save_list(var, ra(var));
		}
	}
	if (get_stack_size(var->A) != size)
		while (count--)
			save_list(var, rra(var));
	return (answer);
}

void	re_a(t_var *var, int pre_size, int pre_pivot_idx)
{
	int		now_pivot_index;
	int		size;
	int		send_count;

	size = get_any_stack_size_a(pre_size);
	now_pivot_index = get_pivot_idx_a(size, pre_pivot_idx);
	if (size <= 3)
	{
		if (size == 2)
		{
			if (var->A->top->right->val > var->A->top->right->right->val)
				save_list(var, sa(var));
		}
		else if (size == 3 && get_stack_size(var->A) != size)
			sort_three_a(var);
		else if (size == 3 && get_stack_size(var->A) == size)
			sort_only_three_a(var);
		return ;
	}
	send_count = send_half_element_a(var,
			var->pivot_arr[now_pivot_index], pre_size);
	re_a(var, size, now_pivot_index);
	re_b(var, size, now_pivot_index);
	while (send_count--)
		save_list(var, pa(var));
}
