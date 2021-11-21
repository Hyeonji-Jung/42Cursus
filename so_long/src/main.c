/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:03:07 by hyeojung          #+#    #+#             */
/*   Updated: 2021/11/21 19:30:13 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arr_free(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.row)
	{
		free(game->map.map[i]);
		game->map.map[i] = 0;
	}
	free(game->map.map);
	game->map.map = 0;
}

void	destroy_mlx(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.box);
	mlx_destroy_image(game->mlx, game->img.down);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.ground);
	mlx_destroy_image(game->mlx, game->img.left);
	mlx_destroy_image(game->mlx, game->img.right);
	mlx_destroy_image(game->mlx, game->img.up);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_window(game->mlx, game->win);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		check_file(&game, av[1]);
		read_file(&game, av[1], 1);
		check_map(&game);
		so_long_init(&game);
		mlx_hook(game.win, 17, 0, &exit_game, &game);
		mlx_hook(game.win, EVENT_KEY_PRESS, 0, &key_press, &game);
		mlx_loop(game.mlx);
	}
	else
		print_err(&game, "Usage: ./so_long map/\"filename\"");
}
