#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


#include <stdio.h>

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putnum_type(long num, int type, int *len)
{
	char *hex = "0123456789abcdef";
	char *dec = "0123456789";

	if (num < 0)
	{
		num = -num;
		ft_putchar('-', len);
	}
	if (num / type > 0)
	{
		ft_putnum_type(num / type, type, len);
		ft_putnum_type(num % type, type, len);
	}
	else
	{
		if (type == 16)
			ft_putchar(hex[num], len);
		else if (type == 10)
			ft_putchar(dec[num], len);
	}
}

void	ft_putstr(char *str, int *len)
{
	int	i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}

int	check_type(va_list *ap, const char *str, int i, int *len)
{
	char *s;
	char c;
	int	x;
	int d;
	int flag;
	long a;

	flag = 0;
	flag = 1;
	switch(*str) {
    	case 's':    
    	    s = va_arg(*ap, char *);
    	    ft_putstr(s, len);
			flag = 1;
    	    break;
    	case 'd':    
    	    d = va_arg(*ap, int);
			a = d;
    	    ft_putnum_type(a, 10, len);
			flag = 1;
			break;
    	case 'x':      
    	    x = va_arg(*ap, int);
			a = x;
    	    ft_putnum_type(a, 16, len);
			flag = 1;
    	    break;
    }
	return (flag);
}

int ft_printf(const char *str, ... )
{
	int	len = 0;
	int	i = 0;
	va_list ap;

	va_start(ap, str);
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			// printf("holy\n");
			if (check_type(&ap, str, i, &len))
				str++;
		}
		else
		{
			ft_putchar(*str, &len);
			str++;
		}
	}
	va_end(ap);
	return (len);
}

int	main(int ac, char **av)
{
	int	len;

	char *s = NULL;
	len = ft_printf("%s, %d, %x\n", "home", (int)-2147483648, 123);
	printf("len = %d\n", len);
	len = printf("%s, %d, %x\n", "home", (int)-2147483648, 123);
	printf("len = %d\n", len);
	printf("len = %s\n", s);
	ft_printf("len = %s\n", s);
	return (0);
}