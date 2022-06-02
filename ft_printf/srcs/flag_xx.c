/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:31:21 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/03 00:34:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_X_printf(unsigned int address, unsigned int *len)
{
	char	*hex;
	
	hex = "0123456789ABCDEF";
	if (address > 15)
		hex_X_printf(address / 16, len );
	write(1, &hex[address % 16], 1);
	(*len)++;
}