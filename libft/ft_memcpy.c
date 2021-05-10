/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:24:01 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/10 15:43:06 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	if (!dest && !src)
		return (0);
	i = 0;
	ptr1 = (char*)dest;
	ptr2 = (char*)src;
	while (i < size)
	{
		*(ptr1 + i) = *(ptr2 + i);
		i++;
	}
	return (dest);
}
