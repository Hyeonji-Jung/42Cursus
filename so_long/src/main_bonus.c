/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:03:07 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/03 15:41:01 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	arr_free(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.row)
	{
		ft_free(game->map.map[i]);
		game->map.map[i] = 0;
	}
	ft_free(game->map.map);
	game->map.map = 0;
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
		mlx_loop_hook(game.mlx, &print_score, &game);
		mlx_loop(game.mlx);
	}
	else
	{
		ft_putstr("Usage: ./so_long map/\"filename\"");
		return (-1);
	}
	return (0);
}
