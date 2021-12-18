#include "push_swap.h"

static int	getPivotIdx_A(int size, int prePivotIdx)
{
	int	gap;

	if (size <= 3)
		return (prePivotIdx + 2);
	gap = size / 2;
	if (size % 2 == 1)
		gap += 1;
	return (prePivotIdx + gap);
}

static int	sendHalfElement_A(t_var *var, int pivot, int preSize)
{
	int	size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = getAnyStackSize_A(preSize);
	while (size--)
	{
		if (var->A->top->right->val <= pivot)
		{
			answer++;
			ft_putstr(pb(var), 1);
		}
		else
		{
			count++;
			ft_putstr(ra(var), 1);
		}
	}
	if (getStackSize(var->A) != size)
		while (count--)
			ft_putstr(rra(var), 1);
	return (answer);
}

void	reA(t_var *var, int preSize, int prePivotIdx)
{
	int		now_pivot_index;
	int		size;
	int		sendCount;

	size = getAnyStackSize_A(preSize);
	now_pivot_index = getPivotIdx_A(size, prePivotIdx);
	if (size <= 2)
	{
		if (size <= 1)
			return ;
		if (var->A->top->right->val > var->A->top->right->right->val)
			ft_putstr(sa(var), 1);
		return ;
	}
	sendCount = sendHalfElement_A(var,
			var->pivot_arr[now_pivot_index], preSize);
	reA(var, size, now_pivot_index);
	reB(var, size, now_pivot_index);
	while (sendCount--)
		ft_putstr(pa(var), 1);
}
