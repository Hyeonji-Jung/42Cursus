/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:34:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/01/02 17:29:31 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	send_half_element_init(t_var *var, int pivot)
{
	int	size;

	size = var->max_size;
	while (size--)
	{
		if (var->stack_a->top->right->val <= pivot)
			save_list(var, pb(var));
		else
			save_list(var, ra(var));
	}
	return (0);
}

static int	check_size_and_sort(t_var *var)
{
	t_node	*top;

	top = var->stack_a->top;
	if (var->max_size <= 4)
	{
		if (var->max_size == 2)
		{
			if (top->right->val > top->right->right->val)
				save_list(var, sa(var));
		}
		else if (var->max_size == 3)
			sort_only_three_a(var);
		else if (var->max_size == 4)
			sort_only_four_a(var);
	}
	if (is_sorted(top->right, var->max_size, S_A))
		return (1);
	return (0);
}

static void	re(t_var *var)
{
	int	now_pivot_index;
	int	size;

	if (check_size_and_sort(var))
		return ;
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
		exit(0);
	}
	return (0);
}
