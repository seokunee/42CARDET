/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:10:13 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/03 00:34:23 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunnbr(unsigned int n, unsigned int *len)
{
	char	left;

	if (n > 9)
		ft_putunnbr(n / 10, len);
	left = '0' + n % 10;
	write(1, &left, 1);
	(*len)++;
}
