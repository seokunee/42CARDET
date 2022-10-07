/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:06:39 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/06 19:44:13 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	raise_big_and_small_part(t_data *data)
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

static void	b_to_a_part_division(t_data *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (data->list_a->value < data->pivot_small)
		{
			rb(data);
			data->rb++;
		}
		else
		{
			pa(data);
			data->pa++;
			if (data->list_a->value < data->pivot_big)
			{
				ra(data);
				data->ra++;
			}
		}
		i++;
	}
}

static int	check_size_and_hard_sort(t_data *data, int size)
{
	if (size < 6)
	{
		if (size == 1)
			pa(data);
		else if (size == 2)
		{
			if (data->list_b->value < data->list_b->next->value)
				sb(data);
			pa(data);
			pa(data);
		}
		else if (size == 3)
			b_to_a_three_hard_sort(data);
		else if (size == 4 || size == 5)
			b_to_a_four_five_hard_sort(data, size);
		return (1);
	}
	return (0);
}

void	b_to_a(int size, t_data *data)
{
	int	tmp_ra;
	int	tmp_rb;
	int	tmp_pa;

	if (check_size_and_hard_sort(data, size))
		return ;
	data->list_int = set_int_arr_for_sort(data->list_b, size);
	quick_sort(data->list_int, 0, size - 1);
	set_pivot(data, size);
	free(data->list_int);
	b_to_a_part_division(data, size);
	tmp_ra = data->ra;
	tmp_rb = data->rb;
	tmp_pa = data->pa;
	data->ra = 0;
	data->rb = 0;
	data->pa = 0;
	a_to_b(tmp_pa - tmp_ra, data);
	data->ra = tmp_ra;
	data->rb = tmp_rb;
	raise_big_and_small_part(data);
	a_to_b(tmp_ra, data);
	b_to_a(tmp_rb, data);
}
