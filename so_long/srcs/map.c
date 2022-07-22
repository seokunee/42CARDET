/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:44:04 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/22 17:54:17 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rectangular(t_game *game, char *line)
{
	if (((int)ft_strlen(line) - 1 != game->width && \
		ft_strchr(line, '\n')) || ((int)ft_strlen(line) != \
		game->width && !ft_strchr(line, '\n')))
		throw_error("The map is not rectangular.\n");
}

void	read_map(const char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		throw_error("Failed to open file.\n");
	line = get_next_line(fd);
	if (!line)
		throw_error("Not a valid map\n");
	game->width = ft_strlen(line) - 1;
	game->map = ft_strdup(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		game->height++;
		if (line)
		{
			game->map = ft_strjoin_without_nl(game->map, line);
			check_rectangular(game, line);
			free(line);
		}
	}
	close(fd);
}

void	check_map(t_game *game)
{
	check_map_round(game);
	check_element(game);
}

int	draw_map(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while ((game->map)[++i])
	{
		x = (i % game->width) * IMAGE_SIZE;
		y = (i / game->width) * IMAGE_SIZE;
		if ((game->map)[i] == '0')
			set_image(game, game->image.img_empty, x, y);
		else
		{
			set_image(game, game->image.img_empty, x, y);
			if ((game->map)[i] == '1')
				set_image(game, game->image.img_wall, x, y);
			else if ((game->map)[i] == 'P')
				set_image(game, game->image.img_player, x, y);
			else if ((game->map)[i] == 'C')
				set_image(game, game->image.img_collectible, x, y);
			else if ((game->map)[i] == 'E')
				set_image(game, game->image.img_exit, x, y);
		}
	}
	return (0);
}

void	check_map_round(t_game *game)
{
	int	i;

	i = 0;
	while ((game->map)[i])
	{
		if (i / game->width == 0 && (game->map)[i] != '1')
			throw_error("The side of the map is not wall.\n");
		if (i / game->width > 0 && i / game->width < game->height - 1)
		{
			if (i % game->width == 0 && (game->map)[i] != '1')
				throw_error("The side of the map is not wall.\n");
			if (i % game->width == game->width - 1 && (game->map)[i] != '1')
				throw_error("The side of the map is not wall.\n");
		}
		if (i / game->width == game->height - 1 && (game->map)[i] != '1')
			throw_error("The side of the map is not wall.\n");
		i++;
	}
}
