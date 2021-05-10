/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:52:41 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/10 16:13:15 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t			i;
	unsigned char	find;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	find = (unsigned char)c;
	ptr1 = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	while (i < size)
	{
		*(ptr1 + i) = *(ptr2 + i);
		if (*(ptr2 + i) == find)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
