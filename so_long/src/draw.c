/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:54:13 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/20 21:42:01 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_valid_component(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

void	draw_component(t_game *game, char c, int x, int y)
{
	if (c == '1')
	{
		printf("%p %p %p %d %d\n", game->mlx, game->win, game->image.ground, y, x);
	}
		// mlx_put_image_to_window(game->mlx, game->win,
			// game->image.ground, y, x);
}

void	draw(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.col)
		{
			if (!is_valid_component(game->map.map[i][j]))
				print_err(MAPERR);
			else
				draw_component(game, game->map.map[i][j], i * BLOCKS, j * BLOCKS);
		}
		printf("\n");
	}
}
