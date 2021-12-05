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

size_t		ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}