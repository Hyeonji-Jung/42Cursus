/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:05:50 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/04 13:38:46 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)dest;
	i = 0;
	while (i < size)
		tmp[i++] = (unsigned char)c;
	return (tmp);
}
