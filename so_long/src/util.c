/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:11:59 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/06 17:33:32 by hyeojung         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	wd_len(char *s)
{
	int	cnt;

	cnt = 0;
	while (*s++)
		if (*s == '\n')
			cnt++;
	return (cnt);
}

char	**ft_split(t_game *game, char *src)
{
	int		i;
	char	*tmp;
	char	**arr;

	i = 0;
	game->map.row = wd_len(src);
	arr = (char **)malloc(sizeof(char *) * (game->map.row + 1));
	if (!arr)
		print_err("Memory allocation error");
	while (*src)
	{
		tmp = src;
		while (*tmp != '\n')
			tmp++;
		if (*tmp == '\n')
		{
			arr[i] = (char *)malloc(tmp - src + 1);
			ft_strlcat(arr[i], src, tmp - src + 1);
			src += ft_strlen(arr[i++]) + 1;
		}
	}
	arr[i] = 0;
	return (arr);
}
