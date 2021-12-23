#include "push_swap.h"

static int	getPivotIdx_B(int size, int prePivotIdx)
{
	int	gap;

	if (size <= 3)
		return (prePivotIdx - 1);
	gap = size / 2;
	return (prePivotIdx - gap);
}

static int	sendHalfElement_B(t_var *var, int pivot, int preSize)
{
	int	size;
	int	count;
	int	answer;

	count = 0;
	answer = 0;
	size = get_any_stack_size_b(preSize);
	while (size--)
	{
		if (var->B->top->right->val > pivot)
		{
			answer++;
			save_list(var, pa(var));
		}
		else
		{
			count++;
			save_list(var, rb(var));
		}
	}
	if (get_stack_size(var->B) != size)
		while (count--)
			save_list(var, rrb(var));
	return (answer);
}

void	re_b(t_var *var, int preSize, int prePivotIdx)
{
	int		nowPivotIndex;
	int		size;
	int		sendCount;

	size = get_any_stack_size_b(preSize);
	nowPivotIndex = getPivotIdx_B(size, prePivotIdx);
	if (size <= 3)
	{
		if (size == 2)
		{
			if (var->B->top->right->val < var->B->top->right->right->val)
				save_list(var, sb(var));
		}
		else if (size == 3 && get_stack_size(var->B) != size)
			sort_three_b(var);
		else if (size == 3 && get_stack_size(var->B) == size)
			sort_only_three_b(var);
		return ;
	}
	sendCount = sendHalfElement_B(var, var->pivot_arr[nowPivotIndex], preSize);
	re_a(var, size, nowPivotIndex);
	re_b(var, size, nowPivotIndex);
	while (sendCount--)
		save_list(var, pb(var));
}
