/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:11:59 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/05 21:50:55 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		wd_len(char *s)
{
	int	cnt;

	cnt = 0;
	while (*s++)
		if (*s == '\n')
			cnt++;
	return (cnt);
}

char	**ft_split(char *src)
{
	int		i;
	char	*tmp;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (wd_len(src) + 1));
	while (*src)
	{
		tmp = src;
		while (*tmp != '\n')
			tmp++;
		if (*tmp == '\n')
		{
			arr[i] = (char *)malloc(tmp - src + 1);
			ft_strlcat(arr[i++], src, tmp - src);
			src += tmp - src;
		}
	}
	for (int j = 0; j < wd_len(src) + 1; j++)
		ft_putstr(arr[j]);
	return (0);
}