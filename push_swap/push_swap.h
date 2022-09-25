/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:45:17 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/25 19:04:46 by seokchoi         ###   ########.fr       */
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

	int			pivot_big;
	int			pivot_small;

	int			pa;
	int			pb;
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
void		ra(t_data *data, int printable);
void		rb(t_data *data, int printable);
void		rr(t_data *data);
void		rra(t_data *data, int printable);
void		rrb(t_data *data, int printable);
void		rrr(t_data *data);

void		quick_sort(int *arr, int L, int R);
void		check_double(int *arr, int len);
void		set_pivot(t_data *data, int size);
int			*set_int_arr_for_sort(t_pw_list *list, int size);

void		two_sort_a(t_data *data);
void		three_sort_a(t_data *data);
void		hard_sort_a(t_data *data, int size);
void		a_to_b(int size, t_data *data);
void		push_swap(t_data *data);



#endif