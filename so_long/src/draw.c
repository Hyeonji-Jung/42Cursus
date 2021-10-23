/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:54:13 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/23 15:21:22 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_component(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

void	draw_player(t_game *game, void *side)
{
	mlx_put_image_to_window(game->mlx, game->win, side,
		game->map.cur_y, game->map.cur_x);
}

void	draw_one(t_game *game, char c, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, y, x);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, y, x);
	else if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.box, y, x);
		game->collect++;
	}
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, y, x);
	else if (c == 'P')
		draw_player(game, game->img.down);
}

void	draw(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.col)
		{
			if (!is_valid_component(game->map.map[i][j]))
				print_err(MAPERR);
			else
				draw_one(game, game->map.map[i][j], i * BLOCKS, j * BLOCKS);
		}
	}
}
