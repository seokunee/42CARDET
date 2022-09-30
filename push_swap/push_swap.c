/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:33:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/30 20:35:36 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_data *data, int size)
{
	data->pivot_small = data->list_int[size / 3];
	data->pivot_big = data->list_int[size * 2 / 3];
}

int	*set_int_arr_for_sort(t_pw_list *list, int size)
{
	int		*arr;
	int		i;

	arr = (int*)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	i = 0;
	while (i < size)
	{
		arr[i] = list->value;
		list = list->next;
		i++;
	}
	return (arr);
}

void	push_swap(t_data *data)
{
	if (data->total_size < 4)
	{
		hard_sort_a(data, data->total_size);
		return ;
	}
	a_to_b(data->total_size, data);
}

void	init_data(t_data *data)
{
	data->list_a = NULL;
	data->list_b = NULL;
	data->total_size = count_list_in_arr(data->list_str);
	data->list_a_size = data->total_size;
	data->list_b_size = 0;
	data->pa = 0;
	data->pb = 0;
	data->ra = 0;
	data->rb = 0;
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac < 2)
		return (0);
	av_to_list_str(ac, av, &data);
	init_data(&data);
	list_str_to_list_int(&data);
	make_linked_list(&data);
	quick_sort(data.list_int, 0, data.total_size - 1);
	check_double(data.list_int, data.total_size);
	set_pivot(&data, data.list_a_size);
	free(data.list_int);
	push_swap(&data);
	return (0);
}
