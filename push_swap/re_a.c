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
	size = get_any_stack_size_a(preSize);
	while (size--)
	{
		if (var->A->top->right->val <= pivot)
		{
			answer++;
			save_list(var, pb(var));
		}
		else
		{
			count++;
			save_list(var, ra(var));
		}
	}
	if (get_stack_size(var->A) != size)
		while (count--)
			save_list(var, rra(var));
	return (answer);
}

void	re_a(t_var *var, int preSize, int prePivotIdx)
{
	int		nowPivotIndex;
	int		size;
	int		sendCount;

	size = get_any_stack_size_a(preSize);
	nowPivotIndex = getPivotIdx_A(size, prePivotIdx);
	if (size <= 3)
	{
		if (size == 2)
		{
			if (var->A->top->right->val > var->A->top->right->right->val)
				save_list(var, sa(var));
		}
		else if (size == 3 && get_stack_size(var->A) != size)
			sort_three_a(var);
		else if (size == 3 && get_stack_size(var->A) == size)
			sort_only_three_a(var);
		return ;
	}
	sendCount = sendHalfElement_A(var, var->pivot_arr[nowPivotIndex], preSize);
	re_a(var, size, nowPivotIndex);
	re_b(var, size, nowPivotIndex);
	while (sendCount--)
		save_list(var, pa(var));
}
