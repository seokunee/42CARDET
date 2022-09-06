/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:21:03 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/05 15:21:36 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_str_to_list_int(t_data *data)
{
	int		i;
	int		j;
	int		k;
	char	**splited;

	i = 0;
	k = 0;
	data->list_int = (int *)malloc(sizeof(int) * data->list_count);
	while (data->list_str[i])
	{
		splited = ft_split(data->list_str[i], ' ');
		j = 0;
		while (splited[j])
		{
			check_is_num_arr(splited[j]);
			data->list_int[k] = ft_atoi(splited[j]);
			j++;
			k++;
		}
		free_sec_str_arr(splited);
		i++;
	}
}

t_pw_list	*ft_pw_lstnew(int value)
{
	t_pw_list	*new;

	new = (t_pw_list *)malloc(sizeof(t_pw_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	make_linked_list(t_data *data)
{
	int			i;
	t_pw_list 	*tmp_list;

	i = 0;
	data->list = ft_pw_lstnew(data->list_int[i++]);
	tmp_list = data->list;
	while (i < data->list_count)
	{
		tmp_list->next = ft_pw_lstnew(data->list_int[i]);
		tmp_list = tmp_list->next;
		i++;
	}
}
