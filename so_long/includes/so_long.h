/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:12:22 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/07 02:00:11 by seokchoi         ###   ########.fr       */
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
typedef	struct		img_s
{
	void *img_collectible;
	void *img_empty;
	void *img_exit;
	void *img_player;
	void *img_wall;
}		img_t;
typedef struct		game_s
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
	
	img_t	image;
}					game_t;

/* so_long_ft.c */
char	*ft_strjoin_without_nl(char const *s1, char const *s2);

/* image.c */
void	init_image(void *mlx, img_t *image);

/* element.c */
void	check_element(game_t *game);
void	init_element(game_t *game);
void	count_element(game_t *game, char c, int	i);

/* map.c */
void	read_map(const char *filename, game_t *game);
void	check_map(game_t *game);
int		draw_map(game_t *game);
void	check_map_round(game_t *game);


/* so_long.c */
void	throw_error(char *message);
void	check_filename(const char *filename);
int		key_press(int key, game_t *game);

/* move.c */
void	move_w(game_t *game);
void	move_a(game_t *game);
void	move_s(game_t *game);
void	move_d(game_t *game);
void	move_player_to_point(game_t *game, int x, int y);

#endif