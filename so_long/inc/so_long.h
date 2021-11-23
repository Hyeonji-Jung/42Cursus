/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:01:30 by hyeojung          #+#    #+#             */
/*   Updated: 2021/10/31 17:25:05 by hyeojung         ###   ########.fr       */
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

# define BUFFER_SIZE 20000
# define BLOCKS 32

# define EVENT_KEY_PRESS 2
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

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
	int		width;
	int		height;
	void	*ground;
	void	*wall;
	void	*box;
	void	*exit;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}			t_image;

typedef struct s_game
{
	t_map	map;
	t_image	img;
	void	*mlx;
	void	*win;
	int		step;
	int		score;
	int		collect;
}			t_game;

void	check_file(t_game *game, char *s);
void	check_map(t_game *game);
void	check_map_components(t_game *game);
void	check_start(t_game *game, int x, int y, int p);
void	print_err(t_game *game, char *s);
void	ft_putstr(char *s);
void	ft_strcpy(char *dest, char *from, char *to);
void	ft_strlcat(t_game *game, char *dest, char *src, size_t size);
void	read_file(t_game *game, char *s, int read_ret);
void	so_long_init(t_game *game);
void	set_game_images(t_game *game);
void	draw_one(t_game *game, char c, int x, int y);
void	draw_player(t_game *game, void *side);
void	draw(t_game *game);
void	key_move(t_game *game, void *side, int x, int y);
void	set_position(t_game *game, int x, int y);
void	turn_player(t_game *game, int key);
void	ft_putnbr(int n);
void	print_steps(t_game *game);
void	arr_free(t_game *game);
void	destroy_mlx(t_game *game);
void	ft_split(t_game *game, char *src);

char	*ft_strjoin(t_game *game, char *s1, char *s2);
char	*is_newline(char *s);

char	**ft_split_sub(t_game *game, char *src, char **arr);

int		ft_strlen(char *str);
int		is_valid_component(char c);
int		exit_game(t_game *game);
int		key_press(int key, t_game *game);

#endif
