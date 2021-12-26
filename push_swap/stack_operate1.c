/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operate1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:35:12 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/26 23:48:22 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_var *var)
{
	t_node	*temp;
	t_node	*top;

	top = var->stack_a->top;
	temp = top->right;
	if (temp->right != var->stack_a->bottom)
	{
		top->right = temp->right;
		temp->right->left = temp->left;
		temp->left = temp->right;
		temp->right = temp->right->right;
		top->right->right = temp;
		temp->right->left = temp;
	}
	return ("sa\n");
}

char	*sb(t_var *var)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*fixed3;
	t_node	*top;

	top = var->stack_b->top;
	temp1 = top->right;
	temp2 = temp1->right;
	if (temp2 != var->stack_b->bottom)
	{
		fixed3 = temp2->right;
		top->right = temp2;
		fixed3->left = temp1;
		temp1->left = temp2;
		temp1->right = fixed3;
		temp2->left = top;
		temp2->right = temp1;
	}
	return ("sb\n");
}

char	*ss(t_var *var)
{
	sa(var);
	sb(var);
	return ("ss\n");
}

char	*pa(t_var *var)
{
	t_node	*node;

	node = pop_top(var->stack_b);
	if (node)
		push_top(var->stack_a, node);
	return ("pa\n");
}

char	*pb(t_var *var)
{
	t_node	*node;

	node = pop_top(var->stack_a);
	if (node)
		push_top(var->stack_b, node);
	return ("pb\n");
}
