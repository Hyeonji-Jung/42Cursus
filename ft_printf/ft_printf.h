/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:32:32 by hyeojung          #+#    #+#             */
/*   Updated: 2021/09/11 14:38:18 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define TYPE "cspdiuxX%"

typedef struct s_flag
{
	char		type;
	int			ret;
}				t_flag;

int				ft_printf(const char *format, ...);
int				ft_strchr(const char *s, char c);
int				printf_c(t_flag *flag, va_list *ap);
int				printf_s(t_flag *flag, va_list *ap);
int				printf_p(t_flag *flag, va_list *ap);
int				printf_int(t_flag *flag, va_list *ap);
int				printf_u(t_flag *flag, va_list *ap);
int				printf_x(t_flag *flag, va_list *ap);
int				printf_per(t_flag *flag);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(long long n);
void			ft_putnbr_hex(unsigned long n, char c);

size_t			ft_strlen(char *s);
size_t			ft_len(unsigned long n, int base);


#endif
