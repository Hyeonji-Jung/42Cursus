/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:01:30 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/05 16:53:48 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE 30

typedef struct s_map
{
	char	**map;
	size_t	row;
	size_t	col;
}			t_map;

typedef struct s_game
{
	t_map	map;
}			t_game;

void	check_file(char *s);
// void	check_map(char *s);
void	print_err(char *s);
void	ft_putstr(char *s);
void	ft_strlcat(char *dest, char *src, size_t size);
void	read_file(t_game *game, char *s, int read_ret);

char	*ft_strjoin(char *s1, char *s2);

char	**ft_split(t_game *game, char *src);

size_t	ft_strlen(char *str);

#endif
