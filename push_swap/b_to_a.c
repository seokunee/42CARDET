/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:06:39 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/29 15:49:24 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_to_a_three_hard_sort(t_data *data)
{
	int	one;
	int	two;
	int	three;

	one = data->list_b->value;
	two = data->list_b->next->value;
	three = data->list_b->next->next->value;
	if (one < two && two < three)
	{
		pa(data);
		sb(data);
		pa(data);
		sa(data);
		pa(data);
		sa(data);
	}
	else if (one < two && two > three && one < three)
	{
		rb(data, 1);
		pa(data);
		rb(data, 1);
		pa(data);
		pa(data);
	}
	else if (one > two &&  two < three && one < three)
	{
		pa(data);
		sb(data);
		pa(data);
		sa(data);
		pa(data);
	}
	else if (one < two && one > three && two > three)
	{
		sb(data);
		pa(data);
		pa(data);
		pa(data);
	}
	else if (one > two && one > three && two < three)
	{
		pa(data);
		sb(data);
		pa(data);
		pa(data);
	}
	else if (one > two && two > three)
	{
		pa(data);
		pa(data);
		pa(data);
	}
}

void	b_to_a(int size, t_data *data)
{
	int			i;
	int			tmp_ra;
	int			tmp_rb;
	int			tmp_pa;
	t_pw_list	*list_b;
	
	list_b = data->list_b;
	if (size < 4)
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
		return ;
	}
	data->list_int = set_int_arr_for_sort(data->list_b, size);
	quick_sort(data->list_int, 0, size - 1);
	set_pivot(data, size);
	free(data->list_int);
	i = 0;
	while (i < size)
	{
		if (data->list_a->value < data->pivot_small)
		{
			rb(data, 1);
			data->rb++;
		}
		else
		{
			pa(data);
			data->pa++;
			if (data->list_a->value < data->pivot_big)
			{
				ra(data, 1);
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
		rra(data, 1);
		data->ra--;
	}
	while (data->rb > 0)
	{
		rrb(data, 1);
		data->rb--;
	}
	a_to_b(tmp_ra, data);
	b_to_a(tmp_rb, data);
}