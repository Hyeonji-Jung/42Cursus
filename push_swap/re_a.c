/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:34:40 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/26 23:51:13 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	re_rotate(t_var *var, int size, int count)
{
	if (get_stack_size(var->stack_a) != size)
		while (count--)
			save_list(var, rra(var));
}

static int	send_half_element_a(t_var *var, int pivot, int pre_size)
{
	int	size;
	int	post_size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = get_any_stack_size_a(pre_size);
	post_size = get_any_stack_size_b(size);
	while (size-- && answer < post_size)
	{
		if (var->stack_a->top->right->val <= pivot)
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
	re_rotate(var, size, count);
	return (answer);
}

static int	check_size_and_sort(t_var *var, int size)
{
	t_node	*top;

	top = var->stack_a->top;
	if (size <= 4)
	{
		if (size == 2
			&& top->right->val > top->right->right->val)
			save_list(var, sa(var));
		else if (size == 3 && get_stack_size(var->stack_a) != size)
			sort_three_a(var);
		else if (size == 3 && get_stack_size(var->stack_a) == size)
			sort_only_three_a(var);
		else if (size == 4)
		{
			if (get_stack_size(var->stack_a) == size)
				sort_only_four_a(var);
			else
				sort_four_a(var);
		}
	}
	if (is_sorted(top->right, size, S_A))
		return (1);
	return (0);
}

void	re_a(t_var *var, int pre_size, int pre_pivot_idx)
{
	int		now_pivot_index;
	int		size;
	int		send_count;

	size = get_any_stack_size_a(pre_size);
	if (check_size_and_sort(var, size))
		return ;
	now_pivot_index = get_pivot_idx_a(size, pre_pivot_idx);
	send_count = send_half_element_a(var,
			var->pivot_arr[now_pivot_index], pre_size);
	re_a(var, size, now_pivot_index);
	re_b(var, size, now_pivot_index);
	while (send_count--)
		save_list(var, pa(var));
}
