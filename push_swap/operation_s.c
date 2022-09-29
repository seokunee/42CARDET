/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:08:22 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/29 16:10:58 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_pw_list **list)
{
	int	tmp_value;

	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	tmp_value = (*list)->value;
	(*list)->value = (*list)->next->value;
	(*list)->next->value = tmp_value;
}

void	sa(t_data *data)
{
	write(1, "sa\n", 3);
	swap_list(&data->list_a);
}

void	sb(t_data *data)
{
	write(1, "sb\n", 3);
	swap_list(&data->list_b);
}
