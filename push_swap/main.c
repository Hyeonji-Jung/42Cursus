#include "push_swap.h"
#include "time.h"

int		getPivotIdx(t_var *var, int curStack, int prePivotIdx)
{
	int	size;

	// 1. 현재 스택 사이즈 / 2
	if (curStack == S_A)
		size = getStackSize(var->A);
	else
		size = getStackSize(var->B);

	// 2. 현재 스택 사이즈가 짝수이면 -1
	if (size % 2 == 0)
		size -= 1;

	// 3. 이전 pivot_idx += 2번 결과값
	if (curStack == S_A)
		return (prePivotIdx - size); 
	return (prePivotIdx + size); 
}

int		sendHalfElement(t_var *var, int curStack, int depth, int pivot)
{
	int	size;
	int count;

	count = 0;
	size = getAnyStackSize(var, curStack, depth);
	if (curStack == S_A)
	{
		// 피봇 기준으로 보내거나 내리기
		while (size--)
		{
			if (var->A->top->right->val <= pivot)
				ft_putstr(pb(var), 1);
			else
			{
				count++;
				ft_putstr(ra(var), 1);
			}
		}
		if (getStackSize(var->A) != size)
			while (count--)
				ft_putstr(rra(var), 1);
		// 내린 개수만큼 올리기 -> 현재 스택 사이즈랑 전체 스택 사이즈 같을 경우 필요없음
	}
	else if (curStack == S_B)
	{
		// 피봇 기준으로 보내거나 내리기
		while (size--)
		{
			if (var->B->top->right->val > pivot)
				ft_putstr(pa(var), 1);
			else
			{
				count++;
				ft_putstr(rb(var), 1);
			}
		}
		if (getStackSize(var->B) != size)
			while (count--)
				ft_putstr(rrb(var), 1);
		// 내린 개수만큼 올리기 -> 현재 스택 사이즈랑 전체 스택 사이즈 같을 경우 필요없음
	}
	return (0);
}

void	re(t_var *var, int curStack, int depth, int prePivotIdx)
{

	printStack_test(var->A);
	printStack_test(var->B);
	usleep(1000000);
	t_stack	*nowStack;
	int		now_pivot_index;
	int		size;

	if (getAnyStackSize(var, curStack, depth) <= 2)
	{
		if (getAnyStackSize(var, curStack, depth) <= 1)
			return ;
		//A면 오름차순정렬
		if (curStack == S_A)
		{
			if (var->A->top->right->val > var->A->top->right->right->val)
				ft_putstr(sa(var), 1);
		}
		//B면 내림차순정렬
		else
			if (var->B->top->right->val < var->B->top->right->right->val)
				ft_putstr(sb(var), 1);
		return ;
	}

	// 다른 스택에 현재 스택의 반 보내기
	// pivot_index = getPivot(var, curStack, depth, prePivotIdx); //@@@@@@@@@@
	now_pivot_index = getPivotIdx(var, curStack, prePivotIdx);
	
	sendHalfElement(var, curStack, depth, var->pivot_arr[now_pivot_index]);
	re(var, S_A, depth + 1, now_pivot_index);
	re(var, S_B, depth + 1, now_pivot_index);

	// B -> A
	size = getAnyStackSize(var, curStack, depth + 1);
	printf("B -> A size : %d\n", size);
	if (curStack == S_A)
	{
		while (size--)
			ft_putstr(pa(var), 1);
		printf("in 1111111\n");
	}
	if (curStack == S_B)
	{
		while (size--)
			ft_putstr(pb(var), 1);
		printf("in 2222222\n");
	}
	printStack_test(var->A);
	printStack_test(var->B);
	printf("\n\n");
}

int		main(int argc, char *argv[])
{
	t_var var;
	
	if (argc >= 2)
	{
		// initStack(&var);
		// preprocess(&var, argc, argv);
		// printStack_test(var.A);
		// printStack_test(var.B);
		// re(&var, S_A, 0, var.max_size - 1);
		// printStack_test(var.A);
		// printStack_test(var.B);
		// 여기에 써보자
	}
	else
		ft_error();
	exit(0);
}