/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:30:47 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/18 17:54:20 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map.row * BLOCKS,
			game->map.col * BLOCKS,
			"so_long");
	set_game_images(game);
}

void	set_game_images(t_game *game)
{
	game->image.ground = mlx_xpm_file_to_image(game->mlx,
        "../img/so_long_ground.xpm", BLOCKS, BLOCKS);
    game->image.down = mlx_xpm_file_to_image(game->mlx,
        "../img/so_long_down.xpm", BLOCKS, BLOCKS);
}
