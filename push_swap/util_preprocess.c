#include "push_swap.h"

int		ft_atoi(char *from, char *to)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (to - from > 11)
		ft_error();
	while (from < to && ((*from >= 9 && *from <= 13) || *from == 32))
		from++;
	if (from < to && (*from == '+' || *from == '-'))
	{
		if (*from == '-')
			sign *= -1;
		from++;
	}
	if (*from < '0' || *from > '9')
		ft_error();
	while (from < to && *from >= '0' && *from <= '9')
		num = num * 10 + (*(from++) - '0');
	if (num * sign < INT_MIN || num * sign > INT_MAX)
		ft_error();
	return (num * sign);
}
