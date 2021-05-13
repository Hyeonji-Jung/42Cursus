/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:03:36 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/13 12:41:25 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(substr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	len = ft_strlen(s + start) < len ? ft_strlen(s + start) : len;
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
