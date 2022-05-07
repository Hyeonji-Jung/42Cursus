/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_std1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:36:37 by hyeojung          #+#    #+#             */
/*   Updated: 2022/01/02 17:47:06 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	ft_error(void)
{
	ft_putstr("Error\n", 2);
	exit(1);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_bzero(void *p, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)p;
	while (n--)
	{
		*(ptr++) = 0;
	}
	return ;
}
