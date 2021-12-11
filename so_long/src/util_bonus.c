/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:11:59 by hyeojung          #+#    #+#             */
/*   Updated: 2021/11/25 21:24:07 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_strcpy(t_game *game, char *dest, char *src, int size)
{
	int	i;

	if (!dest || !src)
		print_err(game, MEMERR);
	i = 0;
	while (i < size - 1)
	{
		*(dest++) = *(src++);
		i++;
	}
	*dest = 0;
}

void	print_steps(t_game *game)
{
	ft_putstr("STEPS: ");
	ft_putnbr(game->step);
	write(1, "\n", 1);
}
