/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:13:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/04/16 14:55:37 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**malloc_error(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static int	get_wd_cnt(char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static void	my_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
		*(dest++) = *(from++);
	*dest = 0;
}

static char	**split_sub(char **arr, char *s, char c)
{
	char	*from;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = s;
			while (*s && *s != c)
				++s;
			arr[i] = (char *)malloc(s - from + 1);
			if (!arr)
				return (malloc_error(arr));
			my_strcpy(arr[i++], from, s);
		}
		else
			++s;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	arr = (char **)malloc(sizeof(char *) * (get_wd_cnt(ptr, c) + 1));
	if (!arr)
		return (NULL);
	return (split_sub(arr, ptr, c));
}
