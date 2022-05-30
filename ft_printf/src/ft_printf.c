/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:26:17 by seokchoi          #+#    #+#             */
/*   Updated: 2022/05/30 20:29:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_version(va_list ap, char *format, int *idx)
{	
	if (format[*idx + 1] == 'c')
		ft_putchar(va_arg(ap, int));
	else if (format[*idx + 1] == 's')
		ft_putstr(va_arg(ap, unsigned long));
	else if (format[*idx + 1] == 'p')
		hex_lower_printf(va_arg(ap, unsigned long));
	else if (format[*idx + 1] == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (format[*idx + 1] == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (format[*idx + 1] == 'u')
		ft_putunnbr(va_arg(ap, unsigned int));
	else if (format[*idx + 1] == 'x')
		(va_arg(ap, unsigned int));
	else if (format[*idx + 1] == 'X')
		(va_arg(ap, unsigned int));
	else if (format[*idx + 1] == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format == '%')
			parse_version(format, ap, &i);
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (1);
}

#include <stdio.h>
int main(void)
{
	char str[] = "hello %s nice to meet you! i am %d years old!";
	int	n;

	n = printf("%d%s\n", "seokchoi", 26);
	printf("%d\n", n);
	// n = ft_printf("안녕하세요 제 나이는 %d", 10, 10);
	return (0);
}