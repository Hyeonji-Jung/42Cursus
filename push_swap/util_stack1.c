/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:36:22 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/26 23:49:01 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->val = num;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	init_stack(t_var *var)
{
	var->stack_a = malloc(sizeof(t_stack));
	var->stack_b = malloc(sizeof(t_stack));
	var->stack_a->top = get_new_node(0);
	var->stack_a->bottom = get_new_node(0);
	var->stack_a->top->right = var->stack_a->bottom;
	var->stack_a->bottom->left = var->stack_a->top;
	var->stack_b->top = get_new_node(0);
	var->stack_b->bottom = get_new_node(0);
	var->stack_b->top->right = var->stack_b->bottom;
	var->stack_b->bottom->left = var->stack_b->top;
}

void	push_top(t_stack *stack, t_node *new_node)
{
	t_node	*top;
	t_node	*temp;

	top = stack->top;
	temp = top->right;
	top->right = new_node;
	temp->left = new_node;
	new_node->left = top;
	new_node->right = temp;
}

void	push_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*bottom;
	t_node	*temp;

	bottom = stack->bottom;
	temp = bottom->left;
	bottom->left = new_node;
	temp->right = new_node;
	new_node->left = temp;
	new_node->right = bottom;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*top;
	t_node	*temp;

	top = stack->top;
	if (top->right == stack->bottom)
		return (0);
	temp = top->right;
	temp->right->left = top;
	top->right = temp->right;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}
