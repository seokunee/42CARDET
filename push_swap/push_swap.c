/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:33:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/26 20:32:57 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int L, int R)
{
	int left = L;
	int	right = R;
	int pivot = arr[(L + R) / 2];
	int tmp;

	while (left<= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left<= right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	};
	if (L < right)
		quick_sort(arr, L, right);
	if (left < R)
		quick_sort(arr, left, R);
}

void	check_double(int *arr, int len)
{
	int	i;

	i = 1;
	if (len < 2)
		return ;
	while (i < len)
	{
		if (arr[i] == arr[i - 1])
			throw_error("Error");	
		i++;
	}
}

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

	printf("three_sort_a");
	one = data->list_a->value;
	two = data->list_a->next->value;
	three = data->list_a->next->next->value;
	if (one > two && two > three)
		return ;
	else if (one < two && two > three && one < three)
	{
		rra(data, 1);
		sa(data);
	}
	else if (one > two &&  two < three && one < three)
		sa(data);
	else if (one < two && one > three && two > three)
		rra(data, 1);
	else if (one > two && one > three && two < three)
		ra(data, 1);
	else if (one > two && two > three)
	{
		sa(data);
		rra(data, 1);
	}
}

/*
	1 2 3
	one < two && two < three
	return ;

	1 3 2
	one < two && two > three && one < three
	rra sa
	
	2 1 3
	one > two &&  two < three && one < three
	sa

	2 3 1
	one < two && one > three && two > three
	rra

	3 1 2
	one > two && one > three && two < three
	ra

	3 2 1
	one > two && two > three
	sa rra
*/

void	hard_sort_a(t_data *data, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		two_sort_a(data);
	else if (size == 3)
		three_sort_a(data);
}

void	b_to_a(int size, t_data *data)
{
	int			i;
	int			tmp_ra;
	int			tmp_rb;
	int			tmp_pa;
	t_pw_list	*list_b;
	
	list_b = data->list_b;
	if (size < 3)
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

void	a_to_b(int size, t_data *data)
{
	int			i;
	int			tmp_ra;
	int			tmp_rb;
	int			tmp_pb;
	t_pw_list	*list_a;

	list_a = data->list_a;
	if (size < 3)
	{
		if (size == 1)
			return ;
		else if (list_a->value > list_a->next->value)
			sa(data);
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
			ra(data, 1);
			data->ra++;
		}
		else
		{
			pb(data);
			data->pb++;
			if (data->list_b->value >= data->pivot_small)
			{
				rb(data, 1);
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
	b_to_a(tmp_pb - tmp_rb, data);
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
