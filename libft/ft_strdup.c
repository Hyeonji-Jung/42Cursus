/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:26:48 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/11 15:46:24 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int				len;
	char			*ret;

	len = ft_strlen(str);
	ret = (char*)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (--len >= 0)
		ret[len] = str[len];
	return (ret);
}
