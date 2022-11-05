/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:14:50 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/05 18:46:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_error	check_args(t_set_up *set_up, int ac)
{
	if (set_up->num_philos == -1)
		return (ARGS_ERR);
	if (set_up->time_to_die == -1)
		return (ARGS_ERR);
	if (set_up->time_to_eat == -1)
		return (ARGS_ERR);
	if (set_up->time_to_sleep == -1)
		return (ARGS_ERR);
	if (ac == 6 && set_up->num_must_eat == -1)
		return (ARGS_ERR);
	return (NO_ERR);
}

t_error	set_up_init(t_set_up *set_up, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (throw_error(ARGS_ERR));
	set_up->num_philos = ft_atoi((const char *)av[1]);
	set_up->time_to_die = ft_atoi((const char *)av[2]);
	set_up->time_to_eat = ft_atoi((const char *)av[3]);
	set_up->time_to_sleep = ft_atoi((const char *)av[4]);
	set_up->num_must_eat = NO_NUM_EAT;
	if (ac == 6)
		set_up->num_must_eat = ft_atoi((const char *)av[5]);
	if (check_args(set_up, ac))
		return (ARGS_ERR);
	set_up->start_time = get_now_time_ms();
	return (0);
}
