#include "push_swap.h"

void	preprocess(t_var *var, int argc, char **argv)
{
	int		i;
	int		cnt;

	i = 1;
	cnt = 0;
	while (i < argc)
	{
		cnt += parse_arg(var, argv[i], ft_strlen(argv[i]));
		i++;
	}
	var->max_size = cnt;
	put_arr(var);
}

int	parse_arg(t_var *var, char *str, int len)
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
			push_bottom(var->A, get_new_node(n));
		}
		i++;
	}
	return (ret);
}

static void	checkSorted(t_var *var)
{
	int		idx;
	t_node	*p;

	idx = 0;
	p = var->A->top->right;
	while (idx < var->max_size)
	{
		if (var->pivot_arr[idx] != p->val)
			return ;
		idx++;
		p = p->right;
	}
	if (idx == var->max_size)
		exit(0);
}

void	put_arr(t_var *var)
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
	quick_sort(var->pivot_arr, 0, var->max_size - 1);
	check_dup(var->pivot_arr, var->max_size);
	checkSorted(var);
}
