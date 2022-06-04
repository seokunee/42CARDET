/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:30:42 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/04 22:04:44 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_x_printf(unsigned int address, unsigned int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (address > 15)
		hex_x_printf(address / 16, len);
	write(1, &hex[address % 16], 1);
	(*len)++;
}
