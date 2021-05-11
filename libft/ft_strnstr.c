/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:56:10 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/11 16:58:14 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t size)
{
	size_t	find_len;

	find_len = ft_strlen(find);
	if (*find)
	{
		if (size == 0)
			return (NULL);
		while (ft_strncmp(str, find, find_len) != 0 && size--)
		{
			if (!*str || size < find_len)
				return (NULL);
			str++;
		}
	}
	return ((char*)str);
}
