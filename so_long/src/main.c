/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:03:07 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/20 20:50:43 by hyeojung         ###   ########.fr       */
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
		mlx_loop(game.mlx);
	}
	else
		print_err("Usage: ./so_long \"filename\"");
	exit(1);
}
