/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:31:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/04 22:04:34 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_address_printf(unsigned long address, unsigned int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (address > 15)
		hex_address_printf(address / 16, len);
	write(1, &hex[address % 16], 1);
	(*len)++;
}

void	ft_putaddress(unsigned long address, unsigned int *len)
{
	write(1, "0x", 2);
	hex_address_printf(address, len);
}
