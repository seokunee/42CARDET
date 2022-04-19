/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:26:17 by seokchoi          #+#    #+#             */
/*   Updated: 2022/04/19 19:10:45 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_percent(const char *format)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count++;
			if (format[i + 1])
				i += 2;
		}
		else
			i++;
	}
	return (count);
}

void	parse_version(va_list ap, char *format)
{
	if (format[i + 1] == 'c')

	else if (format[i + 1] == 's')

	else if (format[i + 1] == 'p')

	else if (format[i + 1] == 'd')

	else if (format[i + 1] == 'i')

	else if (format[i + 1] == 'u')

	else if (format[i + 1] == 'x')

	else if (format[i + 1] == 'X')

	else if (format[i + 1] == '%')

}


int ft_printf(const char *format, ...)
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
		if (format[i] == '%')
		{
			len = parse_version(ap, &format[i]);
			i += len;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
}

#include <stdio.h>
int main(void)
{
	char str[] = "hello %s nice % to m%e%et you!";
	
	printf("%d\n", ft_find_percent(str));
}