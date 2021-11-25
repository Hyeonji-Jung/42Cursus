/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:43:39 by hyeojung          #+#    #+#             */
/*   Updated: 2021/11/25 21:38:13 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(t_game *game, char *s)
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
		print_err(game, "Invalid filename");
}

void	check_map(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	game->map.col = ft_strlen(game->map.map[0]);
	while (++row < game->map.row)
	{
		if (ft_strlen(game->map.map[row]) != game->map.col)
			print_err(game, MAPERR);
		if (row == 0 || row == game->map.row - 1)
		{
			col = -1;
			while (++col < game->map.col)
				if (game->map.map[row][col] != '1')
					print_err(game, MAPERR);
		}
		if (row > 0 && row < (game->map.row - 1)
			&& (game->map.map[row][0] != '1'
			|| game->map.map[row][game->map.col - 1] != '1'))
			print_err(game, MAPERR);
	}
	check_map_components(game);
}

void	check_map_components(t_game *game)
{
	int	c;
	int	e;
	int	p;
	int	row;
	int	col;

	c = 0;
	e = 0;
	p = 0;
	row = -1;
	while (++row < game->map.row)
	{
		col = -1;
		while (++col < game->map.col)
		{
			if (game->map.map[row][col] == 'C')
				c++;
			else if (game->map.map[row][col] == 'E')
				e++;
			else if (game->map.map[row][col] == 'P')
				check_start(game, row, col, p++);
		}
	}
	if (c < 1 || e != 1 || p != 1)
		print_err(game, MAPERR);
}

void	check_start(t_game *game, int x, int y, int p)
{
	if (p > 1)
		print_err(game, MAPERR);
	game->map.cur_x = x * BLOCKS;
	game->map.cur_y = y * BLOCKS;
}

void	print_err(t_game *game, char *s)
{
	ft_putstr("Error\n");
	ft_putstr(s);
	if (*s != 'F')
		arr_free(game);
	exit(-1);
}
