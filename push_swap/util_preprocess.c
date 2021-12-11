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

void	radixSort(int *a, int cnt) {
	int	result[cnt];
	int bucket[10];
	int	maxValue;
	int	exp;
	int	i;

	maxValue = 0;
	exp = 1;
	i = -1;
	while(++i < cnt)
		if (a[i] > maxValue) maxValue = a[i];
	while (maxValue / exp > 0)
	{
		ft_bzero(bucket, sizeof(int) * 10);
		i = 0;
		while(i < cnt)
			bucket[a[i++] / exp % 10]++;
		i = 0;
		while(++i < 10)
			bucket[i] += bucket[i - 1];
		i = cnt;
		while (i-- >= 0)
			result[--bucket[a[i] / exp % 10]] = a[i];
		i = -1;
		while (i++ < cnt)
			a[i] = result[i];
		exp *= 10;
	}
}

void	checkDup(int *a, int cnt)
{
	int	i;
	int	j;

	i = 0;
	while (i < cnt - 1)
	{
		j = i + 1;
		if (a[i] == a[j])
			ft_error();
		i++;
	}
}
