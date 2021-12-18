#include "push_swap.h"

static int	getPivotIdx_B(int size, int prePivotIdx)
{
	int	gap;

	if (size <= 3)
		return (prePivotIdx - 1);
	gap = size / 2;
	return (prePivotIdx - gap);
}

static int	sendHalfElement_B(t_var *var, int depth, int pivot, int preSize)
{
	int	size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = getAnyStackSize_B(var, depth, preSize);
	while (size--)
	{
		if (var->B->top->right->val > pivot)
		{
			answer++;
			ft_putstr(pa(var), 1);
		}
		else
		{
			count++;
			ft_putstr(rb(var), 1);
		}
	}
	if (getStackSize(var->B) != size)
		while (count--)
			ft_putstr(rrb(var), 1);
	return (answer);
}

void	reB(t_var *var, int depth, int preSize, int prePivotIdx)
{
	t_stack	*nowStack;
	int		now_pivot_index;
	int		size;
	int		sendCount;

	size = getAnyStackSize_B(var, depth, preSize);
	now_pivot_index = getPivotIdx_B(size, prePivotIdx);
	if (size <= 2)
	{
		if (size <= 1)
			return ;
		if (var->B->top->right->val < var->B->top->right->right->val)
			ft_putstr(sb(var), 1);
		return ;
	}
	sendCount = sendHalfElement_B(var, depth,
			var->pivot_arr[now_pivot_index], preSize);
	reA(var, depth + 1, size, now_pivot_index);
	reB(var, depth + 1, size, now_pivot_index);
	while (sendCount--)
		ft_putstr(pb(var), 1);
}
