/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:33:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/16 18:54:16 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	test_print_second_arr(char **arr);
void 	test_print_int_arr(int *arr,int len);
void	test_linked_list_value(t_pw_list *list, int size);
void	text_printf_list_a_b(t_data *data);
void	printf_sizes(t_data *data);


void	quick_sort(t_data *data, int L, int R)
{
	int left = L;
	int	right = R;
	int pivot = data->list_int[(L + R) / 2];
	int temp;

	while (left<= right)
	{
		while (data->list_int[left] < pivot)
			left++;
		while (data->list_int[right] > pivot)
			right--;
		if (left<= right)
		{
			temp = data->list_int[left];
			data->list_int[left] = data->list_int[right];
			data->list_int[right] = temp;
			left++;
			right--;
		}
	};
	if (L < right)
		quick_sort(data, L, right);
	if (left < R)
		quick_sort(data, left, R);
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

void	set_pivot(t_data *data)
{
	data->pivot_f = data->list_int[data->total_size / 3];
	data->pivot_s = data->list_int[data->total_size * 2 / 3];
}

// void	push_swap(t_data *data)
// {
	
// }

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
	quick_sort(&data, 0, data.total_size - 1);
	check_double(data.list_int, data.total_size);
	set_pivot(&data);

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
