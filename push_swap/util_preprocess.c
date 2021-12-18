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

void quick_sort(int *data, int start, int end)
{
	if(start >= end) // 원소가 1개인 경우 
		return;
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp; 
	while(i <= j)
	{
		// 포인터가 엇갈릴때까지 반복
		while(i <= end && data[i] <= data[pivot])
			i++;
		while(j > start && data[j] >= data[pivot])
			j--;
		if(i > j)
		{ // 엇갈림
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{ // i번째와 j번째를 스왑
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	} // 분할 계산
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
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
