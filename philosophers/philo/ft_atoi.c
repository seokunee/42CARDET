/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:36:52 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/31 01:17:17 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg_condition(const char *arg)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign *= -1;
		i++;
	}
	if (sign == -1)
		return (throw_error(ARGS_ERR));
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (throw_error(ARGS_ERR));
		i++;
	}
	return (NO_ERR);
}

int	ft_atoi(const char *nptr)
{
	long	result;
	long	n;
	int		i;

	n = 1;
	i = 0;
	result = 0;
	if (check_arg_condition(nptr))
		return (check_arg_condition(nptr));
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		if (result < 0)
			return ((n + 1) / -2);
		i++;
	}
	return (result * n);
}
