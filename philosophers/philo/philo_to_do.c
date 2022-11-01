/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_to_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:30:14 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/01 20:26:23 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	count_eat(t_philo *philo)
{
	philo->num_eat++;
	if (philo->num_eat == philo->data->set_up.num_must_eat)
	{
		philo->data->done_check_box[philo->id - 1] = 1;
		return (1);
	}
	return (0);
}

void	*philo_to_do(void *philo)
{
	t_philo			*info;

	info = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(info->l_fork);
		take_fork(philo);
		pthread_mutex_lock(info->r_fork);
		take_fork(philo);
		eating(philo);
		pthread_mutex_unlock(info->l_fork);
		pthread_mutex_unlock(info->r_fork);
		if (count_eat(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
