#include "push_swap.h"

int		ft_atoi(char *from, char *to)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
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
	return (num * sign);
}

void	ft_bzero(void *p, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)p;
	while (n--)
	{
		*(ptr++) = 0;
	}
	return ;
}


// void	*ft_bzero(void *dest, size_t size)
// {
// 	return (ft_memset(dest, 0, size));
// }

// void	*ft_memset(void *dest, int c, size_t size)
// {
// 	unsigned char	*tmp;
// 	size_t			i;

// 	tmp = (unsigned char *)dest;
// 	i = 0;
// 	while (i < size)
// 		tmp[i++] = (unsigned char)c;
// 	return (tmp);
// }
