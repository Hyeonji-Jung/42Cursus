#include "push_swap.h"

static int	sendHalfElement_init(t_var *var, int pivot)
{
	int	size;
	int	count;

	count = 0;
	size = var->max_size;
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
	return (0);
}

static void	re(t_var *var)
{
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
	now_pivot_index = var->max_size / 2;
	if (var->max_size % 2 == 0)
		now_pivot_index -= 1;
	sendHalfElement_init(var, var->pivot_arr[now_pivot_index]);
	reA(var, var->max_size, now_pivot_index);
	reB(var, var->max_size, now_pivot_index);
	size = var->max_size / 2;
	if (var->max_size % 2 == 1)
		size += 1;
	while (size--)
		ft_putstr(pa(var), 1);
}

int	main(int argc, char *argv[])
{
	t_var	var;

	if (argc >= 2)
	{
		initStack(&var);
		preprocess(&var, argc, argv);
		re(&var);
	}
	else
		ft_error();
	exit(0);
}
