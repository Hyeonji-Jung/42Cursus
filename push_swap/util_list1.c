/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:35:32 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/26 23:35:33 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_node	*get_new_list_node(char *str)
{
	t_list_node	*node;

	node = malloc(sizeof(t_list_node));
	if (!node)
		return (0);
	node->val = str;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	init_list(t_var *var)
{
	var->list = malloc(sizeof(t_list));
	var->list->top = get_new_list_node("");
}

static void	list_append(t_list *list, t_list_node *node)
{
	t_list_node	*temp;

	temp = list->top;
	while (temp->right != NULL)
		temp = temp->right;
	temp->right = node;
	node->left = temp;
	node->right = NULL;
}

void	save_list(t_var *var, char *str)
{
	t_list_node	*new_node;

	new_node = get_new_list_node(str);
	list_append(var->list, new_node);
}

void	print_list(t_var *var)
{
	t_list_node	*temp;

	temp = var->list->top;
	while (temp != NULL)
	{
		if (temp->val != NULL)
			ft_putstr(temp->val, 1);
		temp = temp->right;
	}
}
