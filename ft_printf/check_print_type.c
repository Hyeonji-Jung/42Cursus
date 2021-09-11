/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:37:09 by hyeojung          #+#    #+#             */
/*   Updated: 2021/09/11 13:30:05 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_c(t_flag *flag, va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar(c);
	flag->ret++;
	return (0);
}

int	printf_s(t_flag *flag, va_list *ap)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	ft_putstr(s);
	flag->ret += len;
	return (0);
}

int	printf_p(t_flag *flag, va_list *ap)
{
	unsigned long val;

	val = (unsigned long)va_arg(*ap, void *);
	ft_putstr("0x");
	ft_putnbr_hex(val, 'p');
	flag->ret += ft_len(val, 16) + 2;
	return (0);
}

int	printf_per(t_flag *flag)
{
	ft_putchar('%');
	flag->ret++;
	return (0);
}
