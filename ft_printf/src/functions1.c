/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:10:13 by seokchoi          #+#    #+#             */
/*   Updated: 2022/05/30 20:28:16 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_lower_printf(unsigned long address)
{
	char	*hex;
	
	hex = "0123456789abcdef";
	if (address > 15)
		hex_printf(address / 16);
	write(1, &hex[address % 16], 1);
}

void	hex_upper_printf(unsigned long address)
{
	char	*hex;
	
	hex = "0123456789ABCDEF";
	if (address > 15)
		hex_printf(address / 16);
	write(1, &hex[address % 16], 1);
}

void	ft_putunnbr(unsigned int n)
{
	char	left;

	if (n > 9)
		ft_print_number(n / 10);
	left = '0' + n % 10;
	write(1, &left, 1);
}

// #include <stdio.h>

// int main(void)
// {
// 	char * str = "1234";
// 	printf("%p\n", str);
// 	hex_printf((unsigned long)str);
// 	write(1, "\n", 1);
// 	return (0);
// }