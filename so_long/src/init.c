/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:30:47 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/03 14:30:39 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_err(game, "mlx init error");
	game->win = mlx_new_window(game->mlx,
			game->map.col * BLOCKS,
			game->map.row * BLOCKS,
			"Slime Forest");
	game->step = 0;
	game->score = 0;
	game->collect = 0;
	set_game_images(game);
	draw(game);
}

void	set_game_images(t_game *game)
{
	game->img.ground = mlx_xpm_file_to_image(game->mlx,
			"./img/so_long_ground.xpm",
			&game->img.width, &game->img.height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./img/so_long_wall.xpm",
			&game->img.width, &game->img.height);
	game->img.box = mlx_xpm_file_to_image(game->mlx,
			"./img/so_long_collect.xpm",
			&game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./img/so_long_exit.xpm",
			&game->img.width, &game->img.height);
	game->img.up = mlx_xpm_file_to_image(game->mlx,
			"./img/so_long_up.xpm",
			&game->img.width, &game->img.height);
	game->img.down = mlx_xpm_file_to_image(game->mlx,
			"./img/so_long_down.xpm",
			&game->img.width, &game->img.height);
	game->img.left = mlx_xpm_file_to_image(game->mlx,
			"./img/so_long_left.xpm",
			&game->img.width, &game->img.height);
	game->img.right = mlx_xpm_file_to_image(game->mlx,
			"./img/so_long_right.xpm",
			&game->img.width, &game->img.height);
}
