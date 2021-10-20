/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:54:13 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/20 20:50:49 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_valid_component(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

void	draw_components(t_game *game, char c, int x, int y)
{
	game->collect++;
	printf("%c, %d, %d", c, y, x);
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
			draw_components(game, game->map.map[i][j], i * BLOCKS, j * BLOCKS);
		}
	}
}
