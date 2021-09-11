/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:30:55 by hyeojung          #+#    #+#             */
/*   Updated: 2021/09/11 14:18:14 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (flag->type == 'u')
		return (printf_u(flag, ap));
	else if (flag->type == 'x' || flag->type == 'X')
		return (printf_x(flag, ap));
	else if (flag->type == '%')
		return (printf_per(flag));
	else
		return (-1);
}

static int	parsing_format(const char **format, va_list *ap, t_flag *flag)
{
	flag->type = '\0';
	if (ft_strchr(TYPE, **format))
		(*flag).type = **format;
	else
		return (-1);
	(*format)++;
	return (recog_type(flag, ap));
}

int	ft_printf(const char *format, ...)
{
	t_flag	flag;
	va_list	ap;

	flag.ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			flag.ret++;
			format++;
		}
		else
		{
			format++;
			if (parsing_format(&format, &ap, &flag) == -1)
				return (-1);
		}
	}
	va_end(ap);
	return (flag.ret);
}
