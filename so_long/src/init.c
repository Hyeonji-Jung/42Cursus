/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:30:47 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/15 22:13:35 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    so_long_init(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx,
                game->map.row * BLOCK,
                game->map.col * BLOCK,
                "so_long");
    set_game_images(game);
}

void set_game_images(t_game *game)
{
    return 0;
}