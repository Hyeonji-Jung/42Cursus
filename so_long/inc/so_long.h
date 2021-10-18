/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:01:30 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/18 17:55:14 by hyeojung         ###   ########.fr       */
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
# define BLOCKS 64
# define FILEERR "File parsing error"
# define MAPERR "Invalid map"
# define MEMERR "Memory allocation error"

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
	int		cur_x;
	int		cur_y;
}			t_map;

typedef struct s_image
{
	void	*ground;
	// void	*wall;
	// void	*collect;
	// void	*exit;
	// void	*up;
	void	*down;
	// void	*left;
	// void	*right;
}			t_image;


typedef struct s_game
{
	t_map	map;
	t_image	image;
	void	*mlx;
	void	*win;
}			t_game;

void	check_file(char *s);
void	check_map(t_game *game);
void	check_map_components(t_game *game);
void	check_start(t_game *game, int x, int y, int p);
void	print_err(char *s);
void	ft_putstr(char *s);
void	ft_strlcat(char *dest, char *src, size_t size);
void	read_file(t_game *game, char *s, int read_ret);
void	so_long_init(t_game *game);
void	set_game_images(t_game *game);
void	draw_blocks(t_game *game);

char	*ft_strjoin(char *s1, char *s2);
char	*is_newline(char *s);

char	**ft_split(t_game *game, char *src);

int		ft_strlen(char *str);

#endif
