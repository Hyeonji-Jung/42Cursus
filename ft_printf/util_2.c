/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:45:08 by hyeojung          #+#    #+#             */
/*   Updated: 2021/09/11 13:01:48 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str, int *len)
{
	int	ret;
	int	sign;
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

void	ft_putnbr(long long n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_putnbr_hex(unsigned long n, char c)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16, c);
	if (c == 'p' || c == 'x')
		ft_putchar("0123456789abcdef"[n % 16]);
	else if (c == 'X')
		ft_putchar("0123456789ABCDEF"[n % 16]);
}
