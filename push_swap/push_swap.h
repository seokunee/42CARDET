/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:45:17 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/20 01:20:08 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_pw_list
{
	int					value;
	struct s_pw_list	*next;
	struct s_pw_list	*prev;
	
}			t_pw_list;

typedef struct s_data
{
	t_pw_list	*list_a;
	t_pw_list	*list_b;

	int			total_size;
	int			*list_int;
	char		**list_str;

	int			list_a_size;
	int			list_b_size;

	int			pivot_f;
	int			pivot_s;

	int			pa;
	int			pd;
	int			ra;
	int			rb;
}			t_data;

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h> // 지울것ㅁㄴㅇㄹㄴㅇㅇㄹㄴㅇㄹㅁㄴㅇㄹㅁㄴㅇㄹㅁㄴㅇㄹㄴㅇㄹㅁㄴㅇㄹㅁㅇㄹㄴㅇㄹㄴㅇㅇㄹㄴㅇㄹㄴㅇㄹㅁㄴㅇㅇㄹ

void		make_linked_list(t_data *data);
t_pw_list	*ft_pw_lstnew(int value);
void		check_is_num_arr(char *arr);
void		av_to_list_str(int ac, char **av, t_data *data);
int			secend_arr_len(char **arr);
void		free_sec_str_arr(char **arr);
int			count_list_in_arr(char **list_string);
void		list_str_to_list_int(t_data *data);

void		throw_error(char *message);

void		sa(t_data *data);
void		sb(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

void	quick_sort(int *arr, int L, int R);


#endif