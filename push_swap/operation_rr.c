/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:09:43 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/29 16:10:54 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	list_last->prev = NULL;
	list_last_pre->next = NULL;
	(*list) = list_last;
}

void	rra(t_data *data, int printable)
{
	if (printable)
		write(1, "rra\n", 4);
	rev_rotate_list(&data->list_a);
}

void	rrb(t_data *data, int printable)
{
	if (printable)
		write(1, "rrb\n", 4);
	rev_rotate_list(&data->list_b);
}

void	rrr(t_data *data)
{
	write(1, "rrr\n", 4);
	rev_rotate_list(&data->list_a);
	rev_rotate_list(&data->list_b);
}
