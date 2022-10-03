/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:06:15 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/03 17:46:47 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	raise_big_and_mib_part(t_data *data)
{
	while (data->ra > 0 && data->rb > 0)
	{
		rrr(data);
		data->ra--;
		data->rb--;
	}
	while (data->ra > 0)
	{
		rra(data);
		data->ra--;
	}
	while (data->rb > 0)
	{
		rrb(data);
		data->rb--;
	}
}

static int	check_size_and_hard_sort(t_data *data, int size)
{
	if (size < 6)
	{
		if (size == 1)
			return (1);
		else if (size == 2)
		{
			if (data->list_a->value > data->list_a->next->value)
				sa(data);
		}
		else
			a_to_b_hard_sort(data, size);
		return (1);
	}
	return (0);
}

static void	a_to_b_part_division(t_data *data, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		if (data->list_a->value >= data->pivot_big)
		{
			ra(data);
			data->ra++;
		}
		else
		{
			pb(data);
			data->pb++;
			if (data->list_b->value >= data->pivot_small)
			{
				rb(data);
				data->rb++;
			}
		}
		i++;
	}
}

void	a_to_b(int size, t_data *data)
{
	int			tmp_ra;
	int			tmp_rb;
	int			tmp_pb;

	if (check_size_and_hard_sort(data, size))
		return ;
	data->list_int = set_int_arr_for_sort(data->list_a, size);
	quick_sort(data->list_int, 0, size - 1);
	set_pivot(data, size);
	free(data->list_int);
	a_to_b_part_division(data, size);
	tmp_ra = data->ra;
	tmp_rb = data->rb;
	tmp_pb = data->pb;
	data->pb = 0;
	raise_big_and_mib_part(data);
	a_to_b(tmp_ra, data);
	b_to_a(tmp_rb, data);
	b_to_a(tmp_pb - tmp_rb, data);
}
