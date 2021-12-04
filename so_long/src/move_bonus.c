/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:20:41 by hyeojung          #+#    #+#             */
/*   Updated: 2021/11/25 22:12:26 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_game(t_game *game)
{
	ft_putstr("SCORE: ");
	if (game->score)
		ft_putnbr(game->score);
	else
		write(1, "0", 1);
	ft_putstr(" / ");
	ft_putnbr(game->collect);
	if (game->score == game->collect
		&& game->map.map[game->map.cur_x / BLOCKS][game->map.cur_y / BLOCKS]
		!= 'N')
		ft_putstr("\nYou won the game 🙌");
	ft_putstr("\nByeBye !\n");
	arr_free(game);
	exit(0);
}

void	set_position(t_game *game, int x, int y)
{
	if (x != 0 && x < game->map.row)
		game->map.cur_x = x * BLOCKS;
	if (y != 0 && y < game->map.col)
		game->map.cur_y = y * BLOCKS;
}

void	turn_player(t_game *game, int key)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
		game->map.cur_y, game->map.cur_x);
	if (key == KEY_W)
		draw_player(game, game->img.up);
	else if (key == KEY_A)
		draw_player(game, game->img.left);
	else if (key == KEY_S)
		draw_player(game, game->img.down);
	else if (key == KEY_D)
		draw_player(game, game->img.right);
}

void	key_move(t_game *game, void *side, int x, int y)
{
	if (game->map.map[x][y] == 'E' && game->score != game->collect)
		return ;
	game->step++;
	print_steps(game);
	if (game->map.map[x][y] == 'C')
	{
		game->score++;
		game->map.map[x][y] = '0';
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.ground, y * BLOCKS, x * BLOCKS);
	}
	else if (game->map.map[x][y] == 'E' && game->score == game->collect)
		exit_game(game);
	else if (game->map.map[x][y] == 'N')
	{
		set_position(game, x, y);
		ft_putstr("You ran into the enemy 😈\n");
		exit_game(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
		game->map.cur_y, game->map.cur_x);
	set_position(game, x, y);
	draw_player(game, side);
}

int	key_press(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->map.cur_x / BLOCKS;
	y = game->map.cur_y / BLOCKS;
	if (key == KEY_ESC)
		exit_game(game);
	else if (key == KEY_W && game->map.map[x - 1][y] != '1')
		key_move(game, game->img.up, x - 1, y);
	else if (key == KEY_A && game->map.map[x][y - 1] != '1')
		key_move(game, game->img.left, x, y - 1);
	else if (key == KEY_S && game->map.map[x + 1][y] != '1')
		key_move(game, game->img.down, x + 1, y);
	else if (key == KEY_D && game->map.map[x][y + 1] != '1')
		key_move(game, game->img.right, x, y + 1);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		turn_player(game, key);
	return (0);
}
