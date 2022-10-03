/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:09:45 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/02 16:40:49 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_pw_list **list)
{
	t_pw_list	*list_last;
	t_pw_list	*list_fir;

	list_fir = (*list);
	list_last = (*list);
	if (list_fir == NULL || list_fir->next == NULL)
		return ;
	list_fir->next->prev = NULL;
	while (list_last->next)
		list_last = list_last->next;
	list_fir->prev = list_last;
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
	write(1, "rr\n", 3);
	rotate_list(&data->list_a);
	rotate_list(&data->list_b);
}
