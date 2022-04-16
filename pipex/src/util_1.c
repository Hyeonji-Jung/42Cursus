/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:04:04 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/16 17:13:53 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	new = (char *)malloc((len + 1));
	if (!new)
		return (NULL);
	*new = 0;
	ft_strlcat(new, s1, len + 1);
	ft_strlcat(new, s2, len + 1);
	return (new);
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

int	ft_strncmp(char *s1, char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (!s1[i] || !s2[i])
			break ;
		i++;
	}
	return (0);
}

char	*ft_strnstr(char *str, char *find, size_t size)
{
	size_t	find_len;

	find_len = ft_strlen(find);
	if (*find)
	{
		if (size == 0)
			return (NULL);
		while (ft_strncmp(str, find, find_len) != 0 && size--)
		{
			if (!*str || size < find_len)
				return (NULL);
			str++;
		}
	}
	return ((char *)str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
