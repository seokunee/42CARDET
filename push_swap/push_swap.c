/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:33:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/25 19:48:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	test_print_second_arr(char **arr);
void 	test_print_int_arr(int *arr,int len);
void	test_linked_list_value(t_pw_list *list, int size);
void	text_printf_list_a_b(t_data *data);
void	printf_sizes(t_data *data);


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

void	a_to_b(int size, t_data *data)
{
	int			i;
	t_pw_list	*list_a;

	if (size == 1)
		return ;
	else if (size == 2)
	{
		two_sort_a(data);
		return ;
	}
	data->list_int = set_int_arr_for_sort(data->list_a, size);
	quick_sort(data->list_int, 0, size - 1);
	set_pivot(data, size);
	free(data->list_int);
	i = 0;
	list_a = data->list_a;
	while (i < size && list_a->next)
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
			if (data->list_a->value >= data->pivot_small)
			{
				rb(data, 1);
				data->rb++;
			}
		}
		list_a = list_a->next;
	}
}

void	push_swap(t_data *data)
{
	if (data->total_size < 4)
		hard_sort_a(data, data->total_size);
	a_to_b(data->total_size, data);
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac < 2)
		return (0);
	av_to_list_str(ac, av, &data);
	data.list_b = NULL;
	data.total_size = count_list_in_arr(data.list_str);
	data.list_a_size = data.total_size;
	data.list_b_size = 0;
	list_str_to_list_int(&data);
	make_linked_list(&data);
	quick_sort(data.list_int, 0, data.total_size - 1);
	check_double(data.list_int, data.total_size);
	set_pivot(&data, data.list_a_size);
	free(data.list_int);
	push_swap(&data);
	text_printf_list_a_b(&data);
	return (0);
}

/*
	코딩 계획
	0. 인자를 리스트로 만들기. -0-
	1. 유효한 인자(리스트)가 들어왔는지 확인. -0-
	2. 인자(string)에서 int로 바꿔주기. -0-
	3. int 배열 리스트에 넣어주기 -0-
	4. push, rotate 함수 완성 -0-
	5. 퀵정렬해서 피봇 찾기 
*/

//------------ For test --------------//
void test_print_second_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void test_print_int_arr(int *arr,int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}

void	test_linked_list_value(t_pw_list *list, int size)
{
	t_pw_list	*tmp;
	int			i;

	i = 0;
	tmp = list;
	if (list == NULL)
		return ;
	while (i < size)
	{
		printf("%d\n",tmp->value);
		tmp = tmp->next;
		i++;
	}
}

void	text_printf_list_a_b(t_data *data)
{
	printf("--------a--------\n");
	test_linked_list_value(data->list_a, data->list_a_size);
	printf("--------a--------\n");
	printf("--------b--------\n");
	test_linked_list_value(data->list_b, data->list_b_size);
	printf("--------b--------\n");
}

void	printf_sizes(t_data *data)
{
	printf("total size = %d\n", data->total_size);
	printf("	a size = %d\n", data->list_a_size);
	printf("	b size = %d\n", data->list_b_size);
}
