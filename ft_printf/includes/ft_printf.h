/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:56:05 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/02 15:46:19 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define ERR -1
# define TRUE 1
# define FALSE 0

void	ft_putchar(unsigned char c, unsigned int *len);
void	ft_putnbr(int n);
void	ft_putstr(char *s, unsigned int *len);
void	ft_putunnbr(unsigned int n, unsigned int *len);
void	hex_address_printf(unsigned long address, unsigned int *len);
void	hex_X_printf(unsigned int address, unsigned int *len);
void	hex_x_printf(unsigned int address, unsigned int *len);

#endif