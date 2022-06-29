/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:41:35 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/29 21:35:11 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
# include "get_next_line.h"
# include "../mlx/mlx.h" /* MiniLibX */
// void	key_press()
// {
// 	if ()
// 	{
		
// 	}
// }


static void	ft_print_number(int n, int fd)
{
	char	left;

	if (n > 9)
		ft_print_number(n / 10, fd);
	left = '0' + n % 10;
	write(fd, &left, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		ft_print_number(n, fd);
	}
}

int	press(int key, void *params)
{
	int *a;
	a = (int *)params;
 	ft_putnbr_fd(key, 1);
	return (0);
}

void	read_map(char *filename)
{
	int	fd;
	
	fd = open(filename, O_RDONLY);
	get_next_line(fd);
}

int	main()
{
	void *mlx;
	void *win;
	void *img_collectible;
	void *img_empty;
	void *img_exit;
	void *img_player;
	void *img_wall;
	int img_width;
	int img_height;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img_collectible = mlx_xpm_file_to_image(mlx, "./images/collectible.xpm", &img_width, &img_height);
	img_empty = mlx_xpm_file_to_image(mlx, "./images/empty.xpm", &img_width, &img_height);
	img_exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &img_width, &img_height);
	img_player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &img_width, &img_height);
	img_wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img_collectible, 0, 0);
	mlx_put_image_to_window(mlx, win, img_empty, 64, 0);
	mlx_put_image_to_window(mlx, win, img_exit, 128, 0);
	mlx_put_image_to_window(mlx, win, img_player, 192, 64);
	mlx_put_image_to_window(mlx, win, img_wall, 0, 64);
	// // mlx_key_hook(win_ptr, press, (void *)0);
	mlx_loop(mlx);
	return (0);
}
