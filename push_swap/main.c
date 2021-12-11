#include "push_swap.h"


int		main(int argc, char *argv[])
{
	t_var var;
	
	if (argc >= 2)
	{
		initStack(&var);
		preprocess(&var, argc, argv);
		printStack_test(var.A);
		printStack_test(var.B);
		re(&var, S_A, 0, var.max_size - 1);
		// 여기에 써보자
	}
	else
		ft_error();
	return (0);
	//info initial done
	//매개변수 파싱 ing
	//배열이랑 스택에 저장
	//배열 정렬
	//재귀 호출
}


int		getPivot(t_var *var, int curStack, int depth, int prePivotIdx)
{
	int	pivotIdx;

	pivotIdx = prePivotIdx / 2;
	if ((prePivotIdx + 1) % 2 == 1) // isOdd
		pivotIdx += 1;
	if (curStack == S_A)
		pivotIdx += prePivotIdx;
	return (var->pivot_arr[pivotIdx]);
}

void	sendHalfElement(t_var *var, int curStack, int depth, int prePivotIdx)
{
	int	pivot = getPivot(var, curStack, depth, prePivotIdx);
	int	size = getCurStackSize(var, depth);

	if (curStack == S_A)
	{
		// 피봇 기준으로 보내거나 내리기
		// 내린 개수만큼 올리기 -> 현재 스택 사이즈랑 전체 스택 사이즈 같을 경우 필요없음
	}
	else
	{

	}
	//피봇 정하고
	//current에 따라, 작거나 같은걸 B로 보내던가 큰걸 A로 보내거나
}

void	re(t_var *var, int curStack, int depth, int prePivotIdx)
{
	t_stack	*nowStack;
	// t_stack	*otherStack;

	nowStack = var->A;
	if (curStack == S_B)
		nowStack = var->B;
	if (getStackSize(nowStack) <= 2)
	{
		//정렬하고 return
		return ;
	}
	else
	{
		//다른 스택에 현재 스택의 반 보내기
		sendHalfElement(var, curStack, depth, prePivotIdx);
	}
}
