/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:30:55 by hyeojung          #+#    #+#             */
/*   Updated: 2021/06/15 21:16:02 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_ret;

static void	init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = -1;
	flag->dot = 0;
	flag->sign = 1;
	flag->prec = -1;
	flag->type = '\0';
}

static int	parsing_format(const char **format, va_list *ap)
{
	t_flag	flag;

	init_flag(&flag);
	while (!ft_strchr(TYPE, **format))
	{
		if (**format == '-')
			parsing_minus(format, &flag);
		else if (**format == '0')
			parsing_zero(format, &flag);
		else if (**format == '*' || ft_strchr(DIGIT, **format))
			parsing_width(format, &flag, ap);
		else if (**format == '.')
			parsing_prec(format, &flag, ap);
		else
			return (-1);
	}
	flag.type = **format;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	g_ret = 0;
	while (*format)
	{
		if (format != '%')
		{
			ft_putchar(*format);
			g_ret++;
			format++;
		}
		else
		{
			if (parsing_format(&(format + 1), &ap) == -1)
				return (-1);
		}
	}
	va_end(ap);
	return (g_ret);
}
