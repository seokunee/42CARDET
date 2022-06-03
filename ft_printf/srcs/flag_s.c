/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:45:21 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/04 01:18:58 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, unsigned int *len)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	*len += i;
}