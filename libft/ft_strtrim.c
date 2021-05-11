/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:58:54 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/11 18:55:24 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	ptr = (char*)s1 + ft_strlen(s1);
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1++;
	}
	while (ptr >= s1)
	{
		if (!ft_strchr(set, *ptr))
			break ;
		ptr--;
	}
	trim = (char*)malloc(++ptr - s1 + 1);
	ft_strlcpy(trim, s1, ptr - s1 + 1);
	return (trim);
}
