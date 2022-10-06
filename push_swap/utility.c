/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:19:51 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/06 17:59:53 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	throw_error(char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		write(2, &message[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

static void	check_minus(const char *nptr, int *i, long *n)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			(*n) *= -1;
		(*i)++;
	}
}

int	ft_pw_atoi(const char *nptr)
{
	long	result;
	long	n;
	int		i;

	n = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	check_minus(nptr, &i, &n);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		if (result < 0)
			return ((n + 1) / -2);
		i++;
	}
	if (result * n < -2147483648 || result * n > 2147483647)
		throw_error("Error");
	return (result * n);
}
