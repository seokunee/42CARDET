/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:12:22 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/29 17:36:46 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h" /* MiniLibX */
# include "../libft/libft.h" /* libft */
# include <stdlib.h> /* exit, malloc, free */
# include <unistd.h>  /* write, close, read*/
# include <fcntl.h> /* open */
# include <string.h> /* strerror */
# include <stdio.h> /* perror */

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

// typedef struct		mlx_ptr_s
// {
//   void			*appid;
//   mlx_win_list_t	*win_list;
//   mlx_img_list_t	*img_list;
//   void			(*loop_hook)(void *);
//   void			*loop_hook_data;
//   void			*loop_timer;
//   mlx_img_list_t	*font;
//   int			main_loop_active;
// } mlx_ptr_t;

#endif