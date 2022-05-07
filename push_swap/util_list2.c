/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:35:51 by hyeojung          #+#    #+#             */
/*   Updated: 2022/01/02 14:58:12 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	erase_list_node(t_list_node *point)
{
	t_list_node	*temp;

	temp = point->left;
	temp->right = point->right->right;
	if (point->right->right != NULL)
		point->right->right->left = temp;
	free(point->right);
	free(point);
}

static void	zip_list_node(t_list_node *point)
{
	t_list_node	*temp;

	if (cmp(point->val, "ra\n") || cmp(point->val, "rb\n"))
		point->val = "rr\n";
	else if (cmp(point->val, "rra\n") || cmp(point->val, "rrb\n"))
		point->val = "rrr\n";
	else if (cmp(point->val, "sa\n") || cmp(point->val, "sb\n"))
		point->val = "ss\n";
	temp = point->right;
	if (point->right->right != NULL)
	{
		point->right->right->left = point;
		point->right = point->right->right;
	}
	else
		point->right = NULL;
	free(temp);
}

static int	is_erase_list_node(t_list_node *temp)
{
	if ((cmp(temp->val, "rr\n") && cmp(temp->right->val, "rrr\n"))
		|| (cmp(temp->val, "rrr\n") && cmp(temp->right->val, "rr\n"))
		|| (cmp(temp->val, "pa\n") && cmp(temp->right->val, "pb\n"))
		|| (cmp(temp->val, "pb\n") && cmp(temp->right->val, "pa\n"))
		|| (cmp(temp->val, "ra\n" ) && cmp(temp->right->val, "rra\n"))
		|| (cmp(temp->val, "rra\n") && cmp(temp->right->val, "ra\n"))
		|| (cmp(temp->val, "rb\n" ) && cmp(temp->right->val, "rrb\n"))
		|| (cmp(temp->val, "rrb\n") && cmp(temp->right->val, "rb\n"))
		|| (cmp(temp->val, "sa\n") && cmp(temp->right->val, "sa\n"))
		|| (cmp(temp->val, "sb\n" ) && cmp(temp->right->val, "sb\n")))
		return (1);
	return (0);
}

static int	is_zip_list_node(t_list_node *temp)
{
	if ((cmp(temp->val, "ra\n") && cmp(temp->right->val, "rb\n"))
		|| (cmp(temp->val, "rb\n") && cmp(temp->right->val, "ra\n"))
		|| (cmp(temp->val, "rra\n") && cmp(temp->right->val, "rrb\n"))
		|| (cmp(temp->val, "rrb\n") && cmp(temp->right->val, "rra\n"))
		|| (cmp(temp->val, "sa\n") && cmp(temp->right->val, "sb\n"))
		|| (cmp(temp->val, "sb\n") && cmp(temp->right->val, "sa\n")))
		return (1);
	return (0);
}

void	optimize_list(t_list *list)
{
	t_list_node	*temp;

	temp = list->top->right;
	while (temp->right != NULL)
	{
		if (is_erase_list_node(temp))
		{
			temp = temp->left;
			erase_list_node(temp->right);
			if (temp == list->top)
				temp = temp->right;
		}
		else if (is_zip_list_node(temp))
		{
			temp = temp->left;
			zip_list_node(temp->right);
			if (temp == list->top)
				temp = temp->right;
		}
		else
			temp = temp->right;
	}
}
