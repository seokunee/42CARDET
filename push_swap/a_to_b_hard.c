/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_hard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:07:54 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/03 17:54:14 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_two_three(t_data *data)
{
	ra(data);
	sa(data);
	rra(data);
}

void	a_to_b_three_hard_sort(t_data *data)
{
	int	one;
	int	two;
	int	three;

	one = data->list_a->value;
	two = data->list_a->next->value;
	three = data->list_a->next->next->value;
	if (one < two && (one < three || one > three) && two > three)
	{
		swap_two_three(data);
		if (one > three)
			sa(data);
	}
	else if (one > two && one < three && two < three)
		sa(data);
	else if (one > two && one > three && (two < three || two > three))
	{
		sa(data);
		swap_two_three(data);
		if (two > three)
			sa(data);
	}
}

static void	hard_sort_division(t_data *data, int size, int center)
{
	int	i;

	i = 0;
	while (data->ra < size - 3 && i < size)
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
}

void	a_to_b_hard_sort(t_data *data, int size)
{
	int			center;

	data->list_int = set_int_arr_for_sort(data->list_a, size);
	quick_sort(data->list_int, 0, size - 1);
	center = data->list_int[size - 3];
	free(data->list_int);
	if (size == 3)
	{
		a_to_b_three_hard_sort(data);
		return ;
	}
	hard_sort_division(data, size, center);
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
