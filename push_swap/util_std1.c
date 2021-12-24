#include "push_swap.h"

void	ft_putstr(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	ft_error(void)
{
	ft_putstr("Error\n", 2);
	exit(1);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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

t_node	*max_node(t_node *t1, t_node *t2, t_node *t3)
{
	if (t1->val < t2->val)
	{
		if (t2->val < t3->val)
			return (t3);
		else
			return (t2);
	}
	else if (t2->val < t3->val)
	{
		if (t3->val < t1->val)
			return (t1);
		else
			return (t3);
	}
	else
	{
		if (t2->val < t1->val)
			return (t1);
		else
			return (t2);
	}
}
