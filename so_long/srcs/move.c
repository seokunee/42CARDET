/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:57:09 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/10 16:39:59 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_to_point(t_game *game, int x, int y)
{
	if (game->map[x + y * game->width] == 'C')
		game->collectible--;
	if (game->map[x + y * game->width] == 'E' && game->collectible != 0)
		return ;
	if (game->map[x + y * game->width] == 'E')
	{
		ft_putstr_fd("clear!\n", 1);
		exit(0);
	}
	game->map[x + y * game->width] = 'P';
	game->map[game->x + game->y * game->width] = '0';
	game->x = x;
	game->y = y;
	game->count++;
	ft_putstr_fd("walk count : ", 1);
	ft_putnbr_fd(game->count, 1);
	write(1, "\n", 1);
}

void	move_w(t_game *game)
{
	int	x;
	int	y;
	int	pass;

	x = game->x;
	y = game->y - 1;
	pass = 0;
	if (game->map[game->width * y + x] != '1')
		pass = 1;
	if (pass == 1)
		move_player_to_point(game, x, y);
}

void	move_a(t_game *game)
{
	int	x;
	int	y;
	int	pass;

	x = game->x - 1;
	y = game->y;
	pass = 0;
	if ((game->map)[game->width * y + x] != '1')
		pass = 1;
	if (pass == 1)
		move_player_to_point(game, x, y);
}

void	move_s(t_game *game)
{
	int	x;
	int	y;
	int	pass;

	x = game->x;
	y = game->y + 1;
	pass = 0;
	if ((game->map)[game->width * y + x] != '1')
		pass = 1;
	if (pass == 1)
		move_player_to_point(game, x, y);
}

void	move_d(t_game *game)
{
	int	x;
	int	y;
	int	pass;

	x = game->x + 1;
	y = game->y;
	pass = 0;
	if ((game->map)[game->width * y + x] != '1')
		pass = 1;
	if (pass == 1)
		move_player_to_point(game, x, y);
}
