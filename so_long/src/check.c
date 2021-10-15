/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:43:39 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/15 17:04:04 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *s)
{
	int		flag;
	char	*tmp;

	flag = 0;
	tmp = s;
	while (*s)
		if (*s++ == '.')
			if (*s++ == 'b')
				if (*s++ == 'e')
					if (*s++ == 'r')
						if (*s++ == 0)
							flag = 1;
	if (!flag)
		print_err("Invalid filename");
}

void	check_map(t_game *game)
{
	int	len;
	int	idx;

	len = game->map.row;
	idx = -1;
	game->map.col = ft_strlen(game->map.map[0]);
	print_map(game);
	while (len--)
	{
		if (ft_strlen(game->map.map[len]) != game->map.col)
			print_err("col 길이가 달라요");
		if (len == 0 || len == (game->map.row - 1))
			while (++idx < game->map.col)
				if (game->map.map[len][idx] != '1')
					print_err("첫줄이랑 마지막줄이 벽이 아니에요");
		if (len > 0 && len < (game->map.row - 1))
			if (game->map.map[len][0] != '1'
				|| game->map.map[len][game->map.col - 1] != '1')
				print_err("양옆이 벽이 아니에요");
	}
	print_err("멀쩡한 지도로군 !");
}

void	print_err(char *s)
{
	ft_putstr("Error\n");
	ft_putstr(s);
	exit(-1);
}

void	print_map(t_game *game)
{
	printf("--------------------\n");
	for (int i = 0; i < game->map.row; i++)
	{
		for (int j = 0; j < game->map.col; j++)
			printf("%c", game->map.map[i][j]);
		printf("\n");
	}
	printf("--------------------\n");
}