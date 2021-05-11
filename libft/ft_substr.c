/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:03:36 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/11 21:43:42 by hwso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(sizeof(char), 1));
	substr = (char*)ft_calloc(sizeof(char), len + 1);
	len = len < ft_strlen(s + start) ? len : ft_strlen(s + start);
	i = 0;
	while (len--)
		*(substr + i++) = *(s + start++);
	return (substr);
}
