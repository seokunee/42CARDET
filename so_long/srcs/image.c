/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:44:30 by seokchoi          #+#    #+#             */
/*   Updated: 2022/07/07 03:21:41 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(void *mlx, img_t *image)
{
	int	img_width;
	int	img_height;

	image->img_collectible = mlx_xpm_file_to_image(mlx, \
	"./images/collectible.xpm", &img_width, &img_height);
	image->img_empty = mlx_xpm_file_to_image(mlx, \
	"./images/empty.xpm", &img_width, &img_height);
	image->img_exit = mlx_xpm_file_to_image(mlx, \
	"./images/exit2.xpm", &img_width, &img_height);
	image->img_player = mlx_xpm_file_to_image(mlx, \
	"./images/player.xpm", &img_width, &img_height);
	image->img_wall = mlx_xpm_file_to_image(mlx, \
	"./images/wall.xpm", &img_width, &img_height);
}

void	set_image(t_game *game, void *image_type, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, image_type, x, y);
}
