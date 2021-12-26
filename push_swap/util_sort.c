#include "push_swap.h"

int	is_sorted(t_node *temp, int len, int now_stack)
{
	len--;
	if (now_stack == S_A)
	{
		while (len--)
		{
			if (temp->val > temp->right->val)
				return (0);
			temp = temp->right;
		}
		return (1);
	}
	else
	{
		while (len--)
		{
			if (temp->val < temp->right->val)
				return (0);
			temp = temp->right;
		}
		return (1);
	}
}

t_node	*max_node(t_node *temp, int len)
{
	t_node	*max_node;

	max_node = temp;
	len--;
	temp = temp->right;
	while (len--)
	{
		if (temp->val > max_node->val)
			max_node = temp;
		temp = temp->right;
	}
	return (max_node);
}

t_node	*min_node(t_node *temp, int len)
{
	t_node	*min_node;

	min_node = temp;
	len--;
	temp = temp->right;
	while (len--)
	{
		if (temp->val < min_node->val)
			min_node = temp;
		temp = temp->right;
	}
	return (min_node);
}
