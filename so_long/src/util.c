/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:11:59 by hyeojung          #+#    #+#             */
/*   Updated: 2021/11/21 19:30:06 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483647)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
		if (n)
		{
			ft_putnbr(n / 10);
			c = n % 10 + '0';
			write(1, &c, 1);
		}
	}
}

void	ft_strlcat(t_game *game, char *dest, char *src, size_t size)
{
	size_t	i;

	if (!dest)
		print_err(game, MEMERR);
	i = 0;
	while (*dest && i < size)
	{
		i++;
		dest++;
	}
	while (src && *src && i + 1 < size)
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	if (i < size)
		*dest = 0;
}

void	print_steps(t_game *game)
{
	ft_putstr("STEPS: ");
	ft_putnbr(game->step);
	write(1, "\n", 1);
}
