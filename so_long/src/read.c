/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:37:02 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/23 12:53:42 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(t_game *game, char *s, int read_ret)
{
	int		fd;
	char	*buff;
	char	*map;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		print_err(FILEERR);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	map = 0;
	while (read_ret != 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buff);
			print_err(FILEERR);
		}
		buff[read_ret] = 0;
		map = ft_strjoin(map, buff);
	}
	free(buff);
	close(fd);
	game->map.map = ft_split(game, map);
}

void	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest)
		print_err(MEMERR);
	while (*dest && i < size)
	{
		i++;
		dest++;
	}
	if (src)
	{
		while (*src && i + 1 < size)
		{
			*dest = *src;
			i++;
			dest++;
			src++;
		}
	}
	if (i < size)
		*dest = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*new;

	if (!s1 && !s2)
		print_err(MAPERR);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(len + 1);
	if (!new)
		print_err(MEMERR);
	*new = 0;
	ft_strlcat(new, s1, len + 1);
	ft_strlcat(new, s2, len + 1);
	if (s1)
		free(s1);
	return (new);
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
	game->map.row = wd_len(src) + 1;
	arr = (char **)malloc(sizeof(char *) * (game->map.row + 1));
	if (!arr)
		print_err(MEMERR);
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
