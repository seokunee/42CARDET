/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:12:22 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/07 03:28:38 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h" /* MiniLibX */
# include "../libft/libft.h" /* libft */
# include "get_next_line.h"
# include <stdlib.h> /* exit, malloc, free */
# include <unistd.h>  /* write, close, read*/
# include <fcntl.h> /* open */
# include <string.h> /* strerror */
# include <stdio.h> /* perror */

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define IMAGE_SIZE		64
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img
{
	void	*img_collectible;
	void	*img_empty;
	void	*img_exit;
	void	*img_player;
	void	*img_wall;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*map;
	int		collectible;
	int		exit;
	int		player;
	int		empty;
	int		x;
	int		y;
	int		count;
	t_img	image;
}					t_game;

/* so_long_ft.c */
char	*ft_strjoin_without_nl(char const *s1, char const *s2);

/* image.c */
void	init_image(void *mlx, t_img *image);
void	set_image(t_game *game, void *image_type, int x, int y);

/* element.c */
void	check_element(t_game *game);
void	init_element(t_game *game);
void	count_element(t_game *game, char c, int i);

/* map.c */
void	read_map(const char *filename, t_game *game);
void	check_map(t_game *game);
int		draw_map(t_game *game);
void	check_map_round(t_game *game);

/* so_long.c */
void	throw_error(char *message);
void	check_filename(const char *filename);
int		key_press(int key, t_game *game);

/* move.c */
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	move_player_to_point(t_game *game, int x, int y);

#endif