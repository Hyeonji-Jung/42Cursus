/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:29:53 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/04 16:32:46 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*tmp;
	
	tmp = (char *)malloc(size);
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, src, size);
	ft_memcpy(dest, tmp, size);
	free(tmp);
	return (dest);
}
