/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:56:05 by seokchoi          #+#    #+#             */
/*   Updated: 2022/05/30 20:37:54 by seokchoi         ###   ########.fr       */
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

int		ft_strlen(const char *s);
void	ft_putnbr(int n);
void	ft_putchar(unsigned char c);
void	ft_putstr(char *s);
void	ft_putunnbr(unsigned int n);
void	hex_lower_printf(unsigned long address);
void	hex_upper_printf(unsigned long address);

#endif