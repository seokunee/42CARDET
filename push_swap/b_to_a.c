/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:06:39 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/30 15:39:38 by seokchoi         ###   ########.fr       */
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

void	b_to_a_four_five_hard_sort(t_data *data, int size)
{
	int			center;
	int			i;

	data->list_int = set_int_arr_for_sort(data->list_b, size);
	quick_sort(data->list_int, 0, size - 1);
	center = data->list_int[size - 3];
	free(data->list_int);
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

void	b_to_a(int size, t_data *data)
{
	int			i;
	int			tmp_ra;
	int			tmp_rb;
	int			tmp_pa;
	t_pw_list	*list_b;
	
	list_b = data->list_b;
	if (size < 6)
	{
		if (size == 1)
			pa(data);
		else if (size == 2)
		{
			if (list_b->value < list_b->next->value)
				sb(data);
			pa(data);
			pa(data);
		}
		else if (size == 3)
			b_to_a_three_hard_sort(data);
		else if (size == 4)
			b_to_a_four_five_hard_sort(data, 4);
		else if (size == 5)
			b_to_a_four_five_hard_sort(data, 5);
		return ;
	}
	data->list_int = set_int_arr_for_sort(data->list_b, size);
	quick_sort(data->list_int, 0, size - 1);
	set_pivot(data, size);
	free(data->list_int);
	i = 0;
	while (i < size)
	{
		if (data->list_a->value <= data->pivot_small)
		{
			rb(data);
			data->rb++;
		}
		else
		{
			pa(data);
			data->pa++;
			if (data->list_a->value <= data->pivot_big)
			{
				ra(data);
				data->ra++;
			}
		}
		i++;
	}
	tmp_ra = data->ra;
	tmp_rb = data->rb;
	tmp_pa = data->pa;
	data->ra = 0;
	data->rb = 0;
	data->pa = 0;
	a_to_b(tmp_pa - tmp_ra, data);
	data->ra = tmp_ra;
	data->rb = tmp_rb;
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
	a_to_b(tmp_ra, data);
	b_to_a(tmp_rb, data);
}