/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:37:31 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/04 20:40:45 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_number(int n, unsigned int *len)
{
	char	left;

	if (n > 9)
		ft_print_number(n / 10, len);
	left = '0' + n % 10;
	write(1, &left, 1);
	(*len)++;
}

void	ft_putnbr(int n, unsigned int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(1, "-", 1);
			(*len)++;
		}
		ft_print_number(n, len);
	}
}
