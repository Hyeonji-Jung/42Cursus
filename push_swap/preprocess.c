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
		cnt += parseArg(var, argv[i], ft_strlen(argv[i]));
		i++;
	}
	sortArr(var, cnt);
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

void	sortArr(t_var *var, int cnt)
{
	int		idx;
	t_node	*p;

	idx = 0;
	var->pivot_arr = (int *)malloc(sizeof(int) * cnt);
	p = var->A->top->right;
	while (idx < cnt && p != var->A->bottom)
	{
		var->pivot_arr[idx++] = p->val;
		p = p->right;
	}
}
