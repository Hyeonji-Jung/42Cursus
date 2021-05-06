/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:52:41 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/06 15:26:00 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (i < size)
	{
		((char*)dest)[i] = ((char*)src)[i];
		if (((char*)src)[i++] == c)
		{
			flag = 1;
			break ;
		}
	}
	if (flag)
		return (dest);
	else
		return (NULL);
}
