/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:41:35 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/04 14:37:06 by seokchoi         ###   ########.fr       */
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
		throw_error("The file does not exist.\n");
	if (ft_strlen(filename) < 5) // 근데 이건 집고 넘어가야할 부분임. 그냥 파일 이름이 .ber 이면 어떡하나.
		throw_error("Not a valid file.n");
	if (filename[ft_strlen(filename) - 4] != '.' || filename[ft_strlen(filename) - 3] != 'b' || \
					filename[ft_strlen(filename) - 2] != 'e' ||filename[ft_strlen(filename) - 1] != 'r')
		throw_error("Not a valid file type.\n");
}

int	key_press(int key, void *params)
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
	else if (c == 'E')
		game->exit++;
	else if (c == 'C')
		game->collectible++;
	else if (c == '1' || c == '0')
		;
	else
		throw_error("The map is invalid.\n");
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
				throw_error("The map is not rectangular.\n");
			free(line);
		}
	}
	close(fd);
}

void	draw_map(void *mlx, void *win, game_t *game, img_t *image)
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
			mlx_put_image_to_window(mlx, win, image->img_empty, x, y);
		else 
		{
			mlx_put_image_to_window(mlx, win, image->img_empty, x, y);
			if((game->map)[i] == '1')
				mlx_put_image_to_window(mlx, win, image->img_wall, x, y);
			else if ((game->map)[i] == 'P')
				mlx_put_image_to_window(mlx, win, image->img_player, x, y);
			else if ((game->map)[i] == 'C')
				mlx_put_image_to_window(mlx, win, image->img_collectible, x, y);
			else if ((game->map)[i] == 'E')
				mlx_put_image_to_window(mlx, win, image->img_exit, x, y);
		}
	}
}
void	check_map_round(game_t *game)
{
	int	i;

	i = 0;
	while ((game->map)[i])
	{
		if (i / game->width == 0 && (game->map)[i] != '1') // 첫줄이 모두 1인지
			throw_error("The top side of the map is not one\n");
		if (i / game->width > 0 && i / game->width < game->height - 1) // 양쪽이 1인지 
		{
			if (i % game->width == 0 && (game->map)[i] != '1')
				throw_error("The left side of the map is not one\n");
			if (i % game->width == game->width - 1 && (game->map)[i] != '1')
				throw_error("The right side of the map is not one");
		}
		if (i / game->width == game->height - 1 && (game->map)[i] != '1') // 마지막 줄이 모두 1인지
			throw_error("The bottom side of the map is not one\n");
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
	if (game->exit == 0)
		throw_error("The map must have at least one exit\n");
	if (game->player != 1)
		throw_error("The map must have one player\n");
	if (game->collectible == 0)
		throw_error("The map must have at least one collectible\n");
}

void	check_map(game_t *game)
{
	check_map_round(game); // 둘레가 1로 되어있나?
	check_element(game); // 장애물, 보물, 플레이어의 수가 적정한가?
}

void	init_image(void *mlx, img_t *image)
{
	int img_width;
	int img_height;

	image->img_collectible = mlx_xpm_file_to_image(mlx, "./images/collectible.xpm", &img_width, &img_height);
	image->img_empty = mlx_xpm_file_to_image(mlx, "./images/empty.xpm", &img_width, &img_height);
	image->img_exit = mlx_xpm_file_to_image(mlx, "./images/exit2.xpm", &img_width, &img_height);
	image->img_player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &img_width, &img_height);
	image->img_wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	
	game_t	game;
	img_t	image;
	if (ac != 2)
		throw_error("It's not a proper argument.\n");
	(void) av;
	read_map(av[1], &game);
	check_map(&game);
	mlx = mlx_init();
	win = mlx_new_window(mlx, game.width *64, game.height * 64, "so_long");
	init_image(mlx, &image);
	draw_map(mlx, win, &game, &image);

	// mlx_key_hook(win, key_press, (void *)0);
	mlx_loop(mlx);
	return (0);
}
