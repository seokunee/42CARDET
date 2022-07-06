/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:46:55 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/07 03:21:41 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_element(t_game *game)
{
	int	i;

	i = -1;
	init_element(game);
	while ((game->map)[++i])
		count_element(game, (game->map)[i], i);
	if (game->exit == 0)
		throw_error("The map must have at least one exit\n");
	if (game->player != 1)
		throw_error("The map must have one player\n");
	if (game->collectible == 0)
		throw_error("The map must have at least one collectible\n");
}

void	init_element(t_game *game)
{
	game->player = 0;
	game->exit = 0;
	game->empty = 0;
	game->collectible = 0;
	game->count = 0;
	game->height = 0;
}

void	count_element(t_game *game, char c, int i)
{
	if (c == 'P')
	{
		game->x = i % game->width;
		game->y = i / game->width;
		game->player++;
	}
	else if (c == 'E')
		game->exit++;
	else if (c == 'C')
		game->collectible++;
	else if (c == '1' || c == '0')
		;
	else
		throw_error("The map is invalid.\n");
}
