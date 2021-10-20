/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:30:47 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/20 20:51:05 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map.col * BLOCKS,
			game->map.row * BLOCKS,
			"so_long");
	set_game_images(game);
	game->collect = 0;
	draw(game);
}

void	set_game_images(t_game *game)
{
	game->image.ground = mlx_xpm_file_to_image(game->mlx,
			"../img/so_long_ground.xpm",
			&game->image.width, &game->image.height);
    game->image.down = mlx_xpm_file_to_image(game->mlx,
        "../img/so_long_down.xpm", &game->image.width, &game->image.height);
}
