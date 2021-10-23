/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:03:07 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/23 15:21:03 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		check_file(av[1]);
		read_file(&game, av[1], 1);
		check_map(&game);
		so_long_init(&game);
		mlx_hook(game.win, 17, 0, &exit_game, &game);
		mlx_hook(game.win, EVENT_KEY_PRESS, 0, &key_press, &game);
		mlx_loop(game.mlx);
	}
	else
		print_err("Usage: ./so_long map/\"filename\"");
	exit(1);
}
