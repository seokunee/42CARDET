/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_hard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:55:50 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/02 16:40:03 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a_three_hard_sort(t_data *data)
{
	int	i;

	i = -1;
	data->list_int = set_int_arr_for_sort(data->list_b, 3);
	quick_sort(data->list_int, 0, 2);
	while (++i < 3 && data->list_b->value != data->list_int[2])
	{
		rb(data);
		data->rb++;
	}
	free(data->list_int);
	pa(data);
	while (data->rb > 0)
	{
		rrb(data);
		data->rb--;
	}
	if (data->list_b->value < data->list_b->next->value)
		sb(data);
	pa(data);
	pa(data);
}

static void	hard_sort_division(t_data *data, int size, int center)
{
	int			i;

	i = 0;
	while (i < size)
	{
		if (data->list_b->value < center)
		{
			rb(data);
			data->rb++;
		}
		else
			pa(data);
		i++;
	}
}

void	b_to_a_four_five_hard_sort(t_data *data, int size)
{
	int			center;

	data->list_int = set_int_arr_for_sort(data->list_b, size);
	quick_sort(data->list_int, 0, size - 1);
	center = data->list_int[size - 3];
	free(data->list_int);
	hard_sort_division(data, size, center);
	a_to_b_three_hard_sort(data);
	while (data->rb > 0)
	{
		rrb(data);
		data->rb--;
	}
	if (size == 5 && data->list_a->value < data->list_a->next->value)
	{
		sb(data);
		pa(data);
	}
	pa(data);
}
