/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:56:14 by hyeojung          #+#    #+#             */
/*   Updated: 2021/06/16 13:17:28 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*(s++) == c)
			return (1);
	}
	return (0);
}

int		ft_atoi(const char *str, int *len)
{
	int	ret;
	int sign;
	int	i;

	ret = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i] == '-')
			sign *= -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret = ret * 10 + str[i] - '0';
		else
			break ;
	}
	*len = i;
	return (ret * sign);
}
