/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:04:04 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/16 14:56:34 by hyeojung         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_err(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
