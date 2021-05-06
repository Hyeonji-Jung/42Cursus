/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:56:10 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/06 17:55:17 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = (char*)find;
	i = 0;
	if (!*find)
		return ((char*)str);
	while (*str && ++i <= size)
	{
		if (*str == *find)
		{
			str++;
			find++;
			if (!*find)
				return ((char*)str - ((char*)find - tmp));
		}
		else
		{
			str++;
			find = tmp;
		}
	}
	return (NULL);
}
