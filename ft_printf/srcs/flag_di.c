/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:37:31 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/02 15:46:16 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_number(int n)
{
	char	left;

	if (n > 9)
		ft_print_number(n / 10);
	left = '0' + n % 10;
	write(1, &left, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(1, "-", 1);
		}
		ft_print_number(n);
	}
}

void	ft_putchar(unsigned char c, unsigned int *len)
{
	write(1, &c, 1);
	(*len)++;
}
