/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:32:32 by hyeojung          #+#    #+#             */
/*   Updated: 2021/07/08 11:27:47 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define DIGIT "123456789"
# define TYPE "cspdiuxX%"

typedef struct s_flag
{
	int			minus;
	int			zero;
	long long	width;
	int			dot;
	int			sign;
	long long	prec;
	char		type;
	int			ret;
}				t_flag;

int				ft_printf(const char *format, ...);
int				ft_strchr(const char *s, char c);
int				ft_atoi(const char *str, int *len);
int				printf_c(t_flag *flag, va_list *ap);
int				printf_s(t_flag *flag, va_list *ap);
int				printf_p(t_flag *flag, va_list *ap);
int				printf_per(t_flag *flag, va_list *ap);
int				printf_int(t_flag *flag, va_list *ap);
int				printf_hex(t_flag *flag, va_list *ap);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			parsing_minus(const char **format, t_flag *flag);
void			parsing_zero(const char **format, t_flag *flag);
void			parsing_width(const char **format, t_flag *flag, va_list *ap);
void			parsing_prec(const char **format, t_flag *flag, va_list *ap);

#endif
