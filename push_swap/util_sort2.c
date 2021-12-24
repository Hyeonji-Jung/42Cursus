#include "push_swap.h"

void	sort_three_b_temp(t_var *var)
{
	save_list(var, rb(var));
	save_list(var, sb(var));
	save_list(var, rrb(var));
}
