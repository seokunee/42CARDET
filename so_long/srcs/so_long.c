/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:41:35 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/07 03:22:49 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	throw_error(char *message)
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	exit(1);
}

void	check_filename(const char *filename)
{
	if (!filename)
		throw_error("The file does not exist.\n");
	if (ft_strlen(filename) < 5)
		throw_error("Not a valid file\n");
	if (filename[ft_strlen(filename) - 4] != '.' || \
					filename[ft_strlen(filename) - 3] != 'b' || \
					filename[ft_strlen(filename) - 2] != 'e' \
					||filename[ft_strlen(filename) - 1] != 'r')
		throw_error("Not a valid file type.\n");
}

int	key_press(int key, t_game *game)
{
	if (key == 13)
		move_w(game);
	else if (key == 0)
		move_a(game);
	else if (key == 1)
		move_s(game);
	else if (key == 2)
		move_d(game);
	else if (key == 53)
		exit(0);
	return (0);
}

static int	end_game(t_game *game)
{
	game->x = game->x;
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		throw_error("It's not a proper argument.\n");
	(void) av;
	check_filename(av[1]);
	read_map(av[1], &game);
	check_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, \
	game.height * 64, "SEOKCHOI_SO_LONG");
	init_image(game.mlx, &(game.image));
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop_hook(game.mlx, draw_map, &game);
	mlx_hook(game.win, 17, 0, end_game, (void *)0);
	mlx_loop(game.mlx);
	return (0);
}
