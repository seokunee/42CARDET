/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:26:17 by seokchoi          #+#    #+#             */
/*   Updated: 2022/06/04 22:04:09 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_version(va_list *ap, const char *format, \
int *idx, unsigned int *len)
{
	if (format[*idx] == 'c')
		ft_putchar(va_arg(*ap, int), len);
	else if (format[*idx] == 's')
		ft_putstr((char *)va_arg(*ap, unsigned long), len);
	else if (format[*idx] == 'p')
	{
		ft_putaddress(va_arg(*ap, unsigned long), len);
		(*len) += 2;
	}
	else if (format[*idx] == 'd' || format[*idx] == 'i')
		ft_putnbr(va_arg(*ap, int), len);
	else if (format[*idx] == 'u')
		ft_putunnbr(va_arg(*ap, unsigned int), len);
	else if (format[*idx] == 'x')
		hex_x_printf(va_arg(*ap, unsigned int), len);
	else if (format[*idx] == 'X')
		hex_xx_printf(va_arg(*ap, unsigned int), len);
	else if (format[*idx] == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]) != 0)
		{
			i++;
			parse_version(&ap, format, &i, &len);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
