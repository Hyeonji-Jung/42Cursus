/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:25:01 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/13 13:46:03 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_nbr(long long n, int fd)
{
	if (n >= 10)
		write_nbr(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (fd < 0)
		return ;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	write_nbr(num, fd);
}
