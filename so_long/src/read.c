/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:37:02 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/28 17:37:59 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(t_game *game, char *s, int read_ret)
{
	int		fd;
	char	buff[BUFFER_SIZE + 1];
	char	*map;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		print_err(game, FILEERR);
	map = 0;
	while (read_ret)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buff);
			print_err(game, FILEERR);
		}
		buff[read_ret] = 0;
		map = ft_strjoin(game, map, buff);
	}
	if (*buff)
		free(buff);
	close(fd);
	game->map.map = ft_split(game, map);
}

char	*ft_strjoin(t_game *game, char *s1, char *s2)
{
	int		len;
	char	*new;

	if (!s1 && !s2)
		print_err(game, MAPERR);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		print_err(game, MEMERR);
	*new = 0;
	ft_strlcat(game, new, s1, len + 1);
	ft_strlcat(game, new, s2, len + 1);
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
		print_err(game, MEMERR);
	while (*src)
	{
		if (*src != '\n')
		{
			tmp = src;
			while (*src && *src != '\n')
				src++;
			arr[i] = (char *)malloc(src - tmp + 1);
			if (!arr[i])
				print_err(game, MEMERR);
			ft_strlcat(game, arr[i++], tmp, src - tmp + 1);
		}
		src++;
	}
	arr[i] = 0;
	return (arr);
}
