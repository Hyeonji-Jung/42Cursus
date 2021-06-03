/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:16:53 by hyeojung          #+#    #+#             */
/*   Updated: 2021/06/03 13:21:43 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		is_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (*(str++) == '\n')
			return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dest && i < size)
	{
		i++;
		dest++;
	}
	if (src)
		while (*src && i + 1 < size)
		{
			*dest = *src;
			i++;
			dest++;
			src++;
		}
	if (i < size)
		*dest = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*new;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen((const char*)s1) + ft_strlen((const char*)s2);
	new = (char*)malloc((len + 1));
	if (!new)
		return (NULL);
	*new = 0;
	ft_strlcat(new, (char*)s1, len + 1);
	ft_strlcat(new, (char*)s2, len + 1);
	if (s1)
		free(s1);
	return (new);
}
