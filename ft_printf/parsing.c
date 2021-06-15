/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:52:11 by hyeojung          #+#    #+#             */
/*   Updated: 2021/06/15 18:54:30 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parsing_minus(const char **format, t_flag *flag)
{
	flag->minus = 1;
	(*format)++;
}

void	parsing_zero(const char **format, t_flag *flag)
{
	flag_zero = 1;
	(*format)++;
}

void	parsing_width(const char **format, t_flag *flag, va_list ap)
{
}

void	parsing_prec(const char **format, t_flag *flag, va_list ap)
{
	flag->dog = 1;
	(*format)++;
}
