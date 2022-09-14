/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:24:16 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/13 16:39:25 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_is_num_arr(char *arr)
{
	int	i; 

	i = 0;
	if (arr[i] == '-')
		i = 1;
	while (arr[i])
	{
		if (ft_isdigit(arr[i]) == 0)
			throw_error("Error");
		i++;
	}
	if (i == 1 && arr[i] =='-')
		exit(1);
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
