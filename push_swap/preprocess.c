#include "push_swap.h"

void	preprocess(t_var *var, int argc, char **argv)
{
	printf("a\n");
	ft_putstr("hey\n", 1);
	int		i;
	int		cnt;
	char	pos[MAX_ARR];
	char	neg[MAX_ARR];

	i = 1;
	cnt = 0;
	ft_bzero(pos, MAX_ARR);
	printf("a\n");
	ft_bzero(neg, MAX_ARR);
	printf("b\n");
	while (i < argc)
		cnt += parseArg(var, argv[i++], pos, neg);
	sortArr(var, pos, neg, cnt);
}

int	parseArg(t_var *var, char *str, char *pos, char *neg)
{
	int		i;
	int		n;
	int		ret;
	char	*from;
	char	*to;

	i = 0;
	ret = 0;
	while (str[i++])
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
			checkArg(pos, neg, n);
			ret++;
			pushBottom(var->A, getNewNode(n));
		}
	}
	return (ret);
}

void	checkArg(char *pos, char *neg, int n)
{
	if (n == INT_MIN && !neg[INT_MAX])
		neg[INT_MAX] = 1;
	else if (n < 0 && !neg[(n * -1) - 1])
		neg[(n * -1) - 1] = 1;
	else if (n >= 0 && !pos[n])
		pos[n] = 1;
	else
		ft_error();
}

void	sortArr(t_var *var, char *pos, char *neg, int cnt)
{
	int	idx;
	int	i;

	idx = 0;
	i = 0;
	var->pivot_arr = (int *)malloc(sizeof(int) * cnt);
	while (i++ < MAX_ARR - 1)
		if (neg[i])
			var->pivot_arr[idx++] = neg[i];
	i = 0;
	while (i++ < MAX_ARR - 1)
		if (pos[i])
			var->pivot_arr[idx++] = pos[i];
}
