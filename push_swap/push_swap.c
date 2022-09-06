/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:33:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/06 18:50:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	test_print_second_arr(char **arr);
void 	test_print_int_arr(int *arr,int len);
void	test_linked_list_value(t_pw_list *list);
void	text_printf_list_a_b(t_data *data);

void quickSort(t_data *data, int L, int R)
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
		quickSort(data, L, right);
	if (left < R)
		quickSort(data, left, R);
}

void	check_double(int *arr, int len)
{
	int	i;

	i = 1;
	while (arr[i] && i < len)
	{
		if (arr[i] == arr[i - 1])
			throw_error("Error");	
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac < 2)
		return (0);
	av_to_list_str(ac, av, &data);
	data.list_b = NULL;
	data.list_count = count_list_in_arr(data.list_str);
	list_str_to_list_int(&data);
	make_linked_list(&data);
	quickSort(&data, 0, data.list_count - 1);
	check_double(data.list_int, data.list_count);
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

void	test_linked_list_value(t_pw_list *list)
{
	t_pw_list *tmp;

	tmp = list;
	if (list == NULL)
		return ;
	while (tmp->next)
	{
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}
	printf("%d\n",tmp->value);
}

void	text_printf_list_a_b(t_data *data)
{
	printf("--------a--------\n");
	test_linked_list_value(data->list_a);
	printf("--------a--------\n");
	printf("--------b--------\n");
	test_linked_list_value(data->list_b);
	printf("--------b--------\n");
}
