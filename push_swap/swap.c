/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:08:22 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/05 20:48:54 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_pw_list *tmp_next;
	t_pw_list *tmp_next_next
	t_pw_list *tmp;

	tmp_next = data->list->next;
	tmp = data->list;
	if (tmp_next)
	{
		tmp_next_next = data->list->next->next;
		data->list = tmp_next;
		data->list->next = tmp;
		data->list->next->next = tmp_next_next;
	}
}

void	sb()
{
	
}

void	pa()
{
	
}

void	pb()
{
	
}
void	ra()
{

}

void	rb()
{
	
}

void	rr()
{
	
}

void	rra()
{
	
}

void	rrb()
{
	
}

void	rrr()
{
	
}