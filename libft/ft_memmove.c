/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:29:53 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/11 15:41:55 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (!dest && !src)
		return (NULL);
	if ((size_t)(dest - src) >= size)
		ft_memcpy(dest, src, size);
	else
		while (size--)
			*((unsigned char*)dest + size) = *((unsigned char*)src + size);
	return (dest);
}
