#include "push_swap.h"
#include "time.h"

void	reB(t_var *var, int depth, int preSize, int prePivotIdx);
void	reA(t_var *var, int depth, int preSize, int prePivotIdx);

int		getPivotIdx_A(int size, int prePivotIdx)
{
	int	gap;

	if (size <=3)
	{
		return prePivotIdx +2;
	}

	gap = size / 2; // getAnystack으로 바꿔야함 TODO

	// 2. 현재 스택 사이즈가 hol수이면 +1
	if (size % 2 == 1)
		gap += 1;

	// 3. 이전 pivot_idx += 2번 결과값
	return (prePivotIdx + gap);
}

int		getPivotIdx_B(int size, int prePivotIdx)
{
	int	gap;

	if (size <=3)
	{
		return prePivotIdx -1;
	}

	gap = size / 2; // getAnystack으로 바꿔야함 TODO

	// 2. 현재 스택 사이즈가 hol수이면 +1
	// if (size % 2 == 1)
	// 	gap += 1;

	// 3. 이전 pivot_idx += 2번 결과값
	return (prePivotIdx - gap);
}

int		sendHalfElement_A(t_var *var, int depth, int pivot, int preSize)
{
	int	size;
	int count;
	int answer;

	count = 0;
	answer = 0;
	size = getAnyStackSize_A(var, depth, preSize);
	// printf("in send half A depth : %d\n", depth);
	// printf("in send half A size : %d\n", size);
	// printf("in send half A pivot : %d\n", pivot);
	// printf("var->A->top->right->val : %d\n", var->A->top->right->val);
	// 피봇 기준으로 보내거나 내리기
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

	// 내린 개수만큼 올리기 -> 현재 스택 사이즈랑 전체 스택 사이즈 같을 경우 필요없음
	if (getStackSize(var->A) != size)
		while (count--)
			ft_putstr(rra(var), 1);
	return (answer);
}

int		sendHalfElement_B(t_var *var, int depth, int pivot, int preSize)
{
	int	size;
	int count;
	int answer;

	count = 0;
	answer = 0;
	size = getAnyStackSize_B(var, depth, preSize);
	// printf("in send half B depth : %d\n", depth);
	// printf("in send half B size : %d\n", size);
	// printf("in send half A pivot : %d\n", pivot);
	// 피봇 기준으로 보내거나 내리기
	while (size--)
	{
		if (var->B->top->right->val > pivot){
			answer++;
			ft_putstr(pa(var), 1);
		}
		else
		{
			count++;
			ft_putstr(rb(var), 1);
		}
	}
	// 내린 개수만큼 올리기 -> 현재 스택 사이즈랑 전체 스택 사이즈 같을 경우 필요없음
	if (getStackSize(var->B) != size)
		while (count--)
			ft_putstr(rrb(var), 1);
	
	return (answer);
}

int		sendHalfElement_init(t_var *var, int pivot)
{
	int	size;
	int count;

	count = 0;
	size = var->max_size;
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
	// 내린 개수만큼 올리기 -> 현재 스택 사이즈랑 전체 스택 사이즈 같을 경우 필요없음
	if (getStackSize(var->A) != size)
		while (count--)
			ft_putstr(rra(var), 1);
	
	return (0);
}

