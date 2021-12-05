#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_var var;
	
	if (argc >= 2)
	{
		printf("111111\n");
		initStack(&var);
		printf("222222\n");

		printf("A:::%p\n", var.A);
		pushTop(var.A, getNewNode(1));
		pushTop(var.A, getNewNode(2));
		pushTop(var.A, getNewNode(3));
		pushTop(var.A, getNewNode(4));
		printStack_test(var.A);
		printf("B:::%p\n", var.B);
		pushTop(var.B, getNewNode(4));
		pushTop(var.B, getNewNode(3));
		pushTop(var.B, getNewNode(2));
		pushTop(var.B, getNewNode(1));
		printStack_test(var.B);

		printf("33333333\n");
		printf("%p %d %p\n", &var, argc, &argv);
		preprocess(&var, argc, argv);
		printf("44444444\n");
		printStack_test(var.A);
		printf("5555555\n");
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