/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:31:41 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/03 00:34:18 by seokchoi         ###   ########.fr       */
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