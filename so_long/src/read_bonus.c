/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:37:02 by hyeojung          #+#    #+#             */
/*   Updated: 2021/11/25 21:23:52 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			print_err(game, FILEERR);
		buff[read_ret] = 0;
		map = ft_strjoin(game, map, buff);
	}
	if (*buff)
		free(buff);
	close(fd);
	ft_split(game, map);
}

char	*ft_strjoin(t_game *game, char *s1, char *s2)
{
	char	*new;
	char	*tmp1;
	int		i;

	if (!s1 && !s2)
		print_err(game, MAPERR);
	tmp1 = s1;
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		print_err(game, MEMERR);
	i = 0;
	while (s1 && *s1)
		new[i++] = *s1++;
	while (s2 && *s2)
		new[i++] = *s2++;
	new[i] = 0;
	if (tmp1)
		free(tmp1);
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

char	**ft_split_sub(t_game *game, char *src, char **arr)
{
	int		i;
	char	*tmp;

	i = 0;
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

void	ft_split(t_game *game, char *src)
{
	char	**arr;

	game->map.row = wd_len(src) + 1;
	arr = (char **)malloc(sizeof(char *) * (game->map.row + 1));
	if (!arr)
		print_err(game, MEMERR);
	game->map.map = ft_split_sub(game, src, arr);
	ft_free(src);
}
