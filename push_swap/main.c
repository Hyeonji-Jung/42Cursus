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


/*재귀함수*/

/*파싱함수*/ // parsing.c

/*배열정렬함수*/

/*2개?*/

/*!2개?*/

/*ra등등 명령어*/

/*피봇 뽑기*/