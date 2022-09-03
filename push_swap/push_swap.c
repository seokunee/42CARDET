/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:33:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/03 20:59:28 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void test_print_second_arr(char **arr);

// void	make_linked_list(int ac, char **av, t_data *data)
// {
// 	int			i;
// 	t_pw_list 	new;
// 	t_pw_list 	*tmp_list;

// 	i = 2;
	
// 	data->list = ft_pw_lstnew(ft_atoi(av[1]));
// 	tmp_list = data->list;
// 	while (2 <= ac)
// 	{
// 		tmp_list->next = ft_pw_lstnew(ft_atoi(av[i]));
// 		i++;
// 	}
// }

t_pw_list	*ft_pw_lstnew(int	value)
{
	t_pw_list	*new;

	new = (t_pw_list *)malloc(sizeof(t_pw_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

int		check_is_num_arr(char **arr)
{
	int	i; 
	int	j;

	i = 0;
	j = 0;
	while(arr[i])
	{
		j = 0;
		if (arr[i][j] == '-')
			j = 1;
		while (arr[i][j])
		{
			if (ft_isdigit(arr[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	av_to_list_str(int ac, char **av, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	data->list_str = malloc(sizeof(char *) * ac);
	while (i < ac)
	{
		data->list_str[j] = ft_strdup(av[i]);
		i++;
		j++;
	}
	data->list_str[j] = NULL;
}

int	secend_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_sec_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_list_in_arr(char **list_str)
{
	int		count;
	int		i;
	char 	**split;
	i = 0;
	count = 0;
	while (list_str[i])
	{
		split = ft_split(list_str[i], ' ');
		count += secend_arr_len(split);
		free_sec_str_arr(split);
		i++;
	}
	return (count);
}

// void	list_str_to_list_int(char **list_str)
// {
	
// }

int	main(int ac, char **av)
{
	t_data data;

	av_to_list_str(ac, av, &data);
	data.list_count = count_list_in_arr(data.list_str);
	
	return (0);
}

/* 코딩 계획
	0. 인자를 리스트로 만들기.
	1. 유효한 인자(리스트)가 들어왔는지 확인.
	2. 인자(string)에서 int로 바꿔주기.
	3. int 배열 리스트에 넣어주기
	4. 
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
