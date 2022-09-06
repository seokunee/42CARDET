/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:08:22 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/06 16:04:59 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_pw_list	*tmp_next;
	t_pw_list	*tmp_next_next;
	t_pw_list	*tmp;

	tmp_next = data->list_a->next;
	tmp = data->list_a;
	if (tmp_next)
	{
		tmp_next_next = data->list_a->next->next;
		data->list_a = tmp_next;
		data->list_a->next = tmp;
		data->list_a->next->next = tmp_next_next;
	}
}

void	sb(t_data *data)
{
	t_pw_list	*tmp_next;
	t_pw_list	*tmp_next_next;
	t_pw_list	*tmp;

	tmp_next = data->list_b->next;
	tmp = data->list_b;
	if (tmp_next)
	{
		tmp_next_next = data->list_b->next->next;
		data->list_b = tmp_next;
		data->list_b->next = tmp;
		data->list_b->next->next = tmp_next_next;
	}
}

void	pa(t_data *data)
{
	t_pw_list	*list_a_first;
	t_pw_list	*list_b_first;
	
	if (data->list_b == NULL)
		return ;
	list_a_first = data->list_a;
	list_b_first = data->list_b;
	data->list_b = data->list_b->next;
	data->list_a = list_b_first;
	list_b_first->next = list_a_first;
}

void	pb(t_data *data)
{
	t_pw_list	*list_a_first;
	t_pw_list	*list_b_first;
	
	if (data->list_a == NULL)
		return ;
	list_a_first = data->list_a;
	list_b_first = data->list_b;
	data->list_a = data->list_a->next;
	data->list_b = list_a_first;
	list_a_first->next = list_b_first;
}

void	ra(t_data *data)
{
	t_pw_list	*list_last;
	t_pw_list	*list_fir;

	list_fir = data->list_a;
	list_last = data->list_a;
	if (list_fir == NULL || list_fir->next == NULL)
		return ;
	while (list_last->next)
		list_last = list_last->next;
	list_last->next = list_fir;
	data->list_a = list_fir->next;
	list_fir->next = NULL;
}

void	rb(t_data *data)
{
	t_pw_list	*list_last;
	t_pw_list	*list_fir;

	list_fir = data->list_b;
	list_last = data->list_b;
	if (list_fir == NULL || list_fir->next == NULL)
		return ;
	while (list_last->next)
		list_last = list_last->next;
	list_last->next = list_fir;
	data->list_b = list_fir->next;
	list_fir->next = NULL;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}

void	rra(t_data *data)
{
	t_pw_list	*list_last;
	t_pw_list	*list_last_pre;
	t_pw_list	*list_fir;

	list_fir = data->list_a;
	list_last = data->list_a;
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
	data->list_a = list_last;
}

void	rrb(t_data *data)
{
	t_pw_list	*list_last;
	t_pw_list	*list_last_pre;
	t_pw_list	*list_fir;

	list_fir = data->list_b;
	list_last = data->list_b;
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
	data->list_b = list_last;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}