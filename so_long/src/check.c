/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:43:39 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/06 17:32:43 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *s)
{
	int		flag;
	char	*tmp;

	flag = 0;
	tmp = s;
	while (*s)
		if (*s++ == '.')
			if (*s++ == 'b')
				if (*s++ == 'e')
					if (*s++ == 'r')
						if (*s++ == 0)
							flag = 1;
	if (!flag)
		print_err("Invalid filename");
}

void	check_map(t_game *game)
{
	int	len;

	len = game->map.row;
	game->map.col = ft_strlen(game->map.map[0]);
	while (len--)
	{
		if (ft_strlen(game->map.map[len]) != game->map.col)
			print_err("Invalid map");
	}
}

void	print_err(char *s)
{
	ft_putstr("Error\n");
	ft_putstr(s);
	exit(-1);
}
