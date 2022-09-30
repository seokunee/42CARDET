/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:37:22 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/30 21:49:03 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort_a(t_data *data)
{
	t_pw_list	*list_a;
	
	list_a = data->list_a;
	if (list_a->value > list_a->next->value)
		sa(data);
}

void	three_sort_a(t_data *data)
{
	int	one;
	int	two;
	int	three;

	one = data->list_a->value;
	two = data->list_a->next->value;
	three = data->list_a->next->next->value;
	if (one < two && two < three)
		return ;
	else if (one < two && two > three && one < three)
	{
		rra(data);
		sa(data);
	}
	else if (one > two &&  two < three && one < three)
		sa(data);
	else if (one < two && one > three && two > three)
		rra(data);
	else if (one > two && one > three && two < three)
		ra(data);
	else if (one > two && two > three)
	{
		sa(data);
		rra(data);
	}
}

void	four_sort_a(t_data *data, int size)
{
	int	first;
	t_pw_list *last;

	data->list_int = set_int_arr_for_sort(data->list_a, size);
	quick_sort(data->list_int, 0, size - 1);
	if ()
	{
		
	}
	free(data->list_int);
}

void	hard_sort_a(t_data *data, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		two_sort_a(data);
	else if (size == 3)
		three_sort_a(data);
}