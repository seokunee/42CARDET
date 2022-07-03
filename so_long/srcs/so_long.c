/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:41:35 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/03 17:00:07 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	throw_error(char *message)
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	exit(1);
}

void	check_filename(const char *filename)
{
	if (!filename)
		throw_error("The file does not exist.");
	if (ft_strlen(filename) < 5)
		throw_error("Not a valid file");
	if (filename[ft_strlen(filename) - 4] != '.' || filename[ft_strlen(filename) - 3] != 'b' || \
					filename[ft_strlen(filename) - 2] != 'e' ||filename[ft_strlen(filename) - 1] != 'r')
		throw_error("Not a valid file type.");
}

int	press(int key, void *params)
{
	int *a;
	a = (int *)params;
 	ft_putnbr_fd(key, 1);
	return (0);
}

char	*ft_strjoin_without_nl(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (j < s1_len && s1[j] != '\n')
		str[i++] = s1[j++];
	j = 0;
	while (j < s2_len && s2[j] != '\n')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void	count_element(game_t *game, char c)
{
	if (c == 'P')
		game->player++;
	if (c == 'E')
		game->exit++;
	if (c == 'C')
		game->collectible++;
}

void	read_map(const char *filename, game_t *game)
{
	int		fd;
	char	*line;

	check_filename(filename);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit(1);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->map = ft_strdup(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		game->height++;
		if (line)
		{
			game->map = ft_strjoin_without_nl(game->map , line);
			if (((int)ft_strlen(line) - 1 != game->width && ft_strchr(line, '\n')) \
					|| ((int)ft_strlen(line) != game->width && !ft_strchr(line, '\n'))) // 길이 체크
				throw_error("Invalid map.7");
			free(line);
		}
	}
	close(fd);
}

void	image_to_map(void *mlx, void*win)
{
	void *img_collectible;
	void *img_empty;
	void *img_exit;
	void *img_player;
	void *img_wall;
	int img_width;
	int img_height;

	img_collectible = mlx_xpm_file_to_image(mlx, "./images/collectible.xpm", &img_width, &img_height);
	img_empty = mlx_xpm_file_to_image(mlx, "./images/empty.xpm", &img_width, &img_height);
	img_exit = mlx_xpm_file_to_image(mlx, "./images/exit2.xpm", &img_width, &img_height);
	img_player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &img_width, &img_height);
	img_wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, img_collectible, 0, 0);
	mlx_put_image_to_window(mlx, win, img_empty, IMAGE_SIZE, 0);
	mlx_put_image_to_window(mlx, win, img_exit, 2* IMAGE_SIZE, 0);
	mlx_put_image_to_window(mlx, win, img_player, 3 * IMAGE_SIZE, 2* IMAGE_SIZE);
	mlx_put_image_to_window(mlx, win, img_wall, 0, 2* IMAGE_SIZE);
}

void	check_map_round(game_t *game)
{
	int	i;

	i = 0;
	while ((game->map)[i])
	{
		if (i / game->width == 0 && (game->map)[i] != '1') // 첫줄이 모두 1인지
			throw_error("Invalid map.1");
		if (i / game->width > 0 && i / game->width < game->height - 1) // 양쪽이 1인지 
		{
			if (i % game->width == 0 && (game->map)[i] != '1')
				throw_error("Invalid map.2");
			if (i % game->width == game->width - 1 && (game->map)[i] != '1')
				throw_error("Invalid map.3");
		}
		if (i / game->width == game->height - 1 && (game->map)[i] != '1') // 마지막 줄이 모두 1인지
			throw_error("Invalid map.4");
		i++;
	}
}

void	init_element(game_t *game)
{
	game->player = 0;
	game->exit = 0;
	game->empty = 0;
	game->collectible = 0;
}

void	check_element(game_t *game)
{
	int	i;

	i = -1;
	init_element(game);
	while ((game->map)[++i])
		count_element(game, (game->map)[i]);
	if (game->exit != 1)
		throw_error("Invalid map.5");
	if (game->player != 1)
		throw_error("Invalid map.6");
}

void	check_map(game_t *game)
{
	check_map_round(game); // 둘레가 1로 되어있나?
	check_element(game); // 장애물, 보물, 플레이어의 수가 적정한가?
}

int	main(int ac, char **av)
{
	void *mlx;
	void *win;
	
	game_t	game;
	img_t	image;
	if (ac != 2)
		return (0);
	(void) av;
	read_map(av[1], &game);
	check_map(&game);
	mlx = mlx_init();
	win = mlx_new_window(mlx, game.width *64, game.height * 64, "so_long");

	image_to_map(mlx, win);
	// mlx_key_hook(win_ptr, press, (void *)0);
	mlx_loop(mlx);
	return (0);
}
