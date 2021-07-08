/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:52:11 by hyeojung          #+#    #+#             */
/*   Updated: 2021/07/08 11:07:18 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_minus(const char **format, t_flag *flag)
{
	flag->minus = 1;
	(*format)++;
}

void	parsing_zero(const char **format, t_flag *flag)
{
	flag->zero = 1;
	(*format)++;
}

void	parsing_width(const char **format, t_flag *flag, va_list *ap)
{
	int	n_or_len;

	if (**format == '*')
	{
		n_or_len = va_arg(*ap, int);
		if (n_or_len < 0)
		{
			n_or_len *= -1;
			flag->minus = 1;
		}
		flag->width = n_or_len;
		(*format)++;
	}
	else
	{
		flag->width = ft_atoi(*format, &n_or_len);
		*format += n_or_len;
	}
}

void	parsing_prec(const char **format, t_flag *flag, va_list *ap)
{
	int	n_or_len;

	flag->dot = 1;
	(*format)++;
	if (*(*format++) == '*')
	{
		n_or_len = va_arg(*ap, int);
		if (n_or_len > 0)
			flag->prec = n_or_len;
	}
	else if (ft_strchr(DIGIT, **format) || **format == '0')
	{
		while (**format == '0')
			(*format)++;
		if (!ft_strchr(DIGIT, **format))
			flag->prec = 0;
		else
		{
			flag->prec = ft_atoi(*format, &n_or_len);
			*format += n_or_len;
		}
	}
}
