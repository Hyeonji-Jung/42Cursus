/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operate2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:35:20 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/26 23:48:29 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ra(t_var *var)
{
	t_node	*node;

	node = pop_top(var->stack_a);
	if (node)
		push_bottom(var->stack_a, node);
	return ("ra\n");
}

char	*rb(t_var *var)
{
	t_node	*node;

	node = pop_top(var->stack_b);
	if (node)
		push_bottom(var->stack_b, node);
	return ("rb\n");
}

char	*rr(t_var *var)
{
	ra(var);
	rb(var);
	return ("rr\n");
}

char	*rra(t_var *var)
{
	t_node	*node;

	node = pop_bottom(var->stack_a);
	if (node)
		push_top(var->stack_a, node);
	return ("rra\n");
}

char	*rrb(t_var *var)
{
	t_node	*node;

	node = pop_bottom(var->stack_b);
	if (node)
		push_top(var->stack_b, node);
	return ("rrb\n");
}
