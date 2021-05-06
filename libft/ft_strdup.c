/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:26:48 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/06 17:53:42 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	len;
	char			*ret;

	len = (unsigned int)ft_strlen(str);
	ret = (char*)malloc(len + 1);
	ret[len] = 0;
	while (--len >= 0)
		ret[len] = str[len];
	return (ret);
}
