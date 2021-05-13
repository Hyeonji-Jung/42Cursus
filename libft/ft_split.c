/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:47:08 by hyeojung          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:41 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**malloc_error(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static int			get_wd_cnt(char *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		++s;
	}
	return (cnt);
}

static void			my_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
		*(dest++) = *(from++);
	*dest = 0;
}

static char			**split_sub(char **arr, char *s, char c)
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
			if (!(arr[i] = (char*)malloc(s - from + 1)))
				return (malloc_error(arr));
			my_strcpy(arr[i++], from, s);
		}
		++s;
	}
	arr[i] = NULL;
	return (arr);
}

char				**ft_split(char const *s, char c)
{
	char	**arr;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char*)s;
	if (!(arr = (char**)malloc((sizeof(char*) * get_wd_cnt(ptr, c)) + 1)))
		return (NULL);
	return (split_sub(arr, ptr, c));
}
