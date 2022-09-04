/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:45:17 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/04 20:43:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_pw_list
{
	int		value;
	struct s_pw_list *next;
}			t_pw_list;

typedef struct s_data
{
	t_pw_list *list;
	int			list_count;
	int			*list_int;
	char		**list_str;
}			t_data;

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h> // 지울것

void		make_linked_list(int ac, char **av, t_data *data);
t_pw_list	*ft_pw_lstnew(int	value);
void		check_is_num_arr(char *arr);
void		av_to_list_string(int ac, char **av, t_data *data);
int			secend_arr_len(char **arr);
void		free_sec_str_arr(char **arr);
int			count_list_in_arr(char **list_string);


#endif