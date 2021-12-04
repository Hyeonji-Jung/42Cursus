/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:55:10 by hyeojung          #+#    #+#             */
/*   Updated: 2021/12/03 15:43:31 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(t_game *game, int n)
{
	char	*ret;
	int		len;
	int		tmp;

	len = 0;
	tmp = n;
	if (!tmp)
		len = 1;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	ret = malloc(len + 1);
	if (!ret)
		print_err(game, MEMERR);
	ret[len] = 0;
	while (len-- > 0)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

void	print_score_sub(t_game *game, int row)
{
	int		i;
	char	*steps;
	char	*score;

	i = 70;
	steps = ft_itoa(game, game->step);
	score = ft_itoa(game, game->score);
	while (i <= game->map.col * BLOCKS)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.empty, i, row - 16);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.empty, i, row);
		i += 16;
	}
	mlx_string_put(game->mlx, game->win, 70, row - 16, 0xFFFFFF, steps);
	mlx_string_put(game->mlx, game->win, 70, row, 0xFFFFFF, score);
	ft_free(steps);
	ft_free(score);
}

void	sprite_animation(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.col)
		{
			if (game->map.map[i][j] == 'N')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.ground, j * BLOCKS, i * BLOCKS);
				if (rand() % 2 == 1)
					mlx_put_image_to_window(game->mlx, game->win,
						game->img.enemy_2, j * BLOCKS, i * BLOCKS);
				else
					mlx_put_image_to_window(game->mlx, game->win,
						game->img.enemy, j * BLOCKS, i * BLOCKS);
			}
		}
	}
}

int	print_score(t_game *game)
{
	int	row;
	int	t;

	row = game->map.row * 32 + 12;
	mlx_string_put(game->mlx, game->win, 16, row - 16, 0xFFFFFF, "STEPS");
	mlx_string_put(game->mlx, game->win, 16, row, 0xFFFFFF, "SCORE");
	print_score_sub(game, row);
	sprite_animation(game);
	t = -1;
	while (++t < 50000000)
		if (t >= 50000000)
			break ;
	return (0);
}
