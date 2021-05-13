/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:28:54 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/13 13:46:22 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	subfunc_len(int n)
{
	int	len;

	len = n <= 0 ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		sign;

	len = subfunc_len(n);
	num = (char*)ft_calloc(sizeof(char), len + 1);
	if (!num)
		return (NULL);
	*num = n < 0 ? '-' : '0';
	sign = n < 0 ? -1 : 1;
	while (n)
	{
		num[--len] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (num);
}
