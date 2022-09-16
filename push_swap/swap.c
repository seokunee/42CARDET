/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:08:22 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/16 19:05:24 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_pw_list **list, int size)
{
	int	tmp_value;

	if (size < 2)
		return ;
	tmp_value = (*list)->value;
	(*list)->value = (*list)->next->value;
	(*list)->next->value = tmp_value;
}

void	sa(t_data *data)
{
	write(1, "sa\n", 3);
	swap_list(&data->list_a, data->list_a_size);
}

void	sb(t_data *data)
{
	write(1, "sb\n", 3);
	swap_list(&data->list_b, data->list_b_size);
}

void	push_list(t_pw_list **from_list, t_pw_list **to_list)
{
	t_pw_list	*from_list_first;
	t_pw_list	*to_list_first;

	if (*from_list == NULL)
		return ;
	from_list_first = *from_list;
	to_list_first = *to_list;
	*from_list = (*from_list)->next;
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

void	rotate_list(t_pw_list **list)
{
	t_pw_list	*list_last;
	t_pw_list	*list_fir;

	list_fir = (*list);
	list_last = (*list);
	if (list_fir == NULL || list_fir->next == NULL)
		return ;
	while (list_last->next)
		list_last = list_last->next;
	list_last->next = list_fir;
	(*list) = list_fir->next;
	list_fir->next = NULL;
}

void	ra(t_data *data)
{
	write(1, "ra\n", 3);
	rotate_list(&data->list_a);
}

void	rb(t_data *data)
{
	write(1, "rb\n", 3);
	rotate_list(&data->list_b);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}

void	rev_rotate_list(t_pw_list **list)
{
	t_pw_list	*list_last;
	t_pw_list	*list_last_pre;
	t_pw_list	*list_fir;
	list_fir = (*list);
	list_last = (*list);
	list_last_pre = NULL;
	if (list_fir == NULL || list_fir->next == NULL)
		return ;
	while (list_last->next)
	{
		list_last_pre = list_last;
		list_last = list_last->next;
	}
	list_last->next = list_fir;
	list_last_pre->next = NULL;
	(*list) = list_last;
}

void	rra(t_data *data)
{
	write(1, "rra\n", 4);
	rev_rotate_list(&data->list_a);
}

void	rrb(t_data *data)
{
	write(1, "rrb\n", 4);
	rev_rotate_list(&data->list_b);
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}


void	