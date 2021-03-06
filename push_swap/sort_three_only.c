/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:34:57 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/26 23:48:01 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_only_three_a(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->stack_a->top;
	if (is_sorted(top->right, 3, S_A))
		return ;
	max = max_node(top->right, 3);
	min = min_node(top->right, 3);
	if (max == top->right->right->right
		|| min == top->right->right->right)
	{
		if (top->right->val > top->right->right->val)
			save_list(var, sa(var));
		if (min == top->right->right->right)
			save_list(var, rra(var));
	}
	else if (max == top->right || min == top->right)
	{
		save_list(var, ra(var));
		if (top->right->val > top->right->right->val)
			save_list(var, sa(var));
		if (min == top->right->right->right)
			save_list(var, rra(var));
	}
}

void	sort_only_three_b(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->stack_b->top;
	if (is_sorted(top->right, 3, S_B))
		return ;
	max = max_node(top->right, 3);
	min = min_node(top->right, 3);
	if (max == top->right->right->right
		|| min == top->right->right->right)
	{
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
		if (max == top->right->right->right)
			save_list(var, rrb(var));
	}
	else if (max == top->right || min == top->right)
	{
		save_list(var, rb(var));
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
		if (max == top->right->right->right)
			save_list(var, rrb(var));
	}
}
