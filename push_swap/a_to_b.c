/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:06:15 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/30 18:09:09 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_three_hard_sort(t_data *data)
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
		ra(data);
		sa(data);
		rra(data);
	}
	else if (one > two &&  two < three && one < three)
		sa(data);
	else if (one < two && one > three && two > three)
	{
		ra(data);
		sa(data);
		rra(data);
		sa(data);
	}
	else if (one > two && one > three && two < three)
	{
		sa(data);
		ra(data);
		sa(data);
		rra(data);
	}
	else if (one > two && two > three)
	{
		sa(data);
		ra(data);
		sa(data);
		rra(data);
		sa(data);
	}
}

void	a_to_b_four_five_hard_sort(t_data *data, int size)
{
	int			center;
	int			i;

	data->list_int = set_int_arr_for_sort(data->list_a, size);
	quick_sort(data->list_int, 0, size - 1);
	center = data->list_int[size - 3];
	free(data->list_int);
	i = 0;
	while (data->ra < size - 3  && i < size)
	{
		if (data->list_a->value < center)
		{
			ra(data);
			data->ra++;
		}
		else
		{
			pb(data);
			data->pb++;
		}
		i++;
	}
	while (data->pb > 0)
	{
		pa(data);
		data->pb--;
	}
	a_to_b_three_hard_sort(data);
	while (data->ra > 0)
	{
		rra(data);
		data->ra--;
	}
	if (size == 5 && data->list_a->value > data->list_a->next->value)
		sa(data);
}

void	a_to_b(int size, t_data *data)
{
	int			i;
	int			tmp_ra;
	int			tmp_rb;
	int			tmp_pb;
	t_pw_list	*list_a;

	list_a = data->list_a;
	if (size < 6)
	{
		if (size == 1)
			return ;
		else if (size == 2)
		{
			if (list_a->value > list_a->next->value)
				sa(data);
		}
		else if (size == 3)
			a_to_b_three_hard_sort(data);
		else if (size == 4)
			a_to_b_four_five_hard_sort(data, 4);
		else if (size == 5)
			a_to_b_four_five_hard_sort(data, 5);
		return ;
	}
	data->list_int = set_int_arr_for_sort(data->list_a, size);
	quick_sort(data->list_int, 0, size - 1);
	set_pivot(data, size);
	free(data->list_int);
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
	tmp_ra = data->ra;
	tmp_rb = data->rb;
	tmp_pb = data->pb;
	data->pb = 0;
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
	b_to_a(tmp_pb - tmp_rb, data);
}