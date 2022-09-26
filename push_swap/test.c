/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:27:28 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/26 20:28:21 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	test_printf_list_a_b(t_data *data)
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
