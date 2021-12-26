#include "push_swap.h"

static int	get_pivot_idx_b(int size, int pre_pivot_idx)
{
	int	gap;

	if (size <= 3)
		return (pre_pivot_idx - 1);
	gap = size / 2;
	return (pre_pivot_idx - gap);
}

static void	re_rotate(t_var *var, int size, int count)
{
	if (get_stack_size(var->B) != size)
		while (count--)
			save_list(var, rrb(var));
}

static int	send_half_element_b(t_var *var, int pivot, int pre_size)
{
	int	size;
	int	post_size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = get_any_stack_size_b(pre_size);
	post_size = get_any_stack_size_a(size);
	while (size-- && answer < post_size)
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
	re_rotate(var, size, count);
	return (answer);
}

static int	check_size_and_sort(t_var *var, int size)
{
	if (size <= 4)
	{
		if (size == 2
			&& var->B->top->right->val < var->B->top->right->right->val)
			save_list(var, sb(var));
		else if (size == 3 && get_stack_size(var->B) != size)
			sort_three_b(var);
		else if (size == 3 && get_stack_size(var->B) == size)
			sort_only_three_b(var);
		else if (size == 4)
		{
			if (get_stack_size(var->B) == size)
				sort_only_four_b(var);
			else
				sort_four_b(var);
		}
	}
	if (is_sorted(var->B->top->right, size, S_B))
		return (1);
	return (0);
}

void	re_b(t_var *var, int pre_size, int pre_pivot_idx)
{
	int		now_pivot_index;
	int		size;
	int		send_count;

	size = get_any_stack_size_b(pre_size);
	if (check_size_and_sort(var, size))
		return ;
	now_pivot_index = get_pivot_idx_b(size, pre_pivot_idx);
	send_count = send_half_element_b(var,
			var->pivot_arr[now_pivot_index], pre_size);
	re_a(var, size, now_pivot_index);
	re_b(var, size, now_pivot_index);
	while (send_count--)
		save_list(var, pb(var));
}