void	reB(t_var *var, int depth, int preSize, int prePivotIdx)
{
	// printf("===B===\n");
	t_stack	*nowStack;
	int		now_pivot_index;
	int		size;
	int		sendCount;


	size = getAnyStackSize_B(var, depth, preSize);
	// printf("preSize : %d\n", preSize);
	// printf("prePivotIdx : %d\n", prePivotIdx);
	now_pivot_index = getPivotIdx_B(size, prePivotIdx);
	// printf("now_pivot_index : %d\n", now_pivot_index);
	// printf("depth : %d\n", depth);
	// printf("size : %d\n", size);

	if (size <= 2)
	{
		if (size <= 1)
			return ;
		if (var->B->top->right->val < var->B->top->right->right->val)
			ft_putstr(sb(var), 1);
		return ;
	}

	// 다른 스택에 현재 스택의 반 보내기
	// pivot_index = getPivot(var, curStack, depth, prePivotIdx); //@@@@@@@@@@
	
	sendCount = sendHalfElement_B(var, depth, var->pivot_arr[now_pivot_index], preSize);
	// printStack_test(var->A);
	// 	printStack_test(var->B);
	reA(var, depth + 1, size, now_pivot_index);
	reB(var, depth + 1, size, now_pivot_index);

	// A -> B
	// printf("===B %d 끝나따===\n", depth);
	while (sendCount--)
		ft_putstr(pb(var), 1);

	// printStack_test(var->A);
	// printStack_test(var->B);
}

void	reA(t_var *var, int depth, int preSize, int prePivotIdx)
{
	// printf("===A===\n");
	t_stack	*nowStack;
	int		now_pivot_index;
	int		size;
	int		sendCount;


	size = getAnyStackSize_A(var, depth, preSize);
	// printf("preSize : %d\n", preSize);
	// printf("prePivotIdx : %d\n", prePivotIdx);
	now_pivot_index = getPivotIdx_A(size, prePivotIdx);
	// printf("now_pivot_index : %d\n", now_pivot_index);
	// printf("size : %d\n", size);

	if (size <= 2)
	{
		if (size <= 1)
			return ;
		//A면 오름차순정렬
		if (var->A->top->right->val > var->A->top->right->right->val)
			ft_putstr(sa(var), 1);
		return ;
	}

	// 다른 스택에 현재 스택의 반 보내기
	// pivot_index = getPivot(var, curStack, depth, prePivotIdx); //@@@@@@@@@@
	
	sendCount = sendHalfElement_A(var, depth, var->pivot_arr[now_pivot_index], preSize);
	// printStack_test(var->A);
	// 	printStack_test(var->B);
	reA(var, depth + 1, size, now_pivot_index);
	reB(var, depth + 1, size, now_pivot_index);

	// B -> A
	// printf("===A %d 끝나따===\n", depth);
	while (sendCount--)
		ft_putstr(pa(var), 1);
	
		// printStack_test(var->A);
		// printStack_test(var->B);
}

void	re(t_var *var)
{
	t_stack	*nowStack;
	int		now_pivot_index;
	int		size;
	
	if (var->max_size <= 2)
	{
		if (var->max_size <= 1)
			return ;
		if (var->A->top->right->val > var->A->top->right->right->val)
			ft_putstr(sa(var), 1);
		return ;
	}

	// 다른 스택에 현재 스택의 반 보내기
	now_pivot_index = var->max_size / 2;
	if (var->max_size % 2 == 0)
		now_pivot_index -= 1;
	

	// 피봇 기준으로 보내거나 내리기
	sendHalfElement_init(var, var->pivot_arr[now_pivot_index]);
	// printStack_test(var->A);
	// 	printStack_test(var->B);
	// printf("now_pivot_index : %d\n", now_pivot_index);
	// printf("size : %d\n", var->max_size);
				
	reA(var, 1, var->max_size, now_pivot_index);
	reB(var, 1, var->max_size, now_pivot_index);

	// B -> A
	size = var->max_size / 2;
	if (var->max_size % 2 == 1)
		size += 1;
	while (size--)
			ft_putstr(pa(var), 1);
}

int		main(int argc, char *argv[])
{
	t_var var;
	
	if (argc >= 2)
	{
		initStack(&var);
		preprocess(&var, argc, argv);
		// printStack_test(var.A);
		// printStack_test(var.B);
		re(&var);
		// printStack_test(var.A);
		// printStack_test(var.B);
		// 여기에 써보자
	}
	else
		ft_error();
	exit(0);
}