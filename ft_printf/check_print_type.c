/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:37:09 by hyeojung          #+#    #+#             */
/*   Updated: 2021/07/08 18:22:39 by hyeojung         ###   ########.fr       */
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
	(void)flag;
	(void)ap;
	return (0);
}

int	printf_p(t_flag *flag, va_list *ap)
{
	(void)flag;
	(void)ap;
	return (0);
}

int	printf_per(t_flag *flag, va_list *ap)
{
	(void)flag;
	(void)ap;
	ft_putchar('%');
	return (0);
}
