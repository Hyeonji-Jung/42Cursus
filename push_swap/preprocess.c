#include "push_swap.h"

void	preprocess(t_var *var, int argc, char **argv)
{
	int		i;
	int		cnt;

	i = 1;
	cnt = 0;
	while (i < argc)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		cnt += parseArg(var, argv[i], ft_strlen(argv[i])); // 총 노드의 수
		i++;
	}
	var->max_size = cnt;
	putArr(var); // 배열 할당하고 배열에 값 넣어준 후 정렬해줄 예정 ~
}

int	parseArg(t_var *var, char *str, size_t len)
{
	int		i;
	int		n;
	int		ret;
	char	*from;
	char	*to;

	i = 0;
	ret = 0;
	while (i < len)
	{
		from = 0;
		to = 0;
		if (str[i] != ' ')
		{
			from = &str[i];
			while (str[i] && str[i] != ' ')
				i++;
			to = &str[i];
			n = ft_atoi(from, to);
			ret++;
			pushBottom(var->A, getNewNode(n));
		}
		i++;
	}
	return (ret);
}

void	putArr(t_var *var)
{
	int		idx;
	t_node	*p;

	idx = 0;
	var->pivot_arr = (int *)malloc(sizeof(int) * var->max_size);
	p = var->A->top->right;
	while (idx < var->max_size && p != var->A->bottom)
	{
		var->pivot_arr[idx++] = p->val;
		p = p->right;
	}
	radixSort(var->pivot_arr, var->max_size);
	checkDup(var->pivot_arr, var->max_size);
	printf("arr: ");
	for (int i = 0; i < var->max_size; i++)
		printf("%d ", var->pivot_arr[i]);
	printf("\n");
}
