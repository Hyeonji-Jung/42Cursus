/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:41:44 by hyeojung          #+#    #+#             */
/*   Updated: 2021/09/11 14:42:59 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(t_flag *flag, va_list *ap)
{
	long long	val;

	val = va_arg(*ap, int);
	ft_putnbr(val);
	if (val < 0)
	{
		flag->ret++;
		val *= -1;
	}
	flag->ret += ft_len(val, 10);
	return (0);
}

int	printf_u(t_flag *flag, va_list *ap)
{
	unsigned long	val;

	val = va_arg(*ap, unsigned int);
	ft_putnbr(val);
	flag->ret += ft_len(val, 10);
	return (0);
}

int	printf_x(t_flag *flag, va_list *ap)
{
	unsigned int	val;

	val = va_arg(*ap, int);
	ft_putnbr_hex(val, flag->type);
	flag->ret += ft_len(val, 16);
	return (0);
}
