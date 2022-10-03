/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:09:48 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/03 17:54:45 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_list(t_pw_list **from_list, t_pw_list **to_list)
{
	t_pw_list	*from_list_first;
	t_pw_list	*to_list_first;

	if (*from_list == NULL)
		return ;
	if ((*from_list)->next)
		(*from_list)->next->prev = NULL;
	from_list_first = *from_list;
	to_list_first = *to_list;
	*from_list = (*from_list)->next;
	if (*to_list)
		(*to_list)->prev = from_list_first;
	*to_list = from_list_first;
	from_list_first->next = to_list_first;
}

void	pa(t_data *data)
{
	write(1, "pa\n", 3);
	push_list(&data->list_b, &data->list_a);
	if (data->list_b_size > 0)
	{
		data->list_a_size++;
		data->list_b_size--;
	}
}

void	pb(t_data *data)
{
	write(1, "pb\n", 3);
	push_list(&data->list_a, &data->list_b);
	if (data->list_a_size > 0)
	{
		data->list_b_size++;
		data->list_a_size--;
	}
}
