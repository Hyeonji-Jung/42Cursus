/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:35:01 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/26 23:48:09 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_temp(t_var *var, int now_stack)
{
	if (now_stack == S_A)
	{
		save_list(var, ra(var));
		save_list(var, sa(var));
		save_list(var, rra(var));
	}
	if (now_stack == S_B)
	{
		save_list(var, rb(var));
		save_list(var, sb(var));
		save_list(var, rrb(var));
	}
}

static void	sort_three_a_condition(t_node *top, t_node *max, t_node *min,
															t_var *var)
{
	if (max == top->right)
	{
		save_list(var, sa(var));
		sort_three_temp(var, S_A);
		if (top->right->val > top->right->right->val)
			save_list(var, sa(var));
	}
	if (min == top->right)
	{
		save_list(var, ra(var));
		if (top->right->val > top->right->right->val)
			save_list(var, sa(var));
		save_list(var, rra(var));
	}
}

static void	sort_three_b_condition(t_node *top, t_node *max, t_node *min,
															t_var *var)
{
	if (max == top->right)
	{
		save_list(var, rb(var));
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
		save_list(var, rrb(var));
	}
	if (min == top->right)
	{
		save_list(var, sb(var));
		sort_three_temp(var, S_B);
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
	}
}

void	sort_three_a(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->stack_a->top;
	if (is_sorted(top->right, 3, S_A))
		return ;
	max = max_node(top->right, 3);
	min = min_node(top->right, 3);
	if (max == top->right || min == top->right)
		sort_three_a_condition(top, max, min, var);
	else if (max == top->right->right->right
		|| min == top->right->right->right)
	{
		if (top->right->val > top->right->right->val)
			save_list(var, sa(var));
		if (min == top->right->right->right)
		{
			sort_three_temp(var, S_A);
			save_list(var, sa(var));
		}
	}
}

void	sort_three_b(t_var *var)
{
	t_node	*top;
	t_node	*max;
	t_node	*min;

	top = var->stack_b->top;
	if (is_sorted(top->right, 3, S_B))
		return ;
	max = max_node(top->right, 3);
	min = min_node(top->right, 3);
	if (max == top->right || min == top->right)
		sort_three_b_condition(top, max, min, var);
	else if (max == top->right->right->right
		|| min == top->right->right->right)
	{
		if (top->right->val < top->right->right->val)
			save_list(var, sb(var));
		if (max == top->right->right->right)
		{
			sort_three_temp(var, S_B);
			save_list(var, sb(var));
		}
	}
}
