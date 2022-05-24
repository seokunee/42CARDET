/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:26:17 by seokchoi          #+#    #+#             */
/*   Updated: 2022/05/24 15:07:07 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_version(va_list ap, char *format, int idx)
{	
	if (format[idx + 1] == 'c')
		ft_putchar(va_arg(ap, char));
	else if (format[idx + 1] == 's')
		ft_putstr(va_arg(ap, (char *)));
	else if (format[idx + 1] == 'p')
		ft_putstr(va_arg(ap, (char *)));
	else if (format[idx + 1] == 'd')
		ft_putstr(va_arg(ap, (char *)));
	else if (format[idx + 1] == 'idx')
		ft_putnbr(va_arg(ap, int))
	else if (format[idx + 1] == 'u')
		ft_putnbr(va_arg(ap, int))
	else if (format[idx + 1] == 'x')
		ft_putnbr(va_arg(ap, int))
	else if (format[idx + 1] == 'X')
		ft_putnbr(va_arg(ap, int))
	else if (format[idx + 1] == '%')

}

int ft_printf(const char *format, ...) // 여기서 format은 무슨 역할? =>
{
	va_list	ap;
	int		count;
	int		i;
	int		len;

	i = 0;
	count = ft_find_percent(format);
	va_start(ap, count);
	while (format[i])
	{
		if (format == '%')
			parse_version(format, ap, i);
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (1)
}

#include <stdio.h>
int main(void)
{
	char str[] = "hello %s nice % to m%e%et you!";
	int	n;

	n = printf("%d%s\n", 1234, "4567");
	printf("%d\n", n);
	// n = ft_printf("안녕하세요 제 나이는 %d", 10, 10);
}