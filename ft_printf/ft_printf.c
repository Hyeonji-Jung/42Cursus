/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:30:55 by hyeojung          #+#    #+#             */
/*   Updated: 2021/06/16 17:16:35 by hyeojung         ###   ########.fr       */
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

static int	recog_type(t_flag *flag, va_list *ap)
{
	if (flag->type == 'c')
		return (printf_c(flag, ap));
	else if (flag->type == 's')
		return (printf_s(flag, ap));
	else if (flag->type == 'p')
		return (printf_p(flag, ap));
	else if (flag->type == 'd' || flag->type == 'i')
		return (printf_int(flag, ap));
	else if (flag->type == 'x' || flag->type == 'X')
		return (printf_hex(flag, ap));
	else if (flag->type == '%')
		return (printf_per(flag, ap));
	else
		return (-1);
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
	(*format)++;
	return (recog_type(&flag, ap));
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	g_ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			g_ret++;
			format++;
		}
		else
		{
			format++;
			if (parsing_format(&format, &ap) == -1)
				return (-1);
		}
	}
	va_end(ap);
	return (g_ret);
}
