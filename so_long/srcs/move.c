/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:09 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/05 02:06:36 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	move_player_to_point(game_t *game, int x, int y)
{
	void	*mlx;
	void	*win;
	
	mlx = game->mlx;
	win = game->win;
	(game->map)[x + y * game->width] = 'P';
	(game->map)[game->x + game->y * game->width] = '0';
	game->x = x;
	game->y = y;
}

void	test(game_t *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.img_empty, x, y);
}


void	move_w(game_t *game)
{
	int	x;
	int	y;
	int	pass;

	x = game->x;
	y = game->y - 1;
	pass = 0;
	if ((game->map)[game->width * y + x] != 1)
		pass = 1;
	if (pass == 0)
		move_player_to_point(game, x, y);
	printf("up\n");
}

void	move_a(game_t *game)
{
	int	x;
	int	y;
	int	pass;
	
	x = game->x - 1;
	y = game->y;
	pass = 0;
	if ((game->map)[game->width * y + x] != 1)
		pass = 1;
	if (pass == 0)
		move_player_to_point(game, x, y);
	printf("left\n");
}

void	move_s(game_t *game)
{
	int	x;
	int	y;
	int	pass;

	x = game->x;
	y = game->y + 1;
	pass = 0;
	if ((game->map)[game->width * y + x] != 1)
		pass = 1;
	if (pass == 0)
		move_player_to_point(game, x, y);
	printf("down\n");
}

void	move_d(game_t *game)
{
	int	x;
	int	y;
	int	pass;

	x = game->x + 1;
	y = game->y;
	pass = 0;
	if ((game->map)[game->width * y + x] != 1)
		pass = 1;
	if (pass == 0)
		move_player_to_point(game, x, y);
	printf("right\n");
}
