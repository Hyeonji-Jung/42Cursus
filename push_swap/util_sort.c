#include "push_swap.h"

int		is_sorted(t_node *temp, int len, int now_stack)
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